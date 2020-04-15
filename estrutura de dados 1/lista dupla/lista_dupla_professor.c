#include<stdio.h>

struct noh{
	int valor;
	struct noh* prox;
	struct noh* ant;	
};


typedef struct noh Noh;

void inserir_inicio(Noh** inicio, int valor);
void apresenta_lista(Noh* inicio);
void inserir_pos(Noh* inicio, int pos, int valor);
void remover_inicio(Noh** inicio);
void remover_pos(Noh* inicio, int pos);

main()
{
	Noh* inicio = NULL;
	Noh* fim = NULL;

	inserir_inicio(&inicio, 3);
	inserir_inicio(&inicio, 5);
	inserir_inicio(&inicio, 10);
	inserir_pos(inicio, 1, 4);
	apresenta_lista(inicio);
	remover_inicio(&inicio);
	apresenta_lista(inicio);
	inserir_pos_recursivo(inicio, 0, 1, 20);
//	remover_pos(inicio, 1);
	apresenta_lista(inicio);
	
	
}



void inserir_inicio(Noh** inicio, int valor)
{
	
	Noh* novo;
	
	novo = (Noh*) malloc(sizeof(Noh));
	
	if(novo != NULL)
	{
		novo->valor = valor;
		if(*inicio == NULL)
		{
			novo->ant = novo->prox = NULL;
			*inicio = novo;
		}
		else
		{
			novo->prox = *inicio;
			novo->ant = NULL;
			(*inicio)->ant = novo;
			*inicio = novo;
		}
	}
	else
	{
		printf("\nErro na alocação de memória!");
		exit(1);
	}
	
}

void inserir_pos_recursivo(Noh* inicio,int posAtual, int pos, int valor)
{
	Noh* novo;
	
	if(posAtual < pos)
		inserir_pos_recursivo(inicio->prox, posAtual+1, pos, valor);
	else
	{
		novo = (Noh*) malloc(sizeof(Noh));
		novo->valor = valor;
		novo->prox = inicio;
		novo->ant = inicio->ant;
		inicio->ant->prox = novo;	
		inicio->ant = novo;		
	}						
}

void inserir_pos(Noh* inicio, int pos, int valor)
{
	int posAtual;
	Noh* novo = (Noh*) malloc(sizeof(Noh));
	Noh* atual = inicio;
	
	if(novo != NULL)
	{
		posAtual = 0;
		novo->valor = valor;
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


void remover_inicio(Noh** inicio)
{
	Noh* atual = *inicio;
	Noh* proxAtual;
	if(atual != NULL)
	{
		atual->prox->ant = NULL;
		*inicio = atual->prox;
		free(atual);	
	}	
}

void remover_pos(Noh* inicio, int pos)
{
	int posAtual;
	Noh* atual = inicio;
	posAtual = 0;
	
	while(posAtual < pos)
	{
		atual = atual->prox;
		posAtual++;
	}
	
	atual->ant->prox = atual->prox;
	atual->prox->ant = atual->ant;
	free(atual);
	
}

void apresenta_lista(Noh* inicio)
{
	Noh* atual = inicio;
	printf("\n");
	while(atual != NULL)
	{
		printf("%i ", atual->valor);
		atual = atual->prox;		
	}	
}



