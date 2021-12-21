#include "backsubst.h"
#include <stdio.h>
/**
 * Zwraca 0 - wsteczne podstawienie zakonczone sukcesem
 * Zwraca 1 - błąd dzielenia przez 0 (element na diagonali = 0)
 * Zwraca 2 - błąd nieprawidłowych rozmiarów macierzy
 */
int  backsubst(Matrix *x, Matrix *mat, Matrix *b) {
	int r = mat->r;

	if(mat->c != b->r)
	{
		//fprintf(stderr, "błąd nieprawiłowych rozmiarow macierzy");
		return 2;
	}

	for(int w = r - 1; w >= 0; w--)
	{
		double s = 0;
		for(int k = w + 1; k < r; k++)
		{
			s += mat->data[w][k] * x->data[k][0];
		}
		x->data[w][0] = (b->data[w][0] - s) / mat->data[w][w];
	}

	for (int i = 0; i < r; i++)
	{
		if(mat->data[i][i] == 0)
		{
			//fprintf(stderr, "element na diagonali rowny 0");
			return 1;
		}
	}


	/* To ponizej jest przepisaniem b do x. Nalezy to poprawic! */

	//int i;
	//for (i =0; i < x->r; i++) {
	//	x->data[i][0] = b->data[i][0];
	//}

	return 0;
}


