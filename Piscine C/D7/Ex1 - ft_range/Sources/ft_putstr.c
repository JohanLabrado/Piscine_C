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


int *ft_range(int min, int max)
{
	if (min >= max)
		return NULL;

	
	int tabSize;
	int i;

	tabSize = max - min;
	i = -1;

	int *tab = (int *)malloc(sizeof(int) * tabSize);

	while (++i < tabSize)
		tab[i] = min++;

	return tab;

}

int main(void)
{
	int *tab2 = ft_range(0, 10);
	for (int i = 0; i < 10; i++)
	{
		ft_putnbr(tab2[i]);
		ft_putchar('\n');
	}
	free (tab2);
	return 0;
}


