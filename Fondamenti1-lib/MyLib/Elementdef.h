#ifndef _ELEMENTDEF_H
#define _ELEMENTDEF_H
typedef struct
{
	int a;
} Item ;
//Liste
typedef struct list_element
{
	Item value;
	struct list_element *next;
} Node;
typedef Node *List;
#endif