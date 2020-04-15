#include <stdio.h>
#include <stdlib.h>

struct list{
	int conteudo;
	struct list *prox;
};

typedef struct list celula;//defina um tipo celula

void main(int argc, char *argv[]){
	
	celula *inicioLista;
	celula *proximoLista;
	
	int resp;
	
	inicioLista = (celula *)malloc(sizeof(celula));
	
	if(inicioLista == NULL)
		exit(1);
		
	proximoLista = inicioLista;
	
	
	
	while(resp = 1){
		printf("Digite o conteudo int da lista: ");
		scanf("%d", &proximoLista->conteudo);
		printf("\nDigite 1 para continuar incrementando ou qualquer outro valor para sair.\n");
		scanf("%d", &resp);
		if(resp == 1){
			proximoLista->prox = (celula *)malloc(sizeof(celula));
			proximoLista = inicioLista;
		}else break;	
	}
	
	printf("\n");
	proximoLista->prox = NULL;
	proximoLista = inicioLista;
	
	do{
		printf("Valor encadeado: %d\n", proximoLista->conteudo);
		proximoLista = proximoLista->prox;
	}while(proximoLista != NULL);
	
}
