/**********************************************************************************************
                                Libreria creata da Dany 
                    -----> www.danysoftware.altervista.org <-----
*pu� essere distribuita, modificata, rielaborata come meglio si crede, basta si citi la fonte*
***********************************************************************************************

*SINTASSI DELLE ESPRESSIONI*
-FUNZIONI DISPONIBILI:

*TRIGONOMETRIA*
-seno->sin()
-coseno->cos()
-tangente->tan()
-arcoseno->asi()
-arcocoseno->acs()
-arcotangente->atg()
-seno iperbolico->snh()
-coseno iperbolico->csh()
-tangente iperbolica->tah()

*LOGARITMI*
-logaritmo base 10->log()
-logaritmo base e (logaritmo naturale)->lon()
-logaritmo base 2->lod()
[NOTA:]->Logarimo con un'altra base: dividere il logaritmo base 10 dell'argomento con il logaritmo base 10 della base.
[Esempio:]->logaritmo base 3 di x^2 ==>   (log(x^2))/(log(3))

*ALGEBRA*
-radice quadrata->rad()
-radice cubica->rac()
-radice quinta->raq()

*VARIE*
-valore assoluto->ass()
-parte intera->int()
-fattoriale->fac()
-funzione pi greco (numeri primi precedenti)->qrm()
-numero divisori->div()
-----------------------------------------------------------------------------------------------------------------------------
-OPERATORI:
*Prededenzadegli operatori in ordine crescente:*

1: +, -
2: *, /, %
3: ^, [funzioni]

[NOTA]: Il simbolo '%' indica l'operatore del modulo (il resto della divisione) e non ha nulla a che fare col calcolo della percentuale.
*Opposti:*
-Per ottenere 'opposto di un valore, anteporre il segno meno all'espressione tra parentesi.
-Esempio:
 -(sin(x)+log(y)) = -(-(x+1))                        (in pratica basta che dopo il meno ci sia sempre la parentesi)
-----------------------------------------------------------------------------------------------------------------------------
-COSTANTI:
-Le costanti adoperate sono due:

 p -> (con valore approssimato a 3,14159)
 e -> (con valore approssimato a 2,71828)
 *******************************************************************************************/
