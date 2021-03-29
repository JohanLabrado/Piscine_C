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

void ft_putstr(char *str)
{
	if (str == NULL)
		return ;

	int i;

	i = 0;
	while (*str != '\0')
	{
		ft_putchar(*str++);
	}
}

int ft_strlen(char *str)
{
	if (str == NULL)
		return 0;

	int result;
	
	result = 0;
	while (*str != '\0')
	{
		result++;
	}

	return result;
}

int main(int argc, char* argv[])
{
	char *str = "testfdd";
	int size = ft_strlen(str);
	ft_putnbr(size);
	ft_putstr(str);
	return 0;
}


