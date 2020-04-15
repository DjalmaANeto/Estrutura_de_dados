#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int conteudo;
	struct NODE *next;
};
typedef struct NODE node;


//assinaturas das funçoes
void cria_lista(node *LISTA);
int listaVazia(node *LISTA);
void insere_inicio(node *LISTA);
void insereFim(node *LISTA);
void imprimeLista(node *LISTA);
void libera_lista(node *LISTA);
node *retira_inicio(node *LISTA);
node *retira_fim(node *LISTA);
node *iverte_lista(node *LISTA);
node *concatena_lista(node *LISTA);
node *retira_repeticao(node *LISTA);
node *copia_lista(node *LISTA);

void cria_lista(node *LISTA)
{
	LISTA->next = NULL;
}


int listaVazia(node *LISTA)
{
	if(LISTA->next == NULL)
		return 1;
	else 
		return 0;	
}


void insereInicio(node *LISTA)
{
	node *novoNO = (node *) malloc(sizeof(node));
	
	if(!novoNO)
		printf("Problema ao alocar memoria.\n");
		
	printf("Novo elemento ao inicio: ");
	scanf("%d", &novoNO->conteudo);
	
	node *oldHead = LISTA->next;
	LISTA->next = novoNO;
	novoNO->next = oldHead;
}


void insereFim(node *LISTA)
{
	node *novoNO = (node *) malloc(sizeof(node));
	
	if(!novoNO)
		printf("Problema ao alocar memoria.\n");
	
	printf("Novo elemento ao final: ");
	scanf("%d", &novoNO->conteudo);
	novoNO->next = NULL;
	
	if(listaVazia(LISTA))
	{
		LISTA->next=novoNO;
		
	}else
	{
		node *temp = LISTA->next;
		while(temp->next != NULL){
			temp = temp->next;	
		}
		temp->next=novoNO;	
	}	
}


void imprimeLista(node *LISTA)
{
	if(listaVazia(LISTA))
		printf("\nLista vazia.\n");
		
	node *temp;
	temp = LISTA->next;
	
	printf("\n");
	while(temp != NULL)
	{
		printf("%d -> ", temp->conteudo);
		temp = temp->next;
	}	
	printf("\n\n");
}


void libera_lista(node *LISTA)//gera erro na impressao da lista após libera-la, retorna lixo em loop infinito ou retorna um elemento em loop infino se preechida.
{
	if(!listaVazia(LISTA))
	{
		node *proxNo, *atualNo;
	
		atualNo = LISTA->next;
		
		while(atualNo != NULL)
		{
			proxNo = atualNo->next;
			atualNo = proxNo;
			free(atualNo);
		}
		
	}
	
}


node *retira_inicio(node *LISTA)
{
	node *exluidoNO;
	
	if(listaVazia(LISTA))
	{
		printf("\nLista vazia\n");
		return NULL;

	}else
	{
		node *temp = LISTA->next;
		LISTA->next = temp->next;
		exluidoNO = temp;
		free(temp);
		return exluidoNO;
	}
		
}


node *retira_fim(node *LISTA)
{
	node *exluidoNO;
	
	if(listaVazia(LISTA))
	{
		printf("\nLista vazia.\n");
		return NULL;
			
	}else
	{
		node *ultimoNO =  LISTA->next;
		node *penultimoNO = LISTA;
		
		while(ultimoNO->next != NULL)
		{
			penultimoNO = ultimoNO;
			ultimoNO = ultimoNO->next;
		}
		
		penultimoNO->next = NULL;
		exluidoNO = ultimoNO;
		free(ultimoNO);
		
		return exluidoNO;
	}
}


node *copia_lista(node *LISTA)
{
	node *temp = (node*)malloc(sizeof(node));
	node *copia;
	
	temp = LISTA->next;
	copia = LISTA;
	copia->next = temp;
	
	while(temp->next != NULL)
	{
		copia->next = temp;
		temp = temp->next;
	} 
	
	return copia;
}


node *iverte_lista(node *LISTA)
{
	node *invert = (node*)malloc(sizeof(node));
	cria_lista(invert);
	
	node *copia = (node*)malloc(sizeof(node));
	copia = copia_lista(LISTA);
	
	node *oldHead = copia;
	
	while(copia->next != NULL)
	{
		oldHead = copia->next;
		invert->next = oldHead;
		copia = copia->next;
	}
	
	return invert;
}

/*
node *iverte_lista(node *LISTA)
{
	if(listaVazia(LISTA)){
		printf("\nLista vazia.\n");
		return NULL;
	}else{
		
		node *invertNO = (node*)malloc(sizeof(node));
		node *temp = LISTA->next;
		node *oldHead = LISTA;
		
		while(temp->next != NULL)//invertNO esta recebendo o ultimo elemento de temp e colocando como primeiro, mas não esta encadeando o restante da lista 
		{
		//entrar por tras
			oldHead = temp->next;
			oldHead = temp;
			invertNO = oldHead;	
			temp = temp->next;
		}
		return invertNO;
	} 
}
*/

