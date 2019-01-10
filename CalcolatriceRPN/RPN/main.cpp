/*Eseguibile che mostra come usare la libreria rpn.h*/
//Header
#include <iostream>
#include <cstdlib>
#include <cstring>
//Libreria funzioni
#include "rpn.h"
//Namespace
using namespace std;

//Main
int main (void)
{
	system("cls");
	//----------------------------//
	cout<<"Scrivere l'espressione da calcolare:"<<endl;
	char exp[999];
	cin.getline(exp,999);
	//chksynx verifica che la forma infissa sia priva degli errori più comuni...
	if (chksyntx(exp)==0)
		cout<<"Errore di sintassi!"<<endl;
	else
	{
		//Ottengo la stringa rpn
		string rpn=FoundRPN(exp);
		cout<<"La forma RPN e': ";
		cout.write(rpn.c_str(),rpn.size());
		cout<<endl;
		//La elaboro e mando come output il risultato:
		cout<<"Il risultato dell'espressione vale: "<<SolveRPN(rpn)<<endl;
	}
	//----------------------------//
	cout<<endl<<endl<<endl;
	system("pause");
	return 0;
}