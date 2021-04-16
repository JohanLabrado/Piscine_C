#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define MAP_SIZE 8
#define MAP_TOTAL_SIZE 64

int map[64] = {0};
int nbQueen = 0;

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

void ft_place_queen(int coord)
{
	int x;
	int y;
	int i = -1;
	int diagPos = coord;
	int diagNeg = coord;
	int invDiagPos = coord;
	int invDiagNeg = coord;

	x = (coord / 8) * 8;
	y = coord % 8;

	map[coord] = 2;

	//axe x et y
	while ( ++i < MAP_SIZE)
	{
		if (map[x] == 0 )
			map[x] = 5;		
		if (map[y] == 0 )
			map[y] = 5;	
			
		x++;
		y += 8;		

		diagNeg -= 9;
		diagPos += 9;
		invDiagNeg -= 7;
		invDiagPos += 7;

		//diagonale NO - SE	
		if (diagNeg / 8 >= 0 && diagNeg % 8 >= 0 && map[diagNeg] == 0 )
		{
			map[diagNeg] = 5;
			if ((diagNeg % 8) == 7 || (diagNeg / 8) == 7)
				diagNeg = -1;
		}
			
		if (diagPos / 8 < 8 && diagPos % 8 < 8 && map[diagPos] == 0)
		{
			map[diagPos] = 5;
			if ((diagPos % 8) == 7 || (diagPos / 8) == 7)
				diagPos = 64;
		}

		//diagonale NE - SO	
		if (invDiagNeg / 8 >= 0 && invDiagNeg % 8 >= 0 && map[invDiagNeg] == 0 )
		{
			map[invDiagNeg] = 5;
			if ((invDiagNeg % 8) == 7 || (invDiagNeg / 8) == 7)
				invDiagNeg = -1;
		}
			
		if (invDiagPos / 8 < 8 && invDiagPos % 8 < 8 && map[invDiagPos] == 0)		
		{
			map[invDiagPos] = 5;
			if ((invDiagPos % 8) == 7 || (invDiagPos / 8) == 7)
				invDiagPos = 64;
		}
			
		
	}
}

void ft_eight_queens_puzzle(int coord)
{
	if (nbQueen == 8)
	return ;

	if (map[coord] == 0)
	{
		ft_place_queen(coord);
		nbQueen++;
		ft_eight_queens_puzzle((coord + 8) - (coord % 8));
	}

	ft_eight_queens_puzzle(coord + 1);


}

int main(void)
{
	ft_eight_queens_puzzle(0);
	int i = 0;
	int count = 0;
	for (i = 0; i < MAP_TOTAL_SIZE; i++)
	{
		ft_putnbr(map[count]);
		ft_putchar(' ');
		count++;
		if ((count % 8) == 0)
			ft_putchar('\n');
	}
	
	
	return 0;
}


