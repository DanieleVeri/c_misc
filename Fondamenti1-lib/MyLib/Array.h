#ifndef _ARRAY_H
#define _ARRAY_H
#include "Elementdef.h"
#include "Element.h"
#include <stdio.h>
/*Ricerca elemento nell'array*/
int cercaArray(Item *a, Item obj, int n);
/*Ricerca binaria elemento*/
int cercaArrayBin(Item vet[], int dim, Item el);
/*Inverte array*/
void invArrayR(Item *a, int i, int n);
/*Chiamata*/
void invArray(Item *a, int n);
/*Compara due array Restituisce 0 se a=b, -1 se a<b, 1 se a>b*/
int cmpArray(Item *a, Item *b, int dim_a, int dim_b);
/*Carica un array di item da input utente*/
void loadArray(Item *a, int dim);
//Scrive in output gli elementi dell'array
void outputArray(Item *a, int n);
#endif