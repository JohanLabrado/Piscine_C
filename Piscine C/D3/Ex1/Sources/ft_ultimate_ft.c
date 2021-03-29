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

void ft_ultimate_ft(int ***nbr)
{
	int i = 0;
	void *current = nbr;
	
	while (i < 2)
	{
		void *tmp = current;
		current = *((void **)(tmp));	
		i++;
	}

	int *value = (int *)current;
	//ft_putnbr(*value);
	ft_putchar('\n');
	
	*value = 42;
	//ft_putnbr(*value);
}

int main(int argc, char* argv[])
{
	int a = 78;
	//ft_putnbr(a);
	int *b = &a;
	int **c = &b;
	int ***d = &c;
	ft_ultimate_ft(d);
	ft_putnbr(a);
	return 0;
}


