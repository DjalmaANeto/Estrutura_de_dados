#include <stdio.h>
#include <stdlib.h>

struct elemento{
	int info;
	struct elemento *next;
};

typedef struct elemento *lista;
typedef struct elemento elem;

lista *li;//esse ponteiro vai representar o topo da lista

lista cria_lista();
lista cria_lista()//funcao cria a lista retornando uma lista vazia
{
	lista* li = (lista *)malloc(sizeof(lista));
	if(li != NULL)
		*li=NULL;
	return li;		
}
//chamada da funcao: li = cria_lista();

void libera_lista(lista* li);
void libera_lista(lista *li)//funcao libera toda a lista
{
	if(li != NULL)
	{
		elem* no;
		while((*li) != NULL)
		{
			no = *li;
			*li = (*li)->next;
			free(no);	
		}
		free(li);	
	}
}
//chamada da funcao: libera_list(li);

int tamanho_lista(lista* li);
int tamanho_lista(lista* li)//funcao para contar o tamanho da lista
{
	int cont = 0;
	if(li == NULL)
		return 0;
	elem* no = *li;//crie um auxiliar que "segure" a ponta da lista para ser percorrida sem perder seu inicio
	while(no != NULL)
	{
		cont++;
		no = no->next;
	}
	return cont;
}
//chamda/uso da funcao int x = tamanho_lista(lista li); 

int lista_vazia(lista* li);
int lista_vazia(lista* li)
{
	if(li==NULL)
		return 1;
	if(*li == NULL)
		return 1;
		else return 0;		
}
//chamda/uso da funcao int x = lista_vazia(lista* li); 
 
int insere_inicio_lista(lista* li, int info);
int insere_inicio_lista(lista* li, int info)//funcao pra inserir uma info no inico da lista. Obs.: retorna 0 se encontra erro de alocação(ex.: lista vazia)  
{
	if(li == NULL)
		return 0;
	elem *no = (elem *)malloc(sizeof(elem));	
	if(no == NULL)
		return 0;	
	no->info = info;
	no->next = (*li);
	*li = no;
	return 1;	
}
 //chamda/uso da funcao int x = insere_inicio_lista(lista* li, elem info);
 
int insere_final_lista(lista* li, int info);
int insere_final_lista(lista* li, int info)//funcao pra inserir uma info no final da lista. Obs.: retorna 0 se encontra erro de alocação(ex.: lista vazia)  
{
	if(li == NULL)
		return 0;
	elem *no = (elem *)malloc(sizeof(elem));	
	if(no == NULL)
		return 0;	
	no->info = info;
	no->next = NULL;
	if((*li)==NULL)
	{
		*li = no;
	}else
	{
		elem *aux = *li;
		while (aux->next != NULL)
		{
			aux = aux->next;	
		}
		aux->next = no;
	} 
	return 1;	
}
 //chamda/uso da funcao int x = insere_final_lista(lista* li, elem info);
 
int insere_ordenada_lista(lista* li, int info);
int insere_ordenada_lista(lista* li, int info)//funcao pra inserir uma info na lista vazia de forma ordenada. Obs.: retorna 0 se encontra erro de alocação(ex.: lista vazia)  
{
	if(li == NULL)
		return 0;
	elem *no = (elem *)malloc(sizeof(elem));	
	if(no == NULL)
		return 0;	
	no->info = info;
	if(lista_vazia(li)) //insere inicio
	{
		no->next = (*li);
		*li = no;
		return 1;
	}else
	{
		elem *ant, *atual = *li;
		while(atual != NULL)
		{
			ant = atual;
			atual = atual->next;			
		}
		if(atual == *li && atual->info < info)
		{
			no->next = (*li);
			*li = no;
		}else
		{
			no->next = ant->next;
			ant->next = no;
		}
	} 
	return 1;	
} 
//chamda/uso da funcao int x = insere_ordenada_lista(lista* li, elem info);

int remove_inicio_lista(lista* li);
int remove_inicio_lista(lista* li)
{
	if(li == NULL)
		return 0;
	if((*li) == NULL)
		return 0;
	
	elem *no = *li;
	*li = no->next;
	free(no);
	return 1; 	
}
 
void main(){
	
	
	
}
