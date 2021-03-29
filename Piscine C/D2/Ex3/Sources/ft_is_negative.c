#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_is_negative(int number)
{
	(number & 0x80000000) ? ft_putchar('N') : ft_putchar('P');
}



int main(int argc, char* argv[])
{
	ft_is_negative(-456656);
	return 0;
}


