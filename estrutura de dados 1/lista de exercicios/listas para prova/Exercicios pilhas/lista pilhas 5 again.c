#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pilha{
	char string[4];
	struct pilha *prox;
}node;

node *push(node *TOPO, char *string);
node *pop(node *TOPO, char *string);
node *iverte(node *TOPO, char *string);
node *imprime(node *TOPO);

void main()
{
	char string[4] = "ABCD";
	char elemento[4];
	node *topo = NULL;
	int op;
	
	while(op!=0){
		printf("1-PUCH\n");
		printf("2-POP\n");
		printf("3-INVERTE ABCD\n");
		printf("4-Imprimir\n");
		printf("0-SAIR\n");
		scanf("%d",op);		
	switch(op){
			case 1:
				printf("\nInsira: ");
				scanf("%c",&elemento);
				topo = push(topo, elemento);
				break;	
			case 2:
				topo = pop(topo,elemento);
				break;
			case 3:
				iverte(topo, string);
				break;		
			case 4:
				imprime(topo);
				break;
		}	
	}
}

node *push(node *TOPO, char *string)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	string = (char*)malloc(sizeof(char));
	
	if(novoNO != NULL){
		novoNO->string[4] = string;
		novoNO->prox = TOPO;
		TOPO = novoNO;
	}else{
		printf("\nERRO\n");
	}
}

node *pop(node *TOPO, char *string)
{
	string = (char*)malloc(sizeof(char));
	node *temp;
	temp = TOPO;
	*string = TOPO->string;
	TOPO = TOPO->prox;
	free(temp);
	return TOPO;
}

node *iverte(node *TOPO, char *string)
{
	TOPO->prox = NULL;
	string = (node*)malloc(sizeof(node));
	int i=0;
	
	for(i=0;i<4;i++){
		TOPO->string[i] = string[i];
		TOPO = TOPO->prox;
	}
	return TOPO;
}

node *imprime(node *TOPO)
{
	if(TOPO == NULL){
		printf("\nValor invalido, pilha vazia");
	}else{
		printf("\nPilha:\n");
	}
	while(TOPO!=NULL){
		printf("%d\n",TOPO->string);
		TOPO=TOPO->string;
	}
	printf("NULL");
}

