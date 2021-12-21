#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;

	FILE * file_1 =  fopen(argv[1],"r");
	FILE * file_2 =  fopen(argv[2],"r");
	int check;

	while ( (check = fgetc(file_1)) != EOF)
	{
		if (isspace(check) || check == '.' || check == '-')
			continue;
		
		else if (isdigit(check))
			continue;

		else
		{
			printf("Zostały podane nieprawidłowe dane :(\n %c - w pliku %s\n\n", check, argv[1]);
			exit (1);
		}
	}



	while ( (check = fgetc(file_2)) != EOF)
	{
		if (isspace(check) || check == '.' || check == '-')
			continue;
		
		else if (isdigit(check))
			continue;

		else
		{
			printf("Zostały podane nieprawidłowe dane :(\n %c - w pliku %s\n\n", check, argv[1]);
			exit (1);
		}
	}
	

	if (A == NULL) return -1;
	if (b == NULL) return -2;
	

	printToScreen(A);
	printToScreen(b);

	res = eliminate(A,b);

	for (int i = 0; i < A->r; i++)
	{
		if (A->data[i][i] == 0)
		{
			fprintf(stderr, "Macierz osobliwa, dzielenie przez 0.\n");
			return 1;
		}

	}

	x = createMatrix(b->r, 1);
	if (x != NULL) {
		res = backsubst(x,A,b);

		if(A->c != x->r)
		{
			fprintf(stderr, "Błąd nieprawidłowych rozmiarow macierzy, nie da się rozwiązać\n");
			return 1;
		}

		printf("Test 1 - poprawne dane %dx%d: OK.\n", A->r, A->c);

		printToScreen(x);
	  freeMatrix(x);
	} else {
					fprintf(stderr,"Błąd! Nie mogłem utworzyć wektora wynikowego x.\n");
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
