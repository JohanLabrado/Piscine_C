#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb()
{
	int i = 0;
	int j = i + 1;
	int k = j + 1;
	while (i <= 7)
	{
		while (j <= 8)
		{
			while (k <= 9)
			{
				ft_putchar(i + '0');
				ft_putchar(j + '0');
				ft_putchar(k + '0');
				ft_putchar('\n');
				k++;
			
			}
			j++;
			k = j + 1;
			
		}
		
		j = i + 1;
		i++;
		
	}
}



int main(int argc, char* argv[])
{
	ft_print_comb();
	return 0;
}


