/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ChallengeSkyscrapper.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 15:57:50 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/12 18:19:40 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <unistd.h>

int solveSchema(int, int);
void	printSchema(void);
int sameColumn(int, int, int);
int sameSquare(int, int, int);
int sameRow(int, int, int);

/* ------ putchar -------*/

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

/* --------- putstr ------*/

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	c = str[0];
	i = 0;
	while (c != '\0')
	{
		write(1, &c, 1);
		i++;
		c = str[i];
	}
}

void	c_putchar(char *str)
{
	int i;
	while(str[i])
	{
		write(1, &str, 1);
		i++;
	}
}

/* --------- Schema -------*/

int schema[4][4] = {0, 0, 3, 0,
					9, 0, 0, 3,
					0, 0, 1, 8,
					0, 0, 8, 1 };

int schema2[4][4] = {5, 3, 0, 0,
					6, 0, 0, 1, 
					0, 9, 8, 0, 
					8, 0, 0, 0 };

int schema3[4][4] = {0};

/* -------- PrintSchema  -------*/

void printSchema()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d", schema3[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	printf("\n\n");
}

/* -------- Solve Schema -----*/

int solveSchema(int x, int y)
{
	int num = 1;
	int tx = 0;
	int ty = 0;

	if (schema[x][y] != 0)  // DIFFERENT DE 0
	{
		if ( x == 4 && y == 4)
			return (1);
		
		if (x < 3) // Derniere case de la ligne
			x++;
		else	// Passage a la ligne suivante
		{
			x = 0;
			y++;
		}

		if (solveSchema(x, y))
			return (1);
		else
			return (0);
	}

	if (schema[x][y] == 0) // EGAL 0
	{
		while (num < 5)
		{
			if (!sameSquare(x, y, num) && !sameRow(x, y, num) && !sameColumn(x, y, num)) // NOT same square, same column, same row
			{
				schema[x][y] = num; // On met le nombre a l'index de [x] et [y]
				
				if (x == 3 && y == 3)
					return (1);

				if (x < 3)
				{
					tx = x + 1;
				}
				else
				{
					tx = 0;
					ty = y + 1;
				}
				if (solveSchema(tx, ty))
				{
					return (1);
				}
			}
			num++;
		}
		return (0);		
	}
}


int		sameColumn(int x, int y, int num) // Verifie la presence d'un meme chiffre sur la colonne
{
	for (int i = 0; i < 3; i++)
	{
		if (schema[x][y] == num)
			return (1);
	}
	return (0); 
}

int		sameRow(int x, int y, int num)
{
	for (int i = 0; i < 3; i++)
	{
		if (schema[x][y] == num)
			return (1);
	}
	return (0); 
}


int		sameSquare(int x, int y, int num)
{
	if (x < 3)
		x = 0;
	else if (x < 4)
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
			if (schema[x][y] == num)
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

	printSchema();
	solveSchema(x,y);
	printSchema();
	return(0);
}
