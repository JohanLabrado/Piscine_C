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


int ft_str_is_printable(char *str)
{
	int i;

	if (str == NULL)
		return 1;

	i = -1;
	while(str[++i] != '\0')
	{
		if (!((str[i] >= 0 && 126 >= str[i])))
			return 0;
	}
	return 1;
}


int main(void)
{
	char str[] = "ZDSGdFSG";
	ft_putnbr(ft_str_is_printable(str));
	ft_putchar('\n');
	return 0;
}