//Header
#include <iostream>
#include <cmath>
#include <cstring>
#include <stack>
//Namespace
using namespace std;
//Funzioni:
//Funzioni teoria dei numeri:
//Funzione "Pi di x", ovvero quanti numeri primi da 1 a x.
int Primidi(int a)
{
	int b, d, c;
	b = 1;
	d = 0;
	while (b < a)
	{
		b++;
		c = 2;
		while (((b % c) != 0) && (c <= b))
			c++;
		if (c >= b)
		{
			d++;
		}
	}
	return d;
}
//Calcola numero divisori
int numdiv(int a)
{
	if (a < 0)
		a = -a;
	int b, c = 0;
	b = 1;
	while (a >= b)
	{
		if (a % b == 0)
		{
			c++;
			b++;
		}
		else
			b++;
	}
	return c;
}
//Fattoriale
double facto(int a)
{
	if (a > 0)
	{
		int i;
		float b = 1;
		for (i = 1; i <= a; i++)
		{
			b = b * i;
		}
		return b;
	}
}
//Associa funzioni a char dalla forma rpn
float Fun(char a, float x)
{
	/*Trigonometria*/
	if (a == 's')
		return sin(x);
	if (a == 'c')
		return cos(x);
	if (a == 't')
		return tan(x);
	if (a == 'a')
		return asin(x);
	if (a == 'b')
		return acos(x);
	if (a == 'd')
		return atan(x);
	if (a == 'h')
		return sinh(x);
	if (a == 'i')
		return cosh(x);
	if (a == 'j')
		return tanh(x);
	/*Logaritmi*/
	if (a == 'L')
		return log10(x);
	if (a == 'N')
		return log(x);
	if (a == 'D')
		return (log(x)) / (log(2.0));
	/*Varie*/
	if (a == 'A')
		return fabs(x);
	if (a == 'I')
		return (int(x));
	if (a == 'P')
		return Primidi(int(x));
	if (a == '!')
		return facto(int(x));
	if (a == 'V')
		return numdiv(int(x));
	/*Algebra*/
	if (a == 'R')
		return sqrt(x);
	if (a == 'C')
		return pow(float(x), float((1 / 3.0)));
	if (a == 'Q')
		return pow(float(x), float((1 / 5.0)));
}
//Funione a tre parametri char che come risultato rid� il carattere-funzione da mettere nell'rpn
char charfun(char a, char b, char c)
{
	int bo = 0;
	/*Trigonometria*/
	if ((a == 's') && (b == 'i') && (c == 'n'))
	{
		bo++;
		return 's';
	}
	if ((a == 'c') && (b == 'o') && (c == 's'))
	{
		bo++;
		return 'c';
	}
	if ((a == 't') && (b == 'a') && (c == 'n'))
	{
		bo++;
		return 't';
	}
	if ((a == 'a') && (b == 's') && (c == 'i'))
	{
		bo++;
		return 'a';
	}
	if ((a == 'a') && (b == 'c') && (c == 's'))
	{
		bo++;
		return 'b';
	}
	if ((a == 'a') && (b == 't') && (c == 'g'))
	{
		bo++;
		return 'd';
	}
	if ((a == 's') && (b == 'n') && (c == 'h'))
	{
		bo++;
		return 'h';
	}
	if ((a == 'c') && (b == 's') && (c == 'h'))
	{
		bo++;
		return 'i';
	}
	if ((a == 't') && (b == 'a') && (c == 'h'))
	{
		bo++;
		return 'j';
	}
	/*Logaritmi*/
	if ((a == 'l') && (b == 'o') && (c == 'g'))
	{
		bo++;
		return 'L';
	}
	if ((a == 'l') && (b == 'n'))
	{
		bo++;
		return 'N';
	}
	if ((a == 'l') && (b == 'o') && (c == 'd'))
	{
		bo++;
		return 'D';
	}
	/*Varie*/
	if ((a == 'a') && (b == 's') && (c == 's'))
	{
		bo++;
		return 'A';
	}
	if ((a == 'i') && (b == 'n') && (c == 't'))
	{
		bo++;
		return 'I';
	}
	if ((a == 'q') && (b == 'r') && (c == 'm'))
	{
		bo++;
		return 'P';
	}
	if ((a == 'f') && (b == 'a') && (c == 'c'))
	{
		bo++;
		return '!';
	}
	if ((a == 'd') && (b == 'i') && (c == 'v'))
	{
		bo++;
		return 'V';
	}
	/*Algebra*/
	if ((a == 'r') && (b == 'a') && (c == 'd'))
	{
		bo++;
		return 'R';
	}
	if ((a == 'r') && (b == 'a') && (c == 'c'))
	{
		bo++;
		return 'C';
	}
	if ((a == 'r') && (b == 'a') && (c == 'q'))
	{
		bo++;
		return 'Q';
	}
	if (bo == 0)
	{
		return 0;
	}
}
//Controlla se il carattere nello stack � una funzione
int chkfun(char a)
{
	if ((a == 's') || (a == 'c') || (a == 't') || (a == 'a') || (a == 'b') || (a == 'd') || (a == 'h') || (a == 'i') || (a == 'j') ||
		(a == 'L') || (a == 'N') || (a == 'D') ||
		(a == 'A') || (a == 'I') || (a == 'P') || (a == '!') || (a == 'V') ||
		(a == 'R') || (a == 'C') || (a == 'Q'))
	{
		return 1;
	}
	else
		return 2;
}
//Controlla se nella conversione RPN, un carattere � una costante (o una variabile) o un'operatore
int chkchar(char a)
{
	if ((('0' <= a) && (a <= '9')) || (a == 'p') || (a == 'e')) //Il carattere � una cifra o una costante
	{
		return 1;
	}
	if ((a == '+') || (a == '-') || (a == '*') || (a == '/') || (a == '^') || (a == '%')) //Il carattere � un operatore
	{
		return 2;
	}
	else
		return 3;
}
//Controlla la precedenza tra 2 operatori
bool precedence(char op1, char op2)
{
	int first = 0;
	if ((op1 == '+') || (op1 == '-'))
	{
		first = 1;
	}
	if ((op1 == '*') || (op1 == '/') || (op1 == '%'))
	{
		first = 2;
	}
	if ((op1 == '^') || (chkfun(op1) == 1))
	{
		first = 3;
	}
	/*******************/
	int second = 0;
	if ((op2 == '+') || (op2 == '-'))
	{
		second = 1;
	}
	if ((op2 == '*') || (op2 == '/') || (op2 == '%'))
	{
		second = 2;
	}
	if ((op2 == '^') || (chkfun(op2) == 1))
	{
		second = 3;
	}
	if ((first == second) || (first < second))
		return false;
	else
		return true;
}
//Conta le cifre di un numero intero(per la lettura dei numeri decimali)
float numcif(double a)
{
	if (a < 0)
	{
		a = -a;
	}
	double b;
	float c;
	b = log10(a);
	c = ceil(b);
	if (c == b)
	{
		c++;
	}
	if (a == 0)
	{
		c = 1;
	}
	return c;
}
//Controlla se la sintassi dell'espressione � corretta:
int chksyntx(string inf)
{
	inf += "  ";
	//////////////////////////
	int chknmb = 0;
	int par_a = 0, par_c = 0;
	//////////////////////////
	for (int i = 0; i < inf.size(); i++)
	{
		if (chkchar(inf[i]) == 1)
			chknmb++;
		if (inf[i] == '(')
			par_a++;
		if (inf[i] == ')')
			par_c++;
		if ((chkchar(inf[i]) == 2) && (chkchar(inf[i + 1]) == 2))
			return 0;
		if ((i == 0) && (inf[i] == '.'))
			return 0;
		if ((inf[i] == '.') && ((!isdigit(inf[i + 1])) || (!isdigit(inf[i - 1]))))
			return 0;
	}
	//////////////////////////
	if (chknmb == 0)
	{
		return 0;
	}
	if (par_a != par_c)
	{
		return 0;
	}
	///////////////////////////
	//Ritorna 1 se tutto va correttamente...
	return 1;
}
//Data una stringa in notazione infissa, ritorna una stringa con l'espressione in forma RPN
string FoundRPN(char in[])
{
	string rpn = "";
	stack<char> operators; //Dichiaro stack che conterr� gli operatori:
						   /*****************************************************************************/
	int h = 0, chknmbr = 0;
	for (h = 0; h <= 99; h++)
	{
		/* Se il carattere e' un numero, questo viene aggiunto alla fine  
					* della stringa di output. Se il prossimo carattere non e' un 
					* numero, viene aggiunto il simbolo di spazio per la migliore 
					* leggibilita' dell'espressione in output */
		if (chkchar(in[h]) == 1)
		{
			rpn += in[h];

			if ((!isdigit(in[h + 1])) && (in[h + 1] != '.') && (in[h + 1] != ','))
			{
				rpn += " ";
			}
			if ((in[h + 1] == '.') || (in[h + 1] == ','))
			{
				rpn += ".";
			}
			chknmbr++;
		}

		/* Il carattere letto e' un operatore. 
					* 		Se lo stack per gli operatori e' vuoto o il carattere 
					* precedente era la parentesi aperta o l'operatore letto ha
					* una precedenza minore rispetto a quella dell'operatore inserito
					* prima, l'operatore letto viene inserito normalmente nello stack. 
					*		Altrimenti se l'operatore letto ha una precedenza maggiore 
					* rispetto a quella dell'operatore inserito prima, dallo stack 
					* viene tolto l'operatore con la precedenza maggiore e viene messo
					* nella stringa di output. */
		if (chkchar(in[h]) == 2)
		{
			bool usc = false;
			while (usc == false)
			{
				if ((operators.empty()) || (operators.top() == '(') || (precedence(in[h], operators.top())))
				{
					if ((chkchar(in[h - 1]) == 1) || (in[h - 1] == ')'))
						operators.push(in[h]);
					usc = true;
				}
				else if (!precedence(in[h], operators.top()))
				{

					rpn += operators.top();
					rpn += " ";
					operators.pop();
				}
			}
		}
		/* Se il carattere è la s, il successivo è la i e quello ancora è la n, allora c'è la funzione sin:  ecc.....
					La funzione 'charfun': data una serie di tre caratteri, se corrispondono a una funzione, copia il carattere corrispondente 
					alla funzione nello stack*/
		char chf = charfun(in[h], in[h + 1], in[h + 2]);
		if (chf != 0)
			operators.push(chf);
		/* 		Se il carattere letto e' una parentesi aperta, questa viene 
					* messa nello stack.
					* 		Se e' una parentesi chiusa, vuol dire che tutti gli operatori 
					* rimasti nello stack fino alla parentesi aperta vanno copiati nella
					* stringa di output. La parentesi aperta viene cancellata dallo stack
					* e dopo si contunua a leggere la stringa di input */
		if (in[h] == '(')
		{
			operators.push(in[h]);
		}
		/*Se il carattere è il meno e precedentemente non vi è alcun valore, vuol dire che si intende 
					*il negartivo di un valore es:-5, allora sostituisco al '-' ---->  '0-'   */
		if ((in[h] == '-') && (chkchar(in[h - 1]) != 1))
		{
			rpn += '0';
			rpn += ' ';
			operators.push('-');
		}
		if (in[h] == ')')
		{
			while (operators.top() != '(') //In pratica scorre nello stack verso sinistra copiando gli operatori incontrati.
			{
				rpn += operators.top();
				rpn += " ";
				operators.pop();
			}
			operators.pop(); //Cancella la parentesi aperta
		}
	}
	/* Tutti gli operatori rimasti nello stack vanno copiati nella 
					stringa di output e poi cancellati dallo stack */
	while (!operators.empty())
	{
		rpn += operators.top();
		rpn += " ";
		operators.pop();
	}
	//////////////////Eventuale break point per verificare rpn.
	rpn += " ";
	return rpn;
}
//Data una stringa in notazione RPN, ne calcola il valore
float SolveRPN(string rpn)
{
	stack<float> numbers;
	string longNumber = "";
	float result = 0, prev = 0, postv = 0;
	int chkop = 0;
	for (unsigned int h = 0; h < rpn.size(); h++)
	{
		/*Il carattere letto e' un numero. Questo numero viene memorizzato
		* nella stringa di appoggio. 
		* Se il prossimo carattere e' un numero,vuol dire che nella 
		* stringa c'e un numero lungo perche' nella funzione di conversione 
		* dopo ogni numero inserito nella stringa di output veniva messo anche
		* il simbolo di spazio. La prossima cifra del numero sara' aggiunta 
		* alla fine della stringa di appoggio all'aumentare dell'indice. 
		* Se il prossimo carattere non e' un numero, la stringa d'appoggio
		* viene convertita in un numero vero e memorizzata nello stack. */
		if (chkchar(rpn[h]) == 1)
		{
			if (isdigit(rpn[h]))
			{
				longNumber += rpn[h];
			}

			if (rpn[h] == 'e') //sostituisco alla e nell'espressione il valore della costante
			{
				numbers.push(2.71828);
			}

			if (rpn[h] == 'p') //sostituisco alla p nell'espressione il valore della costante
			{
				numbers.push(3.14159);
			}
			//Se il carattere successivo non � una cifra e � diverso dalla virgola:
			if ((!isdigit(rpn[h + 1])) && (rpn[h + 1] != '.') && (rpn[h] != 'e') && (rpn[h] != 'p'))
			{
				numbers.push(atof(longNumber.c_str()));
				longNumber = "";
			}
			if (rpn[h + 1] == '.') //Se il carattere successivo � la virgola:
			{
				numbers.push(atof(longNumber.c_str())); //legge la parte precedente a questa (la parte intera )
				longNumber = "";
				prev = numbers.top();
				numbers.pop();
				int count = 2;
				while (isdigit(rpn[count + h])) //Legge la parte successiva e la memorizza come numero
				{
					longNumber += rpn[h + count];
					count++;
				}
				h = h + count;
				postv = (atof(longNumber.c_str()));
				longNumber = "";
				/*somma la parte precedente a quella successiva 
				fratto 10^il numero di cifre che ha es:
				2.985     prev=2   postv=985
				985 ha tre cifre quindi 985/10^3=0.985
				li sommo e ottengo 2.985*/
				numbers.push(prev + (postv / pow(10, numcif(postv))));
				postv = 0;
				prev = 0;
			}
		}

		if (chkchar(rpn[h]) == 2) //Il carattere � un operatore:
		{
			chkop++; //Controlla se vi � un operatore
			result = numbers.top();
			numbers.pop();
			if (numbers.empty()) //se c'� un operatore all'inizio, � come se ci fosse lo 0 (es.-6=0-6)
			{					 //pertanto aggiungo lo 0
				numbers.push(0.0);
			}
			/*****OPERATORS****************************************/
			switch (rpn[h])
			{
			case '+':
				result = numbers.top() + result;
				break;
			case '-':
				result = numbers.top() - result;
				break;
			case '*':
				result = numbers.top() * result;
				break;
			case '/':
				result = numbers.top() / result;
				break;
			case '^':
				result = pow(numbers.top(), result);
				break;
			case '%': //Operatore modulo
				if (((int)numbers.top() != 0) && ((int)result != 0))
					result = int(numbers.top()) % int(result);
				break;
			}
			numbers.pop();
			numbers.push(result);
		}
		if (chkfun(rpn[h]) == 1) //Se c'� un carattere che corrisponde a una funzione:
		{
			/*La funzione 'Fun', dato un carattere
			*corrispondente a una funzione e un valore 
			*float, ne calcola la funzione corrispondente.*/
			result = Fun(rpn[h], numbers.top());
			numbers.pop();
			numbers.push(result);
		}
	}
	if (chkop == 0) //Se nell'espressione non vi � alcun  operatore, allora vi deve essere un solo numero, perci� lo si associa a result
					//infatti chkop si incrementa se il carattere � un operatore(vedi sopra)
		result = numbers.top();

	return result;
}
/****************************   FINE   ******************************     www.danysoftware.altervista.org   */