#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

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

// "gateau"  "fraise"  "3"
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int i;
	unsigned int len;

	if (dest == NULL || src == NULL || size == 0)
		return 0;

	i = 0;
	len = 0;
	while (dest[len] && len < size)
		len++;

	i = len; //i = 6
	while ( (src[len - i] && (len + 1) < size))
	{
		dest[len] = src[len - i];
		len++;
	}

	if (i < size)
		dest[len] = '\0';
	return (i + ft_strlen(src));
}


int main(void)
{
	char str[] = "azerty";
	//char str2[] = "adse";
	ft_putchar('\n');
	ft_putnbr(ft_strlcat(str, " qwoik", 3));
	ft_putchar('\n');
	ft_putstr(str);
	ft_putchar('\n');
	ft_putnbr(ft_strlen(str));
	ft_putchar('\n');
	return 0;
}


