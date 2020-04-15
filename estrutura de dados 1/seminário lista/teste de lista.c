//testando lista encadeada
/*Eu quero que esse programa seja uma lista, ou seja tenha uma funçao
GETNODE e uma funçao FREENODE para incluir um nó e excluir um nó 
repectivamente. Quero que criar uma lista de telefones ou cpfs */

#include <stdio.h>
#include <stdlib.h>
	
struct list{
	int conteudo;
	struct list *prox;
};

typedef struct list celula; //tipo de dado criado "celula"

celula c;
celula *p;
celula *le;

void iniciaLista()
{
	celula *le;
	le = malloc (sizeof(celula));
	le->prox = NULL;
} 

int listaVazia(int *inicioCel)
{
	if(inicioCel == NULL)
		return(1);
		else return(0);
}

void imprime(celula *le)//imprime celula 
{
	if(le != NULL){
		printf("%d \n", le->conteudo);
		imprime(le->prox);
	}
}

void imprimeLista(celula *le)
{
	celula *p;
	for (p = le->prox; p != NULL; p = p->prox)
		printf("%d\n", p->conteudo);
}

void main()
{
	
	celula *inicioCelula;
	celula *proximoCelula;
	
	inicioCelula = (celula *)malloc(sizeof(celula));
	
	if(inicioCelula == NULL)
		printf("ERRO de alocacoa.\n");
		
	proximoCelula = inicioCelula;
	
	
}



