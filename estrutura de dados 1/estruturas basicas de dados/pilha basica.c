//ESTRUTURA BASICA DE UMA PILHA 
#include <stdio.h>
#include <stdlib.h>

//PILHA
typedef struct pilha
{
	int conteudo;
	struct pilha *next;
}node;  
//FUNÇOES PILHA
int VAZIA(node *TOP);
node *PUCH(node *TOP, int conteudo);
node *POP(node *TOP, int conteudo);
//node *POPaleatorio(node *TOP, int conteudo, int item);
void IMPRIME(node *TOP);

//FILA
typedef struct fila
{
	int conteudo;
	struct fila *next;
}nodef;
//FUNCOES FILA
void criaFILA(nodef **INICIO, nodef **FIM, int conteudo);
nodef *PUCHfila(nodef *FIM, int conteudo);
nodef *POPfila(nodef *INICIO);
void IMPRIMEfila(nodef *INICIO);

//LISTA
typedef struct lista{
	int conteudo;
	struct lista *next;
}nodel;
//FUNCOES LISTA
void INICIAlista(nodel *LISTA);
void insere(nodel *LISTA, int conteudo, int posi, int TAM);
void insereINICIO(nodel *LISTA, int conteudo);
void insereFINAL(nodel *LISTA, int conteudo);
void IMPRIMElista(nodel *LISTA);
nodel *POPlista(nodel *LISTA, int conteudo, int posi, int TAM);
nodel *POPinicio(nodel *LISTA, int conteudo);
nodel *POPfinal(nodel *LISTA, int conteudo);

void main()
{
	//PILHA
	node *pilha = NULL;	
	
	
	//FILA
	nodef *filaINICO = NULL;
	nodef *filaFIM = NULL;
	
	//LISTA
	nodel *lista = NULL;
	int posi=0, TAM=0;
	
	int conteudo;
	int op=0, superop=0; 
	do{
		printf("\n1-Pilha.\n");
		printf("2-Fila\n");
		printf("3-Lista\n");
		printf("0-Sair\n");
		scanf("%p",&superop);
		switch(superop)
		{
			case 1:
				do{
					printf("\n1-PUCH\n");
					printf("2-POP\n");
					printf("3-IMPRIME\n");
					printf("0-outra op\n");
					scanf("%d",&op);
					switch(op)
					{
						case 1:
							printf("\nEmpilhe placa: ");
							scanf("%d",&conteudo);
							pilha = PUCH(pilha, conteudo);
						break;
						
						case 2:
							printf("\nDesempilhando...");
							pilha = POP(pilha, conteudo);			
						break;
						
						case 3:
							IMPRIME(pilha);
						break;
						
						default: 
							printf("\nEscreva uma opcao com sentido.\n");
						break;		
					}
				}while(op!=0); 
			break;
			
			case 2:
				do{
					printf("\n1-PUCH na fila\n");
					printf("2-POP na fila\n");
					printf("3-IMPRIME fila\n");
					printf("0-outra op\n");
					scanf("%d",&op);
					switch(op)
					{
						case 1:
							printf("\nEnfilere: ");
							scanf("%d",&conteudo);
							if(filaINICO == NULL)
							{
								criaFILA(&filaINICO, &filaFIM, conteudo);
							}
							else
							{
								filaFIM = PUCHfila(filaFIM, conteudo);
							}
						break;
						
						case 2:
							printf("\nDesenfilerando...");
							filaINICO = POPfila(filaINICO);
						break;
						
						case 3:
							IMPRIMEfila(filaINICO);
						break;
						
						default: 
							printf("\nEscreva uma opcao com sentido.\n");
						break;		
					}
				}while(op!=0); 
			break;
			
			case 3:
				do{
					void INICIAlista(nodel *LISTA);
					printf("\n1-PUCH inicio \n");
					printf("2-PUCH final \n");
					printf("3-PUCH qualquer posição\n");
					printf("4-POP inicio\n");
					printf("5-POP final\n");
					printf("6-POP aleatorio na lista\n");
					printf("7-IMPRIME\n");
					printf("0-outra op\n");
					scanf("%d",&op);
					switch(op)
					{
						case 1:
							printf("\nInsere inicio: ");
							scanf("%d",&conteudo);
							insereINICIO(lista, conteudo);
							TAM++;
						break;
						
						case 2:
							printf("\nInsere final: ");
							scanf("%d",&conteudo);
							insereFINAL(lista, conteudo);
							TAM++;
						break;
						
						case 3:
							printf("\nInsere: ");
							scanf("%d",&conteudo);
							printf("\nPosicao: ");
							scanf("%d",&posi);
							insere(lista, conteudo, posi, TAM);
							TAM++;
						break;
						
						case 4:
							printf("\nRetirando inicio...");
							lista = POPinicio(lista, conteudo);
							TAM--;
						break;
						
						case 5:
							printf("\nRetirando fim...");
							lista = POPfinal(lista, conteudo);
							TAM--;
						break;
						
						case 6:
							printf("\nposicao: ");
							scanf("%d",&posi);
							lista = POPlista(lista, conteudo, posi, TAM);
							printf("\nRetirando...");
							TAM--;
						break;
						default: 
							printf("\nEscreva uma opcao com sentido.\n");
						break;		
					}
				}while(op!=0);
			break;	
		}
	}while(superop!=0);
	
}

