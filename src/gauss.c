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
		double **macierz = mat->data;
		double zmiana[c];

		int blad = 0;
		
		if(r != c)
		{
			printf("Kod dziala tylko dla macierzy kwadratowych\n");
			exit (1);
		}

		
		for(int i = 0; i < r; i++)		//sprawdzenie czy na przekątnej nie ma zer
		{
			if (macierz[i][i] == 0)
			{
				blad = 1;
				for (int j = i; j < c; j++)
				{
					if(macierz[j][i] != 0)
					{
						for (int k = 0; k < c; k++)
						{
							zmiana[k] = macierz[i][k];
							macierz[i][k] = macierz[j][k];
							macierz[j][k] = zmiana[k];
						}
						blad = 0;
					}
					if (blad == 1)
					{
						printf("Nie da sie zastosowac metody eliminacji dla tego macierza.\n");
						exit(1);
					}
					break;

				}

			}
			
		}


		for ( int i = 0; i < r -1; i++)
		{
			for(int j = i + 1; j < c; j++)
			{
				double q = macierz[j][i]/macierz[i][i];

				for(int k = 0; k < c; k++)
				{
					macierz[j][k] -= q*macierz[i][k];
				}
				


				

			}

		}


		return 0;
}

