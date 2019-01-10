#ifndef _LISTE_H
#define _LISTE_H
#include <stdio.h>
#include <stdlib.h>
#include "Elementdef.h"
#include "Element.h"
//Funzioni base
List consList(Item e, List l);
List emptyList(void);
int chkEmptyList(List l);
Item headList(List l);
List tailList(List l);
//Funzioni non base con struct sharing!
void showList(List l);
int memberList(Item el, List l);
List appendList(List l1, List l2);
List reverseList(List l);
List copyList(List l);
List deleteItemList(Item el, List l);
//Funzioni mie
int searchList(List l, Item element);
List removeDuplicate(List l1);
void ordListBs(List l);

#endif