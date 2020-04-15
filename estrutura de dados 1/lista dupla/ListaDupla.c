#include <stdio.h>
#include <stdlib.h>

struct noh {
	int value;
	struct noh *prox;
	struct noh *ant;
};

typedef struct noh NOH;

void inserir_inicio(NOH **inicio, int value);
void imprime_lista(NOH *inicio);
void inserir_pos(NOH *inicio , int pos, int value);
void retira_inicio(NOH **inicio);
void retira_pos(NOH *inicio, int pos);
void retira_fim(NOH **inicio);

void inserir_inicio(NOH **inicio, int value)
{
	NOH *novo;
	novo = (NOH*)malloc(sizeof(NOH));
	
	if(novo!=NULL)
	{
		novo->value = value;
		if(*inicio == NULL)
		{
			novo->ant = novo->prox = NULL;
			*inicio = novo;
		}else
		{
			novo->prox = *inicio;
			novo->ant = NULL;
			(*inicio)->ant = novo;
			*inicio = novo;
		}
	}else
	{
		printf("\nerro de alocacao de memoria.\n");
		exit(1);
	}
}

void inserir_pos(NOH *inicio, int pos, int value)
{
	int posAtual;
	NOH *novo = (NOH*)malloc(sizeof(NOH));
	NOH *atual = inicio;
	
	if(novo != NULL)
	{
		posAtual = 0;
		novo->value = value;
		while(posAtual < pos)
		{
			atual = atual->prox;
			posAtual++;
		}
		
		novo->prox = atual;
		novo->ant = atual->ant;
		atual->ant->prox = novo;
		atual->ant = novo;
		
	}
}

void retira_inicio(NOH **inicio)
{
	NOH *atual = *inicio;
	if( atual!= NULL)
	{
		atual->prox->ant = NULL; 
		*inicio = atual->prox;
		free(atual);
	}
	
}

void retira_pos(NOH *inicio, int pos)
{
	int posAtual;
	NOH *atual = inicio;
	
	posAtual=0;
	while(posAtual<pos)
	{
		atual = atual->prox;
		posAtual++;
	}
	
	atual->ant->prox = atual->prox;
	atual->prox->ant = atual->ant;
	free(atual); 
	
}

void imprime_lista(NOH *inicio)
{
	NOH *atual = inicio;
	
	while(atual != NULL)
	{
		printf("<- %d ->", atual->value);
		atual = atual->prox;
	}
}

void retira_fim(NOH **inicio)
{
	
}

main()
{
	NOH *inicio = NULL;
	NOH *fim = NULL;
	printf("Elementos inseridos ao inicio:\n");
	inserir_inicio(&inicio, 4);
	inserir_inicio(&inicio, 3);
	inserir_inicio(&inicio, 1);
	inserir_inicio(&inicio, 0);
	imprime_lista(inicio);
	printf("\nElemento 2 inserido a posicao 2:\n");
	inserir_pos(inicio, 2, 2);
	imprime_lista(inicio);
	printf("\nElemento retirado do inicio:\n");
	retira_inicio(&inicio);
	imprime_lista(inicio); 
	printf("\nElemento 2 retirado da posicao: 1\n");
	retira_pos(inicio, 1);
	imprime_lista(inicio);
	
}


