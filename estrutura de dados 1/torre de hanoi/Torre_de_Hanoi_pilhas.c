//Torre de Hanoi usadno pilhas

#include <stdio.h>
#include <stdlib.h>
#define TAM 8 //Quantidade de dsicos

int A[TAM];
int B[TAM];
int C[TAM];

int posA = 0;
int posB = 0;
int posC = 0;

//incremento para torre A
void pushA(int n)
{
	A[posA] = n;
	posA++;
}
//decremento para torre A
int popA()
{
	posA--;
	return A[posA];	
}

//verifica o valor de cima da pilha A
int peekA()
{
	return A[posA-1];
}

//incremento para torre B
void pushB(int n)
{
	B[posB] = n;
	posB++;
}
//decremento para torre B
int popB()
{
	posB--;
	return B[posB];	
}

//verifica o valor de cima da pilha B
int peekB()
{
	return B[posB-1];
}

//incremento para torre C
void pushC(int n)
{
	C[posC] = n;
	posC++;
}
//decremento para torre C
int popC()
{
	posC--;
	return C[posC];	
}

//verifica o valor de cima da pilha C
int peekC()
{
	return C[posC-1];
}

//inicia as torres na condição inicial
void iniciaTorre(){
	int i;
	for(i=TAM;i>=1;i--)
	{
		pushA(i);
	}
	
}

//Funções do algoritimo de resolução da Torre de Hanoi
//Move de A para B
void moveAB()
{
	if(posA == 0) 
	{
		pushA(popB());
				
	}else if (posB == 0)
	{
		pushB(popA());
		
	}else if (peekA() < peekB())
	{
		
		pushB(popA());
		
	}else if (peekB() < peekA())
	{
		
		pushA(popB());
		
	}	 
}

//Move de A para C
void moveAC()
{
	if(posA == 0)
	{
		pushA(popC());
		
	}else if(peekA() < peekC())
	{
		
		pushC(popA());
		
	}else if(peekC() < peekA())
	{
		
		pushA(popC());
		
	}
}

//Move de B para C
void moveBC()
{
	if (posC == 0)
	{
		pushC(popB());	
		
	}else if (peekC() < peekB())
	{
		pushB(popC());
			
	}else if (peekB() < peekC())
	{
		pushC(popB());
		
	}
}

//mostra o conteudo das pilhas  
void showTodos()
{
	int i;
	//imprimindo torre A
	printf("A:");
	for(i=0;i<posA;i++)
	{
		printf("%d", A[i]);
	}
	//imprimindo torre B
	printf("\nB:");
	for(i=0;i<posB;i++)
	{
		printf("%d", B[i]);
	}
	//imprimindo torre C
	printf("\nC:");
	for(i=0;i<posC;i++)
	{
		printf("%d", C[i]);
	}
	printf("\n");
}


int main()
{
	iniciaTorre();
	showTodos();
	while(posC < TAM)
	{
		moveAB();
		if (posC == TAM) break;
		showTodos();
		moveAC();
		if (posC == TAM) break;
		showTodos();
		moveBC();
		showTodos();
	}
	showTodos();
	printf("\n");

}


