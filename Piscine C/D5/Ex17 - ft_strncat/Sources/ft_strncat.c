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


char * ft_strncat(char *dest, char *str, unsigned int nb)
{
	unsigned int i;
	int len;

	if (str == NULL || dest == NULL)
		return NULL;

	len = ft_strlen(dest);

	i = 0 ;
	while(i < nb)
	{
		dest[len + i] = str[i];
		i++;
	}
		
	dest[len + i] = '\0';

	return dest;
}


int main(void)
{
	char str[] = "sauce";
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	ft_putstr(ft_strncat(str, " aigre douce", 2));
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	return 0;
}