node *concatena_lista(node *LISTA)//esta função esta criando a lista concatenaNo que deveria concatenar à copia da lista, no entanto a lista LISTA esta sendo concatenada e retornada da função 
{
	int op2;
	
	if(listaVazia(LISTA))
	{
		printf("\nLista vazia.\n");
		return NULL;
	}else{
		
		node *copiaLISTA;
		copiaLISTA = (node*)malloc(sizeof(node));
		node *temp = LISTA;
		
		copiaLISTA = temp->next;
		while(temp->next!=NULL)//copia lista LISTA
		{
			//entrar por tras 
			//copiaLISTA = (node*)malloc(sizeof(node));
			copiaLISTA->conteudo = temp->conteudo;
			temp = temp->next;
			copiaLISTA->next = temp;	
		}	
		
		node *concatenadaNO = (node*)malloc(sizeof(node));
		cria_lista(concatenadaNO);
		
		do{
			printf("Informe onde quer inserir o seu elemento:\n");
			printf("\t1-no inicio\n");
			printf("\t2-no meio\n");
			printf("\t3-no final\n");
			printf("\t0-outra opcao.\n");
			scanf("%d",&op2);
				
			switch(op2)
			{
				case 1:
				insereInicio(concatenadaNO);
				break;
						
				case 2:
				printf("b\n");
				break;
						
				case 3:
				insereFim(concatenadaNO);
				break;	
			}
		}while(op2!=0);
		
		node *temp2 = copiaLISTA->next;
		
		while(temp2->next!=NULL){
			temp2 = temp2->next;
		}
		temp2->next = concatenadaNO->next;
		
		return temp2;
		
	}
}

/*
Retira ocorrencia de x
*/
node *retira_repeticao(node *LISTA)//acontece erro
{
	int retirar;
	
	printf("Escreva o elemento que quer retirar: ");
	scanf("%i",&retirar);
	
	node *ultimo = LISTA->next;
	node *penultimo = LISTA;
	
	do{
		
		penultimo = ultimo;
		if(ultimo->conteudo == retirar)
		{
			node *temp = ultimo->next;
			penultimo->next = temp->next;
			free(ultimo);
		}
		penultimo = penultimo->next;
		
	}while(ultimo->next != NULL);
}

int main(void){
	
	node *LISTA = (node*)malloc(sizeof(node));//alocando local para lista
	cria_lista(LISTA);//criando lista

	node *COPIA = (node*)malloc(sizeof(node));//alocando local para lista
	cria_lista(COPIA);//criando lista
	
	node *invertLISTA = (node*)malloc(sizeof(node));
	cria_lista(invertLISTA);

	node *concatenaLISTA = (node*)malloc(sizeof(node));
	cria_lista(concatenaLISTA);
	
	int op, op2, op3, op4;
	
	do{
		
		printf("Escreva a opcao desejada: \n");
		printf("\t1-Inserir novo elemento.\n");
		printf("\t2-Imprimir lista. \n");
		printf("\t3-Inverter lista. \n");
		printf("\t4-Concatena lista. \n");
		printf("\t5-Retirar elemento.\n");
		printf("\t6-Retirar elemento repetido.\n");
		printf("\t7-Limpar lista.\n");
		printf("\t0-Sair.\n");
		scanf("%d",&op);
		
		switch(op)
		{
			case 1:
				do{
					printf("Informe onde quer inserir o seu elemento:\n");
					printf("\t1-no inicio\n");
					printf("\t2-no meio\n");
					printf("\t3-no final\n");
					printf("\t0-outra opcao.\n");
					scanf("%d",&op2);
				
					switch(op2)
					{
						case 1:
							insereInicio(LISTA);
						break;
						
						case 2:
							printf("b\n");
						break;
						
						case 3:
							insereFim(LISTA);
						break;	
					}
				}while(op2!=0);
			break;
			
			case 2:
				do{
					printf("\t1-imprime lista.\n");
					printf("\t2-imprime lista invertida.\n");
					printf("\t3-imprime lista concatenada.\n");
					printf("\t0-outra opcao.\n");
					scanf("%d",&op3);
				
					switch(op3)
					{
						case 1:
							imprimeLista(LISTA);
						break;
						
						case 2:
							imprimeLista(invertLISTA);
							//imprimeLista(invertLISTA);
						break;
						
						case 3:
							imprimeLista(concatenaLISTA);
						break;	
					}
				}while(op3!=0);
				
			break;
			
			case 3:
				COPIA = copia_lista(LISTA);
				invertLISTA = iverte_lista(COPIA);
				//invertLISTA = iverte_lista(LISTA);
			break;
			
			case 4:
				concatenaLISTA = concatena_lista(LISTA);
			break;
			
			case 5:
				do{
					printf("Informe onde quer excluir o seu elemento:\n");
					printf("\t1-do inicio\n");
					printf("\t2-do meio\n");
					printf("\t3-do final\n");
					printf("\t0-Outra opcao.\n");
					scanf("%d",&op4);
				
					switch(op4)
					{
						case 1:
							retira_inicio(LISTA);
						break;
						
						case 2:
							printf("b\n");
						break;
						
						case 3:
							retira_fim(LISTA);
						break;	
					}
				}while(op4!=0);
			break;
			
			case 6:
				retira_repeticao(LISTA);
			break;						
			
			case 7:
				libera_lista(LISTA);
			break;						
		}
		
	}while(op!=0);
	
}
