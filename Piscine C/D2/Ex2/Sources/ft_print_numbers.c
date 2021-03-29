#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_numbers()
{
	int count = 0;
	char number = '0';
	while (count < 10)
	{
		ft_putchar(number++);
		count++;
	}
}



int main(int argc, char* argv[])
{
	ft_print_numbers();
	return 0;
}


