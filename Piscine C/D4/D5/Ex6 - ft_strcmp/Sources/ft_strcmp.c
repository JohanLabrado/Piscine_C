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

int ft_atoi(char *str)
{
	if (str == NULL)
		return 0;

	int result;
	int size;
	int i;

	i = 0;
	result = 0;
	size = ft_strlen(str);
	
	
	while (i < size)
	{
		result = result * 10  + (str[i] - '0');
		i++;
	}

	return result;
}

int ft_strcmp(char *str1, char *str2)
{
	int len1;
	int len2;
	int i;
	int val1;
	int val2;

	len1 = ft_strlen(str1);
	len2 = ft_strlen(str2);
	i = -1;
	val1 = val2 = 0;

	while (++i < len1)
		val1 += ft_atoi(&(str1[i]));
	i = -1;
	while (++i < len2)
		val2 += ft_atoi(&(str2[i]));

	if (val1 == val2)
		return 0;
	else if (val1 > val2)
		return 1;
	else
		return -1;
}


int main(void)
{
	char str1[] = "ABE";
	char str2[] = "ABD";
	ft_putnbr(ft_strcmp(str1, str2));
	ft_putchar('\n');
	return 0;
}


