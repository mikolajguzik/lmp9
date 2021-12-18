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
		double zmiana;

		int blad = 0;
		
		if(r != c)
		{
			printf("Kod dziala tylko dla macierzy kwadratowych\n");
			exit (1);
		}

		
		for(int i = 0; i < r; i++)		//sprawdzenie czy na przekątnej nie ma zer
		{								//a jeżeli są to zmiana kolejności
			if (mat->data[i][i] == 0)
			{
				blad = 1;
				for (int j = i; j < c; j++)
				{
					if(mat->data[j][i] != 0)
					{
						for (int k = 0; k < c; k++)
						{
							zmiana = mat->data[i][k];
							mat->data[i][k] = mat->data[j][k];
							mat->data[j][k] = zmiana;
						}

						zmiana = b->data[i][0];
						b->data[i][0] = b->data[j][0];
						b->data[j][0] = zmiana; 

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
				if (mat->data[j][i] == 0)
					continue;

				double q = mat->data[j][i]/mat->data[i][i];

				for(int k = 0; k < c; k++)
				{
					mat->data[j][k] -= q*mat->data[i][k];
				}

				b->data[j][0] -= q*b->data[i][0];

			}

		}


		return 0;
}

