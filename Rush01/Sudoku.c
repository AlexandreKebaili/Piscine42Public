/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 12:28:02 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/12 11:50:02 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int ** createPuzzle()
{
	int **puzzle;
	int i, j;
	int sudoku[9][9] = {0,1,9,	0,0,2,	0,0,0,
						4,7,0,	6,9,0,	0,0,1,
						0,0,0,	4,0,0,	0,9,0,

						8,9,4,	5,0,7,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	2,0,1,	9,5,8,

						0,5,0,	0,0,6,	0,0,0,
						6,0,0,	0,2,8,	0,7,9,
						0,0,0,	1,0,0,	8,6,0};
	
	
	
	int sudoku2[9][9] = {0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,

						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,

						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0,
						0,0,0,	0,0,0,	0,0,0};

	int sudoku3[9][9] = {0};


	puzzle = (int**)malloc(sizeof(int*)*9);  // Allocation de memoire pour le puzzle

	i = 0;
	while (i < 9)
	{
		puzzle[i] = (int*)malloc(sizeof(int)*9);
		j = 0;
		while (j < 9)
		{
			puzzle[i][j] = sudoku[i][j];
		}
	}
	return (puzzle);
}

void	printPuzzle(int ** puzzle)
{
	int i, j;

	i = 0;
	j = 0;

	while (i <9)
	{
		while(j < 9)
		{
			printf("%d", sudoku[i][j]);
			printf("%d", sudoku2[i][j]);
			printf("%d", sudoku3[i][j]);
		}
		printf("\n");
	}
}

void solvesudoku(int x, int y)
{
	int num = 1;

	if ()
}


int	main()
{
	int **puzzle;
	puzzle = createPuzzle();
	printPuzzle(puzzle);
	return (0);
}
