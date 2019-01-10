#include "Ordinamenti.h"
/*Gestione contatori scambi:*/
/*Variabili globali*/
int swapCount = 0;
int compCount = 0;
void incComp(void)
{
	compCount++;
}
void incSwap(void)
{
	swapCount++;
}
void resetCounters(void)
{
	compCount = 0;
	swapCount = 0;
}
void printCounters(void)
{
	printf("\nNumero di confronti: %d\n", compCount);
	printf("\nNumero di scambi: %d\n", swapCount);
}
/*Ordinamento Naive Sort*/
int trovaPosMax(Item v[], int n)
{
	int i, posMax = 0;
	for (i = 1; i<n; i++)
	{
		if (compare(v[posMax], v[i]) == -1)  //v[posMax]<v[i]
			posMax = i;
		incComp();
	}
	return posMax;
}
void ordNs(Item v[], int n)
{
	int p;
	while (n>1)
	{
		p = trovaPosMax(v, n);
		if (p<n - 1)
		{
			swap(&v[p], &v[n - 1]);
			incSwap();
		}
		n--;
	}
}
/*Ordinamento Bubble Sort*/
void ordBs(Item v[], int n)
{
	int i, ordinato = 0;
	while (n>1 && !ordinato)
	{
		ordinato = 1;
		for (i = 0; i<n - 1; i++)
		{
			incComp();
			if (compare(v[i],v[i + 1]) == 1)   //v[i]>v[i+1]
			{
				swap(&v[i], &v[i + 1]);
				incSwap();
				ordinato = 0;
			}
		}
		n--;
	}
}
/*Ordinamento Insert Sort*/
void put_item(Item v[], int pos)
{
	int i = pos - 1;
	Item x;
	assign(&x,v[pos]);
	while (i >= 0 && compare(x,v[i]) == -1)
	{
		incComp();
		incSwap();  //??
		assign(&v[i + 1] , v[i]);
		i--;
	}
	assign(&v[i + 1] , x);
	incSwap();  //??
}
void ordIs(Item v[], int n)
{
	int k;
	for (k = 1; k<n; k++)
		put_item(v, k);
}
/*Ordinamento Merge Sort*/
void merge(Item v[], int i1, int i2, int fine, Item vout[])
{
	int i = i1, j = i2, k = i1;
	while (i <= i2 - 1 && j <= fine) {
		incComp();
		incSwap();
		if (compare(v[i], v[j])==-1)   //v[i]<v[j]
			assign(&(vout[k]), v[i++]);
		else
			assign(&(vout[k]), v[j++]);
		k++;
	}
	while (i <= i2 - 1)
	{
		incSwap();
		assign(&(vout[k]), v[i++]);
		k++;
	}
	while (j <= fine)
	{
		incSwap();
		assign(&(vout[k]), v[j++]);
		k++;
	}
	for (i = i1; i <= fine; i++)
	{
		incSwap();
		assign(&(v[i]), vout[i]);
	}
}
void ordMsR(Item v[], int first, int last, Item vout[])
{
	int mid;
	if (first < last)
	{
		mid = (last + first) / 2;
		ordMsR(v, first, mid, vout);
		ordMsR(v, mid + 1, last, vout);
		merge(v, first, mid + 1, last, vout);
	}
}
void ordMs(Item v[], int n, Item vout[])
{
	ordMsR(v, 0, n - 1, vout);
	return;
}
/*Ordinamento Quick Sort*/
void ordQsR(Item a[], int iniz, int fine)
{
	int i, j, iPivot;
	Item pivot;
	if (iniz < fine)
	{
		i = iniz;
		j = fine;
		iPivot = fine;
		assign(&pivot, a[iPivot]);
		incSwap();
		do /* trova la posizione del pivot */
		{
			while (i < j && compare(a[i], pivot)<1) { i++; incComp(); }    //a[i]<=pivot
			while (j > i && compare(a[j], pivot)>-1){ j--; incComp(); }   //a[j]>=pivot
			if (i < j) { swap(&a[i], &a[j]); incSwap(); }
		} while (i < j);
		/* determinati i due sottoinsiemi */
		/* posiziona il pivot */
		if (i != iPivot && compare(a[i], a[iPivot])!=0)
		{
			swap(&a[i], &a[iPivot]);
			incSwap();
			incComp();
			iPivot = i;
		}
		/* ricorsione sulle sottoparti, se necessario */
		if (iniz < iPivot - 1)
			ordQsR(a, iniz, iPivot - 1);
		if (iPivot + 1 < fine)
			ordQsR(a, iPivot + 1, fine);
	}
}
void ordQs(Item a[], int dim)
{
	ordQsR(a, 0, dim - 1);
	return;
}