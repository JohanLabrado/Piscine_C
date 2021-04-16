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

void ft_strncpy(char *dest, char *src, unsigned int n)
{
	if (src == NULL)
		return;

	unsigned int len = ft_strlen(src);

	if (n > len)
		n = len;

	unsigned int i = -1;
	while(++i < n)
		dest[i] = src[i]; 

	dest[i] = '\0';			
}


int main(void)
{
	char str[] = "ceci est une string de test par usine de test groupe sans groupe pour tester";
	char *strcopy = (char *)malloc(ft_strlen(str) + 1);
	ft_strncpy(strcopy, str, 42);
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr(strcopy);
	free(strcopy);
	ft_putchar('\n');
	return 0;
}


