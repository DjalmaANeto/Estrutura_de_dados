//ESTRUTURA BÁSICA DE PILHA
#include <stdio.h>
#include <stdlib.h>

struct pilha{
	char string[100];
	struct pilha *next;
};

typedef struct pilha node;

node *PUCH(node *TOP, char string[100]);
void imprime(node *TOP);
node *POP(node *TOP, char *string[100]);

void main()
{
	node *TOPO = NULL;
	int op;
	char string[100];
	
	do
	{
		printf("1-PUCH\n");
		printf("2-POP\n");
		printf("3-IMPRIMIR\n");
		printf("0-SAIR\n");
		scanf("%d",op);
		switch(op)
		{
			case 1:
				printf("Insira string: ");
				scanf("%c",&string[100]);
				TOPO = PUCH(TOPO,string);
				break;
			case 2:
				printf("POP feito.\n");
				TOPO = POP(TOPO, &string[100]);
				break;
			case 3:
				imprime(TOPO);
				break;			
		}
	}while(op!=0);	
}

node *PUCH(node *TOP, char string[100])
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	
	if(novoNO != NULL)
	{
		novoNO->string[100] = string[100];
		novoNO->next = TOP;
		TOP = novoNO;
		return TOP;
	}
	else
	{
		printf("\nproblemas durante a alocacao.");
		return NULL;
	}
}

void imprime(node *TOP)
{
	if(TOP==NULL)
	{
		printf("\nPilha vazia.\n");
	}
	else
	{
		printf("\nPilha:\n");
	}
	while(TOP->next!=NULL)
	{
		printf("%d",TOP->string);
		TOP=TOP->next;
	}
	printf("NULL");
}

node *POP(node *TOP, char *string[100])
{
	node *temp;
	temp = TOP;
	*string[100] = TOP->string[100];
	TOP = TOP->next;
	free(temp);
	return TOP;
}

