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

int ft_strncmp(char *str1, char *str2, unsigned int n)
{
	int val1;
	int val2;
	char * strCopy1 = (char *)malloc(n);
	char * strCopy2 = (char *)malloc(n);

	val1 = 0;
	val2 = 0;
	ft_strncpy(strCopy1, str1, n);
	ft_strncpy(strCopy2, str2, n);


	val1 = ft_atoi((strCopy1));
	val2 = ft_atoi((strCopy2));
	printf("val 1 : %d\n", val1);
	printf("val 2 : %d\n", val2);
		
	free(strCopy2);
	free(strCopy1);

	if (val1 == val2)
		return 0;
	else if (val1 > val2)
		return 1;
	else
		return -1;
}


int main(void)
{
	char str1[] = "AB";
	char str2[] = "ABD";
	ft_putnbr(ft_strncmp(str1, str2, 2));
	ft_putchar('\n');
	return 0;
}


