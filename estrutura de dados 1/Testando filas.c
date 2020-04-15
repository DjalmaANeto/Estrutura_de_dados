#include<stdio.h>
#include<stdlib.h>

#define	MAXTAMNOME 40

struct Noh{
	char nome[MAXTAMNOME];
	int pedido;
	struct Noh *prox;
};

typedef struct Noh noh;

void inicializa(noh ** inicio, noh ** fim, char nome[MAXTAMNOME], int pedido);
noh * enfileira(noh * fim, char nome[MAXTAMNOME], int pedido);
noh * desenfilera(noh * inicio);

void main(){
	
	noh * inicio = NULL;
	noh * fim = NULL;
	int op, pedido;
	char nome[MAXTAMNOME];
	
	
	printf("\n\tMenu:\t\n");
	printf("Xburguer - 1\n");
	printf("Xbancon - 2\n");
	printf("xsalada - 3\n");
	
	
	do{
		printf("\n1-para enfileirar.");
		printf("\n2-para desinfileirar.");
		printf("\n3-para imprimir.");
		printf("\n4-Sair.\n");
		scanf("%i",&op);
		
		switch(op){
			
			case 1:
				
				printf("\nDigite:\n");
				printf("Nome: ");
				scanf("%c",&nome[MAXTAMNOME]);
				scanf("%c",&nome[MAXTAMNOME]);
				printf("Pedido: ");
				scanf("%i", &pedido);
				
				if(inicio == NULL){
					
					inicializa(&inicio, &fim, &nome[MAXTAMNOME], &pedido);
					
				}else{
					
					fim = enfileira(&fim, &nome[MAXTAMNOME], &pedido);
					
				}
				imprime(inicio);
				break;
			
			case 2:
				
				if(inicio != NULL){
					
					inicio = desenfilera(inicio);
					
				}
				imprime(inicio);
				printf("\nSaiu da fila.\n");
				break;
			
			case 3:
				
				imprime(inicio);
				break;
			
			case 4:
				
				printf("\nSaindo...\n");
				break;
			
			default:
				
				printf("\nOpcao invalida!\n");
				printf("\nEscreva um comando valido:\n");		
				break;
		}
	}while(op!=4);	
		
}

void inicializa(noh ** inicio, noh ** fim, char nome[MAXTAMNOME], int pedido){

	noh * novoNoh;
	novoNoh = (noh *) malloc((sizeof(noh)));
	
	if(novoNoh != NULL){
		novoNoh -> nome[MAXTAMNOME] = nome[MAXTAMNOME];
		novoNoh -> pedido = pedido;
		novoNoh -> prox = NULL; 
	}
	
	*inicio = novoNoh;
	*fim = novoNoh;	
}

noh * enfileira(noh * fim, char nome[MAXTAMNOME], int pedido){
	
	noh * novoNoh;	
	novoNoh = (noh *) malloc((sizeof(noh)));
	
	if(novoNoh != NULL){
		novoNoh -> nome[MAXTAMNOME] = nome[MAXTAMNOME];
		novoNoh -> pedido = pedido;
		fim -> prox = novoNoh; 
		return novoNoh;
	}else{
		printf("\nEspaço insuficiente!");
		return NULL;
	}		
}

noh * desenfilera(noh * inicio){
	
	noh * Temp;
	
	if(inicio != NULL){
		Temp = inicio;
		inicio = inicio -> prox;
		free(Temp);
		return inicio;
	}
}

void imprime(noh * inicio){
	
	int pedido;
	char nome[MAXTAMNOME];
	noh * atual = inicio;
	
	if(inicio == NULL){
		printf("\nFila vazia.\n");
	}else{
		printf("\nCliente:\n");
	}
	
	while(atual != NULL){
		nome[MAXTAMNOME] = atual->nome;
		printf("Nome: %c\t", nome);
		pedido = atual->pedido;
		printf("Pedido: %d\n", pedido);
		atual = atual->prox;			
	}
	printf("\nNULL\n");
}





