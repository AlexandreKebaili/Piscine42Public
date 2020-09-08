/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChallengeSudoku.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 11:59:09 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/12 15:44:01 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int solveSudoku(int, int);
void	printSudoku(void);
int sameColumn(int, int, int);
int sameSquare(int, int, int);
int sameRow(int, int, int);

/* --------- Sudoku -------*/

int sudoku[9][9] = {0, 0, 3, 0, 2, 0, 6, 0, 0,
					9, 0, 0, 3, 0, 5, 0, 0, 1,
					0, 0, 1, 8, 0, 6, 4, 0, 0,
					0, 0, 8, 1, 0, 2, 9, 0, 0,
					7, 0, 0, 0, 0, 0, 0, 0, 8,
					0, 0, 6, 7, 0, 8, 2, 0, 0,
					0, 0, 2, 6, 0, 9, 5, 0, 0,
					8, 0, 0, 2, 0, 3, 0, 0, 9,
					0, 0, 5, 0, 1, 0, 3, 0, 0};

int sudoku2[9][9] = {5, 3, 0, 0, 7, 0, 0, 0, 0,
					6, 0, 0, 1, 9, 5, 0, 0, 0,
					0, 9, 8, 0, 0, 0, 0, 6, 0,
					8, 0, 0, 0, 6, 0, 0, 0, 3,
					4, 0, 0, 8, 0, 3, 0, 0, 1,
					7, 0, 0, 0, 2, 0, 0, 0, 6,
					0, 6, 0, 0, 0, 0, 2, 8, 0,
					0, 0, 0, 4, 1, 9, 0, 0, 5,
					0, 0, 0, 0, 8, 0, 0, 7, 9};

int sudoku3[9][9] = {0};

/* -------- PrintSudoku -------*/

void printSudoku()
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j<8; j++)
		{
			printf("%d", sudoku[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n\n");
}

/* -------- Solve Sudoku -----*/

int solveSudoku(int x, int y)
{
	int num = 1;
	int tx = 0;
	int ty = 0;

	if (sudoku[x][y] != 0)  // DIFFERENT DE 0
	{
		if ( x == 8 && y == 8)
			return (1);
		
		if (x < 8)
			x++;
		else
		{
			x = 0;
			y++;
		}
		if (solveSudoku(x, y))
			return (1);
		else
			return (0);
	}

	if (sudoku[x][y] == 0) // EGAL 0
	{
		while (num < 10)
		{
			if (!sameSquare(x, y, num) && !sameRow(x, y, num) && !sameColumn(x, y, num))
			{
				sudoku[x][y] = num;
				
				if (x == 8 && y == 8)
					return (1);

				if (x < 8)
				{
					tx = x + 1;
				}
				else
				{
					tx = 0;
					ty = y + 1;
				}
				if (solveSudoku(tx, ty))
				{
					return (1);
				}
			}
			num++;
		}
		return (0);		
	}
}


int		sameColumn(int x, int y, int num)
{
	for (int i = 0; i < 8; i++)
	{
		if (sudoku[x][y] == num)
			return (1);
	}
	return (0); 
}

int		sameRow(int x, int y, int num)
{
	for (int i = 0; i < 8; i++)
	{
		if (sudoku[x][y] == num)
			return (1);
	}
	return (0); 
}


int		sameSquare(int x, int y, int num)
{
	if (x < 3)
		x = 0;
	else if (x < 6)
		x = 3;
	else
		x = 6;

	if (y < 3)
		y = 0;
	else if (y < 6)
		y = 3;
	else
		y = 6;

	for (int i = x; i < x + 3; i++)
	{
		for (int j = y; j < y + 3; j++)
		{
			if (sudoku[x][y] == num)
				return (1);
		}
	}
	return (0); 
}



/* ----------------- MAIN ----------------------- */
int	main()
{
	int x = 0;
	int y = 0;

	printSudoku();
	solveSudoku(x,y);
	printSudoku();
	return(0);
}
