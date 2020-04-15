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
int remove_inicio_lista(lista* li)//funcao remove o primeiro item da lista 
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
//chamada/uso da funcao: int x = remove_inicio_lista(li)
 
 int remove_final_lista(lista* li);
 int remove_final_lista(lista* li)//funcao remove o final da lista	
 {
 	if(li==NULL)
 		return 0;
	if((*li) == NULL)
		return 0;
	elem *ant, *no = *li;
	while(no->next != NULL)
	{
		ant = no;
		no = no->next;
	} 	 	
	if(no == (*li))
		*li = no->next;
	else
		ant->next = no->next;
	free(no);
	return 1;		
 }
 
 int remove_qualquer_lista(lista* li, int qualquer);
 int remove_qualquer_lista(lista* li, int qualquer)//funcao remove um qualquer da lista
 {
 	if(li == NULL)
	 	return 0;
 	
 	elem *ant, *no = *li;
	 while(no != NULL && no->info != qualquer)
	 {
	 	ant = no;
	 	no = no->next;
	 } 
 	if(no == NULL)
 		return 0;
 	if(no == *li)
	 	*li = no->next;	
	else 
		ant->next = no->next;
	free(no);
	return 1;	 	
 }
 
 /*
 void imprime_lista(lista *li);
 void imprime_lista(lista *li)
 {
 	system("clear");
 	if(lista_vazia(li)==1)
	 	printf("\nLista vazia.\n\n");
		 
	lista *temp;
	
	temp = li->next;
	printf("\nLista: ");
	
	while(temp != NULL)
	{
		printf("%d -> ", temp->info);
		temp = temp->next;	
	}	 	
 }
 */
 
void main(void)
{	
	int op;
	int info;

	lista *li = (lista *)malloc(sizeof(lista));
	
	if(!li)
		printf("\nSem memoria disponivel.\n");
	else 
		cria_lista(li);
	do{
		printf("Escreva:\n");
			printf("\t1-para inserir um numero ao inicio da lista.\n");
			printf("\t2-para inserir um numero no final da lista.\n");
			printf("\t3-para inserir um numero de forma ordenada a lista.\n");
			printf("\t4-para retirar um numero do inico da lista.\n");
			printf("\t5-para retirar um numero do final da lista.\n");
			printf("\t6-para retirar um numero qualquer da lista.\n");
			printf("\t7-para retirar todos os numeros da lista.\n");
			printf("\t8-para imprimir a lista.\n");
			printf("\t9-para sair.\n");
			scanf("%d",&op);
			if(op<1 || op>9)
				printf("Escreva uma opcao valida.\n");	
	
	
		switch(op){
				case 1:
					printf("\nNovo elemento no inicio: ");
					scanf("%d", &info);
					insere_inicio_lista(li,info);
				break;	
				
				case 2:
					printf("\nNovo elemento no final: ");
					scanf("%d", &info);
					insere_final_lista(li,info);
				break;	
				
				case 3:
					printf("\nNovo elemento de forma ordenada: ");
					scanf("%d", &info);
					insere_ordenada_lista(li,info);
				break;
					
				case 4:
					printf("\nRetira um elemento do inicio: ");
					remove_inicio_lista(li);
				break;
				
				case 5:
					printf("\nRetira um elemento do final: ");
					remove_final_lista(li);
				break;
				
				case 6:
					printf("\nRetira um elemento qualquer: ");	
					scanf("%d", &info);
					remove_qualquer_lista(li,info);
				break;
				
				case 7:
					printf("\nLimpando a lista.");
					libera_lista(li);
				break;
				
				case 8:
					printf("\nImprime a lista: ");
					
				break;			
			}
	
	}while(op!=9);
}
