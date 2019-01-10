#include "IOFile.h"
void apriFile(FILE **f, char *nome, char *modo)
{
	*f = fopen(nome, modo);
	if (*f == NULL)
	{
		printf("\nErrore apertura file: %s\n", nome);
		Pause();
		exit(1);
	}
	return;
}
int leggiFileItem(FILE *f, Item *i)
{
	return fread(i, sizeof(Item), 1, f);
}
int scriviFileItem(FILE *f, Item i)
{
	return fwrite(&i, sizeof(Item), 1, f);
}
int caricaDaFile(FILE *f, Item **out)
{
	Item i;
	int dim = 0;
	while (leggiFileItem(f, &i) == 1)
		dim++;
	(*out) = (Item *)malloc(sizeof(Item)*dim);
	rewind(f);
	dim = 0;
	while (leggiFileItem(f, &i) == 1)
		(*out)[dim] = i, dim++;
	return dim;
}