#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_print_comb()
{
	int i;
	int j;

	i = 0;
	j = i + 1;

	while (i <= 99)
	{
		while (j <= 99)
		{
			
			
			ft_putchar(i/10 + '0');
			ft_putchar(i%10 + '0');

			ft_putchar(' ');

			ft_putchar(j/10 + '0');
			ft_putchar(j%10 + '0');
			
			ft_putchar('\n');
			j++;
		}	
		i++;
		j = i + 1;	
				
	}
}



int main(int argc, char* argv[])
{
	ft_print_comb();
	return 0;
}


