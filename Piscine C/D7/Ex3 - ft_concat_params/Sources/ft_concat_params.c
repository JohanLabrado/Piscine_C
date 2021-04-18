#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int number)
{
	if (number == INT_MIN)
	{
		ft_putchar('-');
		ft_putchar('2');
		ft_putnbr((INT_MIN + 2000000000) * (-1));
		return ;
	}
	else if (number & 0x80000000)
	{	
		ft_putchar('-');
		number *= -1;
	}
	if (number > 9)
	{
		ft_putnbr(number/10);
		ft_putchar(number%10 + '0');
	}
	else
		ft_putchar(number + '0');
}

int ft_strlen(char *str)
{
	if (str == NULL)
		return 0;

	int result;
	
	result = 0;
	while (*str++ != '\0')
	{
		result++;
	}

	return result;
}

void ft_putstr(char *str)
{
	if (str == NULL)
		return ;

	write (1, str, ft_strlen(str));
}

char * ft_strcat(char *dest, char *str)
{
	int i;
	int len;

	if (str == NULL || dest == NULL)
		return NULL;

	len = ft_strlen(dest);

	i = 0 ;
	while(i < ft_strlen(str))
	{
		dest[len + i] = str[i];
		i++;
	}
		
	dest[len + i] = '\0';

	return dest;
}

char *ft_concat_params(int argc, char **argv)
{
	if (argc <= 1)
		return NULL;

	int i;
	i = -1;
	int len = 0;

	
	while(++i < argc)
	{
		len += ft_strlen(argv[i + 1]);
	}

	char *str = (char *)malloc(sizeof(char) * (len + argc));

	i = -1;
	while(++i < argc - 1)
	{
		str = ft_strcat(str, argv[i + 1]);
		str = ft_strcat(str, "\n");
	}

	str[len + argc] = '\0';

	return str;
}




int main(int argc, char **argv)
{
	 
	ft_putstr(ft_concat_params(argc, argv));
	return 0;
}


