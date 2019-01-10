#ifndef _IOFILE_H
#define _IOFILE_H
#define _CRT_SECURE_NO_WARNINGS
#include "IOConsole.h"
#include "Elementdef.h"
#include <stdio.h>
#include <stdlib.h>
void apriFile(FILE **f, char *nome, char *modo);
int leggiFileItem(FILE *f, Item *i);
int scriviFileItem(FILE *f, Item i);
//NOTA: Memoria allocata dinamicamente, liberare out con free().
int caricaDaFile(FILE *f, Item **out);


#endif