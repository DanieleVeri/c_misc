#include "Element.h"
/*Funzioni da modificare in base al tipo dei dati del problema*/
void swap(Item *a, Item *b)
{
	Item box;
	assign(&box,*a);
	assign(a, *b);
	assign(b, box);
}
int compare(Item a, Item b)
{
	return a.a > b.a ? 1 : (a.a == b.a ? 0 : -1);
}
void assign(Item *lvalue, Item rvalue)
{
	*lvalue = rvalue;
}
Item mioMin(Item a, Item b)
{
	return compare(a, b) > -1 ? b : a;
}
Item mioMax(Item a, Item b)
{
	return compare(a, b) > -1 ? a : b;
}
Item inputLoadItem(void)
{
	Item r;
	r.a = readInt();
	return r;
}
void outputItem(Item a)
{
	printf("\na = %d\n",a.a);
	return;
}