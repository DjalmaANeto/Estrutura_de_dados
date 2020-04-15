#include <stdio.h>


struct Noh
{
	int idade;
	struct Noh *prox;	
};

typedef struct Noh noh;

void inicializa(noh ** inicio, noh ** fim, int idade);
noh * enfileira(noh * fim, int idade);
noh * desenfileira(noh * inicio);

void main()
{
	
	noh * inicio = NULL;
	noh * fim = NULL;
	int opt, idade;
	
	printf("\nEscolha uma opcao: \n");
	printf("\n1. ENFILEIRAR");
	printf("\n2. DESENFILEIRAR");
	printf("\n3. SAIR\n");
	scanf("%d", &opt);
	
	while(opt != 3)
	{
		switch(opt)
		{
			case 1: 
				printf("\nDigite a idade: ");
				scanf("%d", &idade);
				
				if(inicio == NULL)
				{
					inicializa(&inicio, &fim, idade);
				}
				else
				{
					fim = enfileira(fim, idade);
				}
				imprime(inicio);
				break;
				
			case 2:
			 	if(inicio != NULL)
			 	{
			 		inicio = desenfileira(inicio);	
				}
				imprime(inicio);
				break;
				
			default:
				printf("\Escolha inválida");
				break;
		}
		
		
		printf("\nO que você quer?");
		scanf("%d", &opt);
	}
	
}


void inicializa(noh ** inicio, noh ** fim, int idade)
{
	noh * novoNoh;	
	novoNoh = (noh *) malloc(sizeof(noh));
	
	if(novoNoh != NULL)
	{
		novoNoh->idade = idade;
		novoNoh->prox = NULL;
	}
	
	*inicio = novoNoh;
	*fim = novoNoh;	
}


noh * enfileira(noh * fim, int idade)//inicio e conteudo
{
	
	noh * novoNoh;
	novoNoh = (noh *) malloc(sizeof(noh));
	
	if(novoNoh!=NULL)
	{
		novoNoh->idade = idade;
		novoNoh->prox = NULL;
		fim->prox = novoNoh;
		return novoNoh;
	}
	else
	{
		printf("\nEspaço insuficiente!");
		return NULL;
	}
	
}

noh * desenfileira(noh * inicio)
{
	noh * temp;
	
	if(inicio != NULL)
	{
		temp = inicio;	
		inicio = inicio->prox;
		free(temp);
		return inicio;
	}
}

void imprime(noh * inicio)
{
	noh * atual = inicio;
	if(inicio == NULL)
	{
		printf("\nFila vazia!");	
	}
	else
	{
		printf("\nValor armazenado: \n");
	}
	
	while(atual != NULL)
	{
		printf("%d --> ", atual->idade);
		atual = atual->prox;
	}
	printf("NULL\n");
}
