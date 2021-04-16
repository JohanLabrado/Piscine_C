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


char * ft_strcapitalize(char *str)
{
	int i;

	if (str == NULL)
		return NULL;

	if (str[0] >= 97 && str[0] <= 122)
		str[0] -= 32;


	i = 0;
	while(str[++i] != '\0')
	{
		if (str[i] == ' ' || str[i] == '+' || str[i] == '-')
		{
			i++;
			if (str[i] >= 97 && str[i] <= 122) 
				str[i] -= 32;
		}		
	}
	return str;
}


int main(void)
{
	char str[] = "salut, comment tu vas ? 42mots quarante-deux; cinquante+et+un";
	ft_putstr(ft_strcapitalize(str));
	ft_putchar('\n');
	return 0;
}


