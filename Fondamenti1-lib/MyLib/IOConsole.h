#ifndef _IOCONSOLE_H
#define _IOCONSOLE_H
#include <stdio.h>
#include <stdlib.h>
//Pausa programma
void Pause(void);
//Leggi intero
int readInt(void);
//Carica array interi da input utente
int loadArrayInt(int *a, int n, int stop);
//Scrive in output gli elementi dell'array
void outArrayInt(int *a, int n);
#endif