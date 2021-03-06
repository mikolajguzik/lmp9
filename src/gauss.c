#include "gauss.h"
#include <stdio.h>
#include <stdlib.h>
/**
 * Zwraca 0 - elimnacja zakonczona sukcesem
 * Zwraca 1 - macierz osobliwa - dzielenie przez 0 
 */

int eliminate(Matrix *mat, Matrix *b){

		int c = mat->c;
		int r = mat->r;
		


	int max = 0;
	int row;
	double zmiana;

	for (int i = 0; i < c; i++)
	{

		row = i;

		for (int j = i; j < r; j++)
		{
			if (max < mat->data[j][i])
			{
				max = mat->data[j][i];
				row = j;
			}

		}

		if (row != i)
		{
			for (int j = 0; j < mat->c; j++)
			{
				zmiana = mat->data[row][j];
				mat->data[row][j] = mat->data[i][j];
				mat->data[i][j] = zmiana;
			}

			zmiana = b->data[row][0];
			b->data[row][0] = b->data[i][0];
			b->data[i][0] = zmiana;
		}

		max = 0;


	}

	if (r > c)
		r = c;
	if (c > r)
		c = r;


	for (int i = 0; i < r; i++)
	{
		if (mat->data[i][i] == 0)
			return 1;

	}


		for ( int i = 0; i < r -1; i++)
		{
			for(int j = i + 1; j < c; j++)
			{
				if (mat->data[j][i] == 0)
					continue;

				double q = mat->data[j][i]/mat->data[i][i];

				for(int k = 0; k < mat->c; k++)
				{
					mat->data[j][k] -= q*mat->data[i][k];
				}

				b->data[j][0] -= q*b->data[i][0];

			}

		}
	return 0;
}