//INICIO DAS FUNCOES PILHA
int VAZIA(node *TOP)
{
	if(TOP->next == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

node *PUCH(node *TOP, int conteudo)
{
	node *novoNO;
	novoNO = (node*)malloc(sizeof(node));
	
	if(novoNO != NULL)
	{ 
		novoNO->conteudo = conteudo;
		novoNO->next = TOP;
		TOP = novoNO;
		return TOP;
	}
	else
	{
		printf("\nProblemas de alocação.\n");
		return NULL;
	}
}

node *POP(node *TOP, int conteudo)
{
	node *temp;
	temp = TOP->next;
	conteudo = temp->conteudo;//nao entendo
	TOP = TOP->next;
	free(temp);
	return TOP;	
}

void IMPRIME(node *TOP)
{
	node *temp;
	temp = TOP;
	
	if(VAZIA(TOP)==1)
		printf("\npilha vazia brow\n");
	
	printf("\npilha:\n");
	while(temp!=NULL)
	{
		printf("%d - %c\n", temp->conteudo);
		printf("*\n");
		temp = temp->next;
	}	
	printf("NULL\n");
}

/*
node *POPaleatorio(node *TOP, int conteudo, int item)
{
	node *temp;
	node = TOP;
	
	while(temp != NULL)
	{
		if(temp->conteudo == item)
		{
			node *anterior;
			node *prox;
			
			
		}
	}
}
*/
//FIM DAS FUNCOES PILHA

//INICIO DAS FUNCOES FILA
void criaFILA(nodef **INICIO, nodef **FIM, int conteudo)
{
	nodef *novoNO;
	novoNO = (nodef*)malloc(sizeof(nodef));
	if(novoNO != NULL)
	{
		novoNO->conteudo = conteudo;
		novoNO->next = NULL;
	}
	*INICIO = novoNO;
	*FIM = novoNO;
}

nodef *PUCHfila(nodef *FIM, int conteudo)
{
	nodef *novoNO;
	novoNO = (nodef*)malloc(sizeof(nodef));
	
	if(novoNO != NULL)
	{
		novoNO->conteudo = conteudo;
		novoNO->next = NULL;
		FIM->next = novoNO;
		return novoNO;
	}
	else
	{
		printf("\nProblemas para alocar memoria\n");
		return NULL;
	}
}

nodef *POPfila(nodef *INICIO)
{
	nodef *temp;
	temp = INICIO;
	
	if(temp!=NULL)
	{
		INICIO = INICIO->next;
		free(temp);
		return INICIO;
	}
	else
	{
		printf("\nfila vazia\n");
		return NULL;
	}
}

void IMPRIMEfila(nodef *INICIO)
{
	nodef *temp;
	temp = INICIO;
	
	if(temp == NULL)
	{
		printf("\nfila vazia\n");
	}
	else
	{
		printf("\nFila: ");
		while(temp != NULL)
		{
			printf("%d ->", temp->conteudo);
			temp = temp->next;
		}
		printf("NULL\n");
	}
}
//FIM DAS FUNCOES FILA

//INICIO DAS FUNCOES LISTA

void INICIAlista(nodel *LISTA)
{
	LISTA->next = NULL;
}

void insereINICIO(nodel *LISTA, int conteudo)
{
	nodel *novoNO;
	novoNO = (nodel*)malloc(sizeof(nodel));
	nodel *oldHEAD;
	
	if(novoNO!=NULL)
	{
		novoNO->conteudo = conteudo;
		oldHEAD = LISTA->next;
		LISTA->next = novoNO;
		novoNO->next = oldHEAD;
		
	}
	else
	{
		printf("\nProblemas de alocacao.\n");
	}
}

void insereFINAL(nodel *LISTA, int conteudo)
{
	nodel *novoNO;
	novoNO = (nodel*)malloc(sizeof(nodel));
	
	novoNO->conteudo = conteudo;
	novoNO->next = NULL;
	
	if(LISTA->next == NULL)
	{
		LISTA->next = novoNO;
	}
	else
	{
		nodel *temp;
		temp = LISTA->next;
		
		while(temp!=NULL)
		{
			temp = temp->next;
		}
		temp->next = novoNO;
	}
}

void insere(nodel *LISTA, int conteudo, int posi, int TAM)
{
	int cont=0;
	
	if(posi >= 0 || posi<= TAM)
	{
		if(posi = 0)
		{
			insereINICIO(LISTA, conteudo);
		}
		else if(posi == TAM)
		{
			insereFINAL(LISTA, conteudo);
		}
		else
		{
			nodel *novoNO;
			novoNO = (nodel*)malloc(sizeof(nodel));
			novoNO->conteudo = conteudo;
			
			nodel *atual;
			atual = LISTA->next;
			nodel *anterior; 
			anterior = LISTA;
			
			while(cont!=posi)
			{
				anterior = atual;
				atual = atual->next;
				cont++;
			}
			anterior->next = novoNO;
			novoNO->next = atual;
		}
	}
}

void IMPRIMElista(nodel *LISTA)
{
	nodel *temp; 
	temp = LISTA->next;
	
	if(temp==NULL)
	{
		printf("\nlista vazia\n");
	}
	else 
	{
		printf("\nLista: ");
		while(temp!=NULL)
		{
			printf("%d ->",temp->conteudo);
			temp=temp->next;
		}
	}
}

nodel *POPinicio(nodel *LISTA, int conteudo)
{
	nodel *atual;
	atual = LISTA->next;
	if(atual==NULL)
	{
		printf("\nlista vazia\n");
	}
	else 
	{
		LISTA = atual->next;
		free(atual);
		return LISTA;
	}
}

nodel *POPfinal(nodel *LISTA, int conteudo)
{
	nodel *atual;
	atual = LISTA->next;
	nodel *anterior;
	anterior = LISTA;
	
	if(atual == NULL)
	{
		printf("\nlista vazia\n");
	}
	else
	{
		while(atual->next!=NULL)
		{
			anterior = atual;
			atual = atual->next;
		}
		anterior->next = NULL;
		free(atual);
		return anterior;
	}
}

nodel *POPlista(nodel *LISTA, int conteudo, int posi, int TAM)
{
	int cont=0;
	
	if(posi >= 0 || posi >= TAM)
	{
		if(posi == 0 )
		{
			POPinicio(LISTA, conteudo);
		}
		else if(posi == TAM)
		{
			POPfinal(LISTA, conteudo);
		}
		else
		{
			nodel *atual;
			atual = LISTA->next;
			nodel *anterior;
			anterior = LISTA;
			
			while(posi != cont)
			{
				anterior = atual;
				atual = atual->next;
				cont ++;
			}
			anterior->next = atual->next;
			free(atual);
			return anterior;
		}
		
	}
}

//FIM DAS FUNCOES LISTA
