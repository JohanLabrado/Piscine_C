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



int	check_base(char *base)
{
	int	i;
	int	z;

	i = 0;
	z = 0;
	if (base == NULL || !base[1])
		return 0;

	while (base[i] != '\0')
	{
		z = i + 1;
		if (!((base[i] >= '0' && base[i] <= '9') || (base[i] >= 'a' \
				&& base[i] <= 'z') || (base[i] >= 'A' && base[i] <= 'Z')))
			return 0;
		while (base[z])
			if (base[i] == base[z++])
				return 0;
		i += 1;
	}
	return 1;
}

int ft_atoi_base(char *str, char *base);
{
	
	int len;

	if (!check_base(base))
		return 0;

	if (nbr < len)
		ft_putchar(base[nbr % len]);
	else
	{
		ft_putnbr_base(nbr / len, base);
		ft_putchar(base[nbr % len]);
	}
	
}


int main(void)
{
		
	ft_putchar('\n');
	ft_putnbr_base(1000, "123456");
	ft_putchar('\n');

	return 0;
}


