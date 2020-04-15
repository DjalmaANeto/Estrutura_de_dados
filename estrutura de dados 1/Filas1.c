#include <stdio.h>
#include <stdlib.h>

struct Noh {
	int idade;
	char nome[40];
	struct Noh *prox;
};

typedef struct Noh noh;
void inicializa(noh **inicio, noh **fim, int idade);
noh * enfileira(noh * fim, int idade);
void imprime(noh * inicio);
noh * desenfileira(noh * inicio);

int main(){
	noh * inicio = NULL;
	noh * fim = NULL; 
	int opt,idade;
	
	while(opt!=3){
	
	printf("\nEscreva uma opção:\n");
	printf("\n1.Enfileirar\n");
	printf("\n2.Desenfileirar\n");
	printf("\n3.Sair\n");
	scanf("%d", &opt);
	
		switch(opt){
			case 1:
				printf("\nDigite a idade: ");
				scanf("%d",&idade);
				
				if(inicio==NULL){
					inicializa(&inicio, &fim, idade);
				}else{
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
	}
}

void inicializa(noh **inicio, noh ** fim, int idade ){
	noh * novoNoh;	
	novoNoh = (noh*) malloc (sizeof(noh));
	if (novoNoh!=NULL){
		
		novoNoh->idade=idade;
		novoNoh->prox = NULL;
	}
	*inicio = novoNoh;
	*fim = novoNoh; 
}

noh * enfileira(noh * fim, int idade){
	
	noh * novoNoh;
	novoNoh = (noh *)malloc(sizeof(noh));
	
	if(novoNoh!=NULL){
		novoNoh->idade;
		novoNoh->prox = NULL;
		fim->prox = novoNoh;
		return novoNoh;
	}else{
		printf("\nEspaço insuficiente!\n");
	}
	
}

noh * desenfileira(noh * inicio){
	noh * temp;
	if(inicio != NULL){
		temp = inicio;
		inicio = inicio->prox;
		free(temp);
		return inicio;
	}
}

void imprime(noh * inicio){
	noh * atual = inicio;
	if(inicio==NULL){
		printf("\nFila vazia\n");
	}else{
		printf("\nValor armazenado: \n");
	}
	
	while(atual){
		printf("%d -->", atual->idade);
		atual = atual->prox;
	}
	printf("NULL\n");
}

