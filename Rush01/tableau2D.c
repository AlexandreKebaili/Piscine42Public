/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableau2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 15:01:49 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/11 17:14:04 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main()
{
	int globale[6][6];
	int i2, j2, row2, col2;
	int matrice[4][4];
	int i, j, row, col;
	//int matrice[row][col];
	printf("Entrez le nombre de lignes (max 6) : ");
	scanf("%d", &row2);
	printf("Entrez le nombre de colonnes (max 6) : ");
	scanf("%d", &col2);
	printf("Entrez les %d elements du tableau globale : ", row2*col2);
	
	printf("Entrez le nombre de lignes (max 4) : ");
	scanf("%d", &row);
	printf(" Entrez le nombre de colonnes (max 4) : ");
	scanf("%d", &col);
	printf("Entrez les %d elements de tableau : ", row*col);

	// Construction du tableau englobant le tableau
	
	for (i2 = 0; i2 < row2; i2++)
	{
		for (j2=0; j2 < col; j2++)
		{
			scanf("%d", &globale[i2][j2]);
		}
	}
	printf("Le tableau 2D = \n");
	for (i2 = 0; i2 < row2; i2++)
	{
		for (j2 = 0; j2 < col2; j2++)
		{
			printf("%4d", globale[i2][j2]);
		}
		printf("\n");
	}

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			scanf("%d", &matrice[i][j]);
		}
	}
	printf("Le tableau 2D = \n");
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%4d", matrice[i][j]);
		}
		printf("\n");
	}
	return 0;
}
