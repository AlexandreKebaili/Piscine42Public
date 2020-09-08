/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testMalloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akebaili <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 10:10:38 by akebaili          #+#    #+#             */
/*   Updated: 2020/07/11 10:52:03 by akebaili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	main()
{
	int a = 10;
	int *pa = malloc(sizeof(int)); 

	if (pa == NULL)
	{
		printf("Erreur Malloc ! \n");
		return (1);
	}


	int *tab = malloc(5 * sizeof(int));
	//int tab[5];

	tab[0] = 0;
	*(tab + 1) = 10; // Revient au meme que tab[1] 
	tab[2] = 20;
	tab[3] = 30;
	tab[4] = 44;

	printf("Adresse de &pa : %p \n", &pa);
	printf("Adresse de pa : %p \n", pa);
	printf("Valeur a l'adresse pa : %d \n", *pa);

	int i = 0;
	while (i < 5)
	{
		printf("tab[%d] = %d \n", i, tab[i]);
		i++;
	}

	free(pa); // L'ibere l'espace utiliser par malloc
	free(tab);

	return (0);
}
