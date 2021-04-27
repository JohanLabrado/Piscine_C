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

char * ft_strcat(char *dest, char *str)
{
	int i;
	int len;

	if (str == NULL || dest == NULL)
		return NULL;

	len = ft_strlen(dest);

	i = 0 ;
	while(i < ft_strlen(str))
	{
		dest[len + i] = str[i];
		i++;
	}
		
	dest[len + i] = '\0';

	return dest;
}

char *ft_concat_params(int argc, char **argv)
{
	if (argc <= 1)
		return NULL;

	int i;
	i = -1;
	int len = 0;

	
	while(++i < argc)
	{
		len += ft_strlen(argv[i + 1]);
	}

	char *str = (char *)malloc(sizeof(char) * (len + argc));

	i = -1;
	while(++i < argc - 1)
	{
		str = ft_strcat(str, argv[i + 1]);
		str = ft_strcat(str, "\n");
	}

	str[len + argc] = '\0';

	return str;
}

char	*ft_strdup(char *src)
{
	char	*dst;
	int		i;

	i = 0;
	while (src[i])
		i += 1;
	if (!(dst = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}



unsigned int ft_wordCount(char *str)
{

	unsigned int len;
	unsigned int i;
	unsigned int nbWord;

	len = ft_strlen(str);
	i = -1;
	nbWord = 1;
	while (++i < len)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\t')
			nbWord++;
	}

	return nbWord;

}

unsigned int ft_wordSize(char *str)
{
	//ft_putchar('\n');
	//ft_putstr(str);
	unsigned int i = -1;
	unsigned int len = ft_strlen(str);
	while (++i < len)
	{
		if (str[i] == ' ' || str[i] == '\n' || str[i] == '\0')
			return i;
		if (str[i] == '\t')
			return i + 3;
	}

	return i;
}

//Ceci est un

char **ft_split_whitespaces(char *str)
{
	if (str == NULL)
		return NULL;

	char *tmpstr = ft_strdup(str);
	unsigned int nbWord = ft_wordCount(tmpstr);
	free(tmpstr);

	char **vector = (char **)malloc(sizeof(char *) * (nbWord + 1));

	unsigned int i;
	unsigned int wordSize;

	wordSize = 0;
	i = -1;
	char *tmpstr2 = ft_strdup(str);	
	int offset = 0;
	while (++i < nbWord)
	{
		wordSize = ft_wordSize(tmpstr2);
		tmpstr2 += wordSize + 1;		
		vector[i] = (char *)malloc(sizeof(char) * (wordSize + 1));
		unsigned int a = -1;
		
		while (++a < (wordSize))
			vector[i][a] = str[a];

		vector[i][wordSize] = '\0';
		str += wordSize + 1;
		offset += wordSize + 1;
	}
	str -= offset;
	free(tmpstr2);
	vector[nbWord] = NULL;
	return vector;
}


//Ceci est un
//size 19

void ft_print_word_tables(char **table)
{
	int i;
	i = -1;

	while (table[++i] != NULL)
	{
		ft_putstr(table[i]);
		ft_putchar('\n');
	}
}

int main(void)
{
	char **vectors = ft_split_whitespaces("ceci est une string	de qualite superieure");
	ft_print_word_tables(vectors);
	
		

	return 0;
}