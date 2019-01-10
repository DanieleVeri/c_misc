#ifndef _ELEMENT_H
#define _ELEMENT_H
#include "Elementdef.h"
#include "IOConsole.h"
/*Prototipi:
*1) Swap: scambia due item*/
void swap(Item *a, Item *b);
/*2) Compare: retituisce -1 se a<b, 0 se a=b, 1 se a>b*/
int compare(Item a, Item b);
/*3) Assign: Assegna un item ad un'altro*/
void assign(Item *lvalue, Item rvalue);
/*4) Massimo e minimo tra due Item*/
Item mioMin(Item a, Item b);
Item mioMax(Item a, Item b);
Item inputLoadItem(void);
void outputItem(Item a);
#endif