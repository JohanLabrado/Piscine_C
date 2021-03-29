#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_printReverseAlphabet()
{
	int count = 0;
	char letter = 'z';
	while (count < 26)
	{
		ft_putchar(letter--);
		count++;
	}
}

int main(int argc, char* argv[])
{
	ft_printReverseAlphabet();
	return 0;
}


