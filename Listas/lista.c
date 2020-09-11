#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct lista{
	int conteudo;
	struct lista *next;
};

typedef struct lista node;

void criaLISTA(node *LISTA);
void puchINICIO(node *LISTA, int conteudo);
void puchFIM(node *LISTA, int conteudo);
void puchALEATORIO(node *LISTA, int conteudo, int posi, int TAM);
void imprimeLISTA(node *LISTA);
node *popINICIO(node *LISTA);
node *popFIM(node *LISTA);
node *popALEATORIO(node *LISTA, int TAM, int posi);
node *popALL(node *LISTA);

void main()
{
	node *lista = NULL;
	lista = (node*)malloc(sizeof(node));
	int conteudo;
	int op = 0;
	int TAM;
	int posi = 0;
	criaLISTA(lista);
	
	do{
		printf("\n1-Inserir no inicio.\n");
		printf("2-Inserir pelo fim.\n");
		printf("3-Inserir em qualquer posicao.\n");
		printf("4-Imprimir.\n");
		printf("5-Retira inicio.\n");
		printf("6-Retirar fim.\n");
		printf("7-Retiriar de qualquer posicao.\n");
		printf("0-Sair.\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("\nInicio: ");
				scanf("%d",&conteudo);
				puchINICIO(lista, conteudo);
				TAM++;
			break; 
			
  			case 2:
  				printf("\nFim: ");
  				scanf("%d",&conteudo);
  				puchFIM(lista, conteudo);
  				TAM++;
  			break;
			
			case 3:
				printf("\nInforme onde a posicao que deseja inserir: ");
				scanf("%d",&posi);
				printf("\nInserir: ");
				scanf("%d",&conteudo);
				puchALEATORIO(lista, conteudo, posi, TAM);
				TAM++;
			break;	
			
			case 4:
				printf("\n %d", TAM);
				imprimeLISTA(lista);
			break;
			
			case 5:
				popINICIO(lista);
				TAM--;
			break;	
			
			case 6:
				popFIM(lista);
				TAM--;
			break;
			
			case 7:
				printf("\nEscreva a posicao que deseja retirar: ");
				scanf("%d",&posi);
				popALEATORIO(lista, TAM, posi); 
				TAM--;
			break;
				
			default:
				printf("\nEscreva uma opcao com sentido.\n");
			break;		
		}
	}while(op!=0);
}


void criaLISTA(node *LISTA)
{
	LISTA->next = NULL;
}


void puchINICIO(node *LISTA, int conteudo)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	novoNO->conteudo = conteudo;
	
	node *oldHEAD;
	oldHEAD = LISTA->next;//==NULL
	LISTA->next = novoNO;
	novoNO->next = oldHEAD;	
}


void puchFIM(node *LISTA, int conteudo)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	novoNO->conteudo = conteudo;
	novoNO->next = NULL;
	
	if(LISTA->next==NULL)
	{
		LISTA->next = novoNO;
	}
	else
	{
		node *temp;
		temp = LISTA->next;
		
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = novoNO;
	}
}


void puchALEATORIO(node *LISTA, int conteudo, int posi, int TAM)
{
	int cont;
	
	if(posi>=0 && posi<=TAM)
	{
		if(posi==0)
		{
			puchINICIO(LISTA, conteudo);
		}
		else if(posi==TAM)
		{
			puchFIM(LISTA, conteudo);
		}
		else
		{
			node *atual;
			atual = LISTA->next;
			node *anterior;
			anterior = LISTA;
			node *novoNO;
			novoNO = (node*)malloc(sizeof(node));
			novoNO->conteudo = conteudo;
			
			for(cont=1; cont>TAM; cont)
			{
				anterior = atual;
				atual = atual->next;
			}
			anterior->next = novoNO;
			novoNO->next = atual;
		}
	}
}


void imprimeLISTA(node *LISTA)
{
	node *atual;
	atual = LISTA->next;

	if( LISTA->next == NULL){
		printf("\nA lista esta vazia.\n");	
	}
	else
	{
		printf("\nLista: ");
	}	
	while(atual!=NULL)
		{
			printf("%d -> ",atual->conteudo);
			atual = atual->next;
		}
		printf("NULL\n");
}

node *popINICIO(node *LISTA)
{
	node *temp;
	temp = LISTA->next;
	
	if(temp==NULL)
	{
		printf("\nPilha vazia.\n");
		return NULL;
	}
	else
	{
		LISTA->next = temp->next;
		free(temp);
	}
	return LISTA;
}


node *popFIM(node *LISTA)
{
	node *temp;
	temp = LISTA->next;
	node *anterior;
	anterior = LISTA;
	
	if(temp==NULL)
	{
		printf("\nPilha esta vazia.\n");
	}
	else
	{
		while(temp->next!=NULL)
		{
			anterior = temp;
			temp = temp->next;
		}
		anterior->next = NULL;
		free(temp);
		return anterior;
	}
}


node *popALEATORIO(node *LISTA, int TAM, int posi)
{
	int cont;
	node *temp;
	temp = LISTA->next;
	node *anterior;
	anterior = LISTA;
	
	if(posi>0 && posi<=TAM)
	{
		if(posi==TAM)
		{
			return popFIM(LISTA);
		}
		else if(posi==1)
		{
			return popINICIO(LISTA);
		}
		else
		{
			for(cont=1; cont<posi; cont++)
			{
				anterior = temp;
				temp = temp->next;
			}
			anterior->next = temp->next;
			free(temp);
			return anterior;
		}
	}
}

node *popALL(node *LISTA)
{
	node *temp;
	temp = LISTA->next;
	if(temp==NULL)
	{
		printf("\nPilha vazia.\n");
		return NULL;
	}
	else
	{
		while (temp != NULL)
		{
			LISTA->next = temp->next;
			free(temp);
		}
	}	
}