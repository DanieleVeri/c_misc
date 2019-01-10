#include "Array.h"
/*Ricerca elemento nell'array*/
int cercaArray(Item *a, Item obj, int n)

{
	int i = 0, flag = 1;
	do
	{
		if (compare(a[i], obj)==0)
			flag = 0;
		else
			i++;
	} while (flag && i<n);
	if (i == n)
		return -1;
	else
		return i;
}
/*Ricerca binaria elemento*/
int cercaArrayBin(Item vet[], int dim, Item el) 
{
	int startPos;
	int med = dim / 2;
	if (compare(vet[med], el) == 0)
		return med;
	if (med == 0)
		return -1;
	if (compare(el, vet[med]) == -1)  //el<vet[med]
	{
		return cercaArrayBin(vet, med, el);
	}
	else 
	{
		startPos = med + 1;
		return startPos +
			cercaArrayBin(&vet[startPos], dim - startPos, el);
	}
}
/*Inverte array*/
void invArrayR(Item *a, int i, int n)
{
	if (i == n / 2)
		return;
	swap(a + (n - i), a + i);
	invArrayR(a, i + 1, n);
	return;
}
/*Chiamata*/
void invArray(Item *a, int n)
{
	invArrayR(a, 0, n - 1);
	return;
}
/*Compara due array Restituisce 0 se a=b, -1 se a<b, 1 se a>b*/
int cmpArray(Item *a, Item *b, int dim_a, int dim_b)
{
	int i = 0, flag = 1;
	int min = dim_a > dim_b ? dim_b : dim_a;
	do
	{
		if (compare(a[i], b[i])!=0)
			flag = 0;
		else
		{
			if (i ==min - 1)
			{
				flag = 0;
				i--;
			}
			i++;
		}
	} while (flag && i<min);
	return compare (a[i], b[i]);
}
/*Carica array da input utente*/
void loadArray(Item *a, int dim)
{
	int i = 0;
	for (i = 0; i < dim; i++)
	{
		printf("\nInsersci elemento di indice %d\n", i);
		a[i] = inputLoadItem();
	}
	return ;
}
//Scrive in output gli elementi dell'array
void outputArray(Item *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("\nElemento di indice %d:\n", i);
		outputItem(a[i]);
	}
	return;
}