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

void ft_swap(int *a, int *b)
{
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}

void ft_sort_integer_table(int *tab, int size)
{
	int i;

	i = 1;
	while ( i <= size)
	{
		if (tab[i] < tab[i-1])
		{
			ft_swap(&(tab[i]), &(tab[i-1]));
			i = 1;
		}	
		else
			i++;
	}
}



int main(int argc, char* argv[])
{
	int tab[10] = {15, 5, 6, 1, 4, 8, 9, 62, -8, 2};
	ft_sort_integer_table(tab, 10);

	int i = -1;
	while (++i < 10)
	{
		ft_putnbr(tab[i]);
		ft_putchar('\n');
	}
	
	return 0;
}


