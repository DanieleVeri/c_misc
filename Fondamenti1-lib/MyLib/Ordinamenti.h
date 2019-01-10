#ifndef _ORDINAMENTI_H
#define _ORDINAMENTI_H
#include "Elementdef.h"
#include "Element.h"
#include <stdio.h>
/*Prototipi:
*Gestione contatori scambi:*/
void incComp(void);
void incSwap(void);
void resetCounters(void);
void printCounters(void);
/*Ordinamenti:
*Ordinamento Naive Sort*/
int trovaPosMax(Item v[], int n);
void ordNs(Item v[], int n);
/*Ordinamento Bubble Sort*/
void ordBs(Item v[], int n);
/*Ordinamento Insert Sort*/
void put_item(Item v[], int pos);
void ordIs(Item v[], int n);
/*Ordinamento Merge Sort*/
void merge(Item v[], int i1, int i2, int fine, Item vout[]);
void ordMsR(Item v[], int first, int last, Item vout[]);
void ordMs(Item v[], int n, Item vout[]);
/*Ordinamento Quick Sort*/
void ordQsR(Item a[], int iniz, int fine);
void ordQs(Item a[], int dim);
#endif