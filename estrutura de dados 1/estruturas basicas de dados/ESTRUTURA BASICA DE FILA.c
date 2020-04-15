//ESTRUTURA BASICA DE LISTA
#include <stdio.h>
#include <stdlib.h>

struct fila{
	int conteudo;
	struct fila *next;	
};

typedef struct fila node;

void CRIAfila(node **INICIO, node **FIM, int conteudo);
node *PUCHfila(node *FIM, int conteudo);
node *POPfila(node *INICIO);
void IMPRIMEfila(node *INICIO);

void main()
{
	node *inicio = NULL;
	node *fim = NULL;
	int conteudo = NULL, op;
	
	do{
		printf("\n1-Enfilera\n");
		printf("2-Desenfilera\n");
		printf("3-Imprime\n");
		printf("0-Sair\n");
		scanf("%d",&op);
		printf("\n");
		switch(op){
			case 1:
				printf("\nEnfilere: ");
				scanf("%d",&conteudo);
				if(inicio==NULL)
				{
					CRIAfila(&inicio, &fim, conteudo);
				}
				else
				{
					fim = PUCHfila(fim, conteudo);
				}	
				break;
			case 2:
				if(inicio!=NULL)
				{
					inicio = POPfila(inicio);
				}
				break;
			case 3:
					IMPRIMEfila(inicio);
				break;
			default:
				printf(" escreva algo valido.\n");
				break;	
		}
	}while(op!=0);	
}


void CRIAfila(node **INICIO, node **FIM, int conteudo)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	
	if(novoNO!=NULL)
	{
		novoNO->conteudo = conteudo;
		novoNO->next = NULL;
	}
	
	*INICIO = novoNO;
	*FIM = novoNO;
}

node *PUCHfila(node *FIM, int conteudo)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	
	if(novoNO!=NULL)
	{
		novoNO->conteudo = conteudo;
		novoNO->next = NULL;
		FIM->next = novoNO;
		return novoNO;
	}
	else
	{
		printf("\nErro ao alocar memoria.\n");
		return NULL;
	}
}

node *POPfila(node *INICIO)
{
	node *TEMP;
	if(INICIO!=NULL)
	{
		TEMP = INICIO;
		INICIO = INICIO->next;
		free(TEMP);
		return INICIO;
	}
}

void IMPRIMEfila(node *INICIO)
{
	node *atual = INICIO;
	if(INICIO == NULL)
		printf("\nFila esta vazia.\n");
		
	while(atual != NULL)
	{
		printf("%d->",atual->conteudo);
		atual = atual->next;
	}
	printf("\n");
}

