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

int ft_isPrime(int n)
{
	if (n == 0 || n == 1)
		return 0;
		
	int i;

	i = 2;
	while (i < n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}

	return 1;
}

int main(void)
{
	int a = 23;
	ft_putnbr(ft_isPrime(a));
	return 0;
}


