#include <stdio.h>
#include <stdlib.h>

struct Pilha{
	
	int idade;	
	struct Pilha * prox;
};

typedef struct Pilha pilha;

pilha * push(pilha * topo, int idade);
pilha * pop(pilha * topo, int *idade);
void imprime(pilha * topo);


main(){
	pilha * topo = NULL;
	int idade, opt;	
	
	do{
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - Sair");
		printf("\nDigite a opcao: ");
		scanf("%d", &opt);
		
		switch(opt){
			case 1: 
				printf("\nEntre com a idade: ");
				scanf("%d", &idade);
				topo = push(topo, idade);
				imprime(topo);
				break;
			case 2:
				if(topo != NULL){
					topo = pop(topo, &idade);
					printf("\nValor retirado: %d\n", idade);
				}
				imprime(topo);
				break;
				
			default:
				puts("\nValor inválido");
				break;
		}
	}while(opt != 3);	
	
}


pilha * push(pilha * topo, int idade){
	
	pilha * novoNoh;
	
	novoNoh = (pilha *) malloc(sizeof(pilha));
	
	if(novoNoh != NULL){
		novoNoh->idade = idade;
		novoNoh->prox = topo;
		topo = novoNoh;		
		return topo;
	}
	else{
		printf("\nErro na alocação de memória");
		return NULL;
	}
}


pilha * pop(pilha * topo, int * idade){
	pilha * nohTemp;	
	
	nohTemp = topo;
	*idade = topo -> idade;
	topo = topo -> prox;
	free(nohTemp);
	
	return topo;
	
}


void imprime(pilha * topo){
	
	if(topo == NULL){
		printf("\n\nValor nao encontrado!");
	}else{
		printf("\n\nDado armazenado: \n");
		
		while(topo != NULL){
			printf("%d -> ", topo->idade);
			topo = topo->prox;
		}
		printf("NULL\n\n");
	}
}


