#include <stdio.h>
#include <stdlib.h>

typedef struct pilha
{
	char *conteudo;
	struct pilha *prox;
}node;

node *puch(node *TOPO, char *conteudo);
node *pop(node *TOPO, char *conteudo);
node *inverte(node *PILHA, char *string);

void main()
{
	char *conteudo = (char*)malloc(sizeof(char)); 
	node *TOPO = NULL;
	
	int op;
	while(op != 0)
	{
		printf("1-PUCH");
		printf("2-POP");
		printf("3-INVERTE");
		printf("0-SAIR");
		scanf("%d",op);
		
		switch(op){
			case 1:
				printf("\nInsira: ");
				scanf("%d",TOPO->conteudo);
				TOPO = puch(TOPO, conteudo);
				break;
			case 2:
				TOPO = pop(TOPO, &conteudo);
				break;
			case 3
				imprime(TOPO);
				break;		
		}
		
	}			
} 

node *puch(node *TOPO, char *conteudo)
{
	node *novoNOH;
	novoNOH = (node*)malloc(sizeof(node));
	if(novoNOH != NULL){
		novoNOH->conteudo = conteudo;
		novoNOH->prox = TOPO;
		TOPO = novoNOH;
		return TOPO;
	}else{
		printf("\nOcorreu erro.\n");
		return NULL;
	}
}

node *pop(node *TOPO, char *string)
{
	node *novoNO;
	novoNO = TOPO;
	*string = TOPO->conteudo;
	TOPO = TOPO->prox;
	free(novoNO);
	return TOPO;
}

void imprime (node *TOPO)
{
	if(TOPO == NULL)
	{
		printf("\nPilha esta vazia.\n");
	}else
	{
		while(TOPO->prox != NULL)
		{
			printf("%d\n", TOPO->conteudo);
			TOPO = TOPO->prox;
		}
	}
}

node *inverte(node *PILHA, char *conteudo)
{
	int i;
	conteudo = (node*)malloc(sizeof(node));
	node *novoNO = NULL;
	
	char texto[4] = "ABCD";
	char texto1[4] = "DCBA";
	
	for(i=0;i<3;i++)
	{
		novoNO->conteudo = texto[i];
		novoNO = novoNO->prox; 
	}
	
	while(novoNO->prox != NULL)
	{
		for(i=0;i<3;i++)
		{
			if(novoNO->conteudo == texto1[1]){
				pop(novoNO, &conteudo);
			}
		}
	}

} 
