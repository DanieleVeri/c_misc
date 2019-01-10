#include "IOConsole.h"
//Pausa programma
void Pause(void)
{
	printf("\n\n");
	system("pause");
}
//Leggi intero
int readInt(void)
{
	char c;   //Carattere in lettura
	int neg = 0;      //L'intero letto è negativo
	int r = 0;    //Risultato
	int i = 0;    //Indice caratteri letti
	do
	{
		c = getchar();
		if (c == '-')    //Se legge carattere -
		{
			if (i == 0)
				neg = 1;
			else
			{
				c = '\n';
				while (getchar() != '\n');  //Pulisco buffer
			}
		}
		if (c >= '0' && c <= '9')  //Se legge carattere cifra...
		{
			i++;
			r += c - '0';
			r *= 10;
		}
		else
		{
			if (c != '\n' && c != '-')  //Se legge un carattere non cifra (o -) smette di leggere
			{
				c = '\n';
				while (getchar() != '\n');  //Pulisco buffer
			}
			if (c == '\n' && i == 0)  //Se si preme solo invio non registra alcun numero
				c = '1';
		}
	} while (c != '\n');
	return neg ? -r / 10 : r / 10 ;
}
//Carica array interi da input utente
int loadArrayInt(int *a, int n, int stop)
{
	int i = 0, tmp, flag=1;
	do
	{
		printf("\nInserisci l'elemento di indice %d:\n",i);
		tmp = readInt();
		if (tmp != stop)
		{
			*(a + i) = tmp;
			i++;
		}
		else
			flag = 0;
	} while (i<n && flag);
	return i;
}
//Scrive in output gli elementi dell'array
void outArrayInt(int *a, int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("\nElemento di indice %d: %d\n", i, a[i]);
	return;
}