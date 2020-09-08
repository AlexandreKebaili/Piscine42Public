/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TryQueens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 19:03:40 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/11 19:29:48 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// To place n queens on nXn chess board

#include <stdio.h>
//#include <conio.h>
#include <math.h>

int a[30], count = 0;

// row = index || colomn = value ie e = row and a[i] = column

int place(int pos)
{
	int i;

	for(i=1; i < pos; i++)
	{
		if ((a[i] == a[pos]) || (abs(a[i] - a[pos] == abs(i-pos))))
				return (0);
	}
	return (1);
}

void print_sol(int n)
{
	int i,j;
	count++;
	printf("\n \n Solution #%d : \n", count);
	for (i = 1; i<=n; i++)
	{
		for (j = 1; j<= n; j++)
		{
			if (a[i] == j)
				printf("Q\t");
			else
				printf("*\t");
		}
		printf("\n");
	}
}

void queen(int n)
{
	int k = 1;
	a[k] = 0;
	while (k!= 0)
	{
		do
		{
			a[k]++;
		}
		while ((a[k] <= n) && !place(k)); // while columns are left and k 
		{
			if (a[k] <= n)
			{
				if (k == n)
					print_sol(n);
				else
				{
					k++;
					a[k] = 0;
				}
			}
			else
				k--;
		}
	}
}

void	main()
{
	int i, n;
	printf("Enter the number of Queens \n");
	scanf("%d", &n);
	queen(n);
	printf("\n Total solutions = %d", count);
}
