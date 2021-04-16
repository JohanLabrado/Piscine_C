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

void ft_strcpy(char *dest, char *src)
{
	if (src == NULL)
		return;

	int len = ft_strlen(src);

	int i = -1;
	while(++i <= len)
		dest[i] = src[i]; 
			
}

int ft_strcmp(char str1, char str2)
{
	if (str1 == str2)
		return 1;

	else
		return 0;

}


char *ft_strstr(char *str, char *toFind)
{
	if (str == NULL)
		return NULL;

	//char *strCpy = (char *)malloc(ft_strlen(str));
	unsigned int lenToFind = ft_strlen(toFind);

	while (++str)
	{
		if (*str == toFind[0])
		{	
			unsigned int j = -1;
			int end = 0;
			while (++j < lenToFind)
			{
				if (ft_strcmp(*(str + j), toFind[j]) == 0)
					end = 1;			
			}	
			if (end == 0)	
				return (str);
		}
	}

	return NULL;
		
}


int main(void)
{
	char str[] = "ceci est une string de test par usine de test groupe sans groupe pour tester";
	//char *strcopy = (char *)malloc(ft_strlen(str) + 1);
	char *newStr = ft_strstr(str, "test");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr(newStr);
	ft_putchar('\n');
	return 0;
}


