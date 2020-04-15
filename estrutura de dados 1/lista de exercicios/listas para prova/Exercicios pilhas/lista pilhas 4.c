#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
	int conteudo;
	struct pilha *prox;
}node;

node *imprime(node *TOPO);
node *puch(node *TOPO, int conteudo);
node *pop(node *TOPO, int *conteudo);

void main()
{
	node *TOPO = NULL;
	int op=0, contI=0;
	int conteudo;
	
	do{
		printf("\n1-insercao");
		printf("\n2-exclusao");
		printf("\n3-impressao");
		printf("\n0-sair\n");
		scanf("%d",&op);
		if(op>3||op<0)
		printf("\nEscreva uma opcao com sentido.");
		
		switch(op){
			case 1:
				printf("\nInsira o elemento que deseja adicionar: ");
				scanf("%d",&conteudo);
				TOPO = puch(TOPO, conteudo);
				contI++;
				break;
			case 2:
				TOPO = pop(TOPO, &conteudo);
				break;
			case 3:
				printf("\nLista:\n");
				imprime(TOPO);
				printf("\nPossiveis %d oporacoes de exclusao.", contI);
				
				break;		
		}
			
	}while(op!=0);
	
}

node *imprime(node *TOPO)
{
	if(TOPO == NULL){
		printf("\nPilha esta vazia.\n");
	}else{
		while(TOPO->prox != NULL){
			printf("%d\n", TOPO->conteudo);
			TOPO = TOPO->prox;
		}
	}
}

node *puch(node *TOPO, int conteudo)
{
	node *novoNOH;
	novoNOH = (node*)malloc(sizeof(node));	
	
	if(novoNOH != NULL){
		novoNOH->conteudo = conteudo;
		novoNOH->prox = TOPO;
		TOPO = novoNOH;
		return TOPO;
	}else{
		printf("\nNao foi possivel criar novoNOH\n");
		return NULL;
	}
}

node *pop(node *TOPO, int *conteudo)
{
	node *temp;
	temp = TOPO;
	*conteudo = TOPO->conteudo;//nao entendi esse ponteiro *conteudo
	TOPO = TOPO->prox;
	free(temp);
	return TOPO;
}

//#######################################################################################################################################################################################

//exercicio 5 

typedef struct pilhaC{
	char *string;
	struct pilhaC *proxC;
}nodeC;

node *inverte(node *PILHA, char *string);
node *inverte(node *PILHA, char *string)
{
	int i;
	string = (nodeC*)malloc(sizeof(nodeC));
	nodeC *novoNO = NULL;
	
	char texto[4] = "ABCD";
	char texto1[4] = "DCBA";
	
	for(i=0;i<3;i++)
	{
		novoNO->string = texto[i];
		novoNO = novoNO->proxC; 
	}
	
	while(novoNO->proxC != NULL)
	{
		for(i=0;i<3;i++)
		{
			if(novoNO->string == texto1[1]){
				pop(novoNO, &string);
			}
		}
	}

} 
