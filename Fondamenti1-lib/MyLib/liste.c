#include "liste.h"
//Funzioni base
List consList (Item e, List l) 
{
	List t;
	t = (List) malloc (sizeof(Node));
	t->value = e; t->next = l;
	return t;
}
List emptyList(void)
{
	return NULL;
}
int chkEmptyList (List l) 
{
	return l == NULL ? 1 : 0;
}
Item headList (List l) 
{
	if (chkEmptyList(l))		
		abort();
	else 
		return l->value;
}
List tailList (List l) 
{
	if (chkEmptyList(l)) 
		abort();
	else 
		return l->next;
}
//Funzioni non base con struct sharing!
void showList (List l) 
{ 
	printf("[");
	while (!chkEmptyList(l)) 
	{
		outputItem(headList(l));
		l = tailList(l);
		if (!chkEmptyList(l)) 
			printf(", ");
	} 
	printf("]\n");
}
int memberList(Item el, List l) 
{
	if (chkEmptyList(l)) 
		return 0;
	else if (compare(el, headList(l))== 0) 
		return 1;
	else 
		return memberList(el, tailList(l));
}
List appendList(List l1, List l2) 
{
	if (chkEmptyList(l1))
		return l2;
	else 
		return consList(headList(l1), appendList(tailList(l1), l2));
}
List reverseList(List l) 
{
	if (chkEmptyList(l)) 
		return emptyList();
	else 
		return appendList(reverseList(tailList(l)), consList(headList(l), emptyList()));
}
List copyList (List l) 
{
	if (chkEmptyList(l)) 
		return l;
	else 
		return consList(headList(l), copyList(tailList(l)));
}
List deleteItemList (Item el, List l) 
{
	if (chkEmptyList(l))
		return emptyList();
	else if (compare(el, headList(l)) == 0)
		return tailList(l);
	else 
		return consList(headList(l), deleteItemList(el, tailList(l)));
}
//Funzioni mie
int searchList(List l, Item element)
{
	if (chkEmptyList(l))
		return -1;
	if (compare(l->value, element) == 0)
		return 1;
	else
	{
		if (searchList(tailList(l), element) != -1)
			return 1 + searchList(tailList(l), element);
		else
			return -1;
	}
}
List removeDuplicate(List l1)
{
	if (chkEmptyList(l1->next))
		return l1;
	if (searchList(tailList(l1), l1->value) == -1)
		return consList(l1->value, removeDuplicate(tailList(l1)));
	else 
		return removeDuplicate(tailList(l1));
}
void ordListBs(List l)
{
	int ordinato = 0;
	List tmp = l;
	while (!ordinato)
	{
		ordinato = 1;
		l = tmp;
		while (!chkEmptyList(l->next))
		{
			if (compare(l->value, l->next->value) == 1)   //v[i]>v[i+1]
			{
				swap(&(l->value), &(l->next->value));
				ordinato = 0;
			}
			l = tailList(l);
		}
	}
}