#include <stdio.h>
#include <stdlib.h>
#include <io.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}


int main(int argc, char* argv[])
{
	ft_putchar('a');
	return 0;
}


