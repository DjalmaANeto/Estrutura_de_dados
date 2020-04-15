#include <stdio.h>
#include <stdlib.h>
//criando um novo tipo Pilha
struct Pilha{
	int idade; 
	struct Pilha * prox;
};
//criando pilha tipo Pilha
typedef struct Pilha pilha;
//funcao push
pilha * push(pilha * topo, int idade);
//funcao pop
pilha * pop(pilha * topo, int *idade);
//funcao imprime pilha
void imprime(pilha * topo); 

void main(){
	
	pilha * topo = NULL;
	int idade, opt; 
	
	do{
		printf("1 - PUSH\n");
		printf("2 - POP\n");
		printf("3 - sair\n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: 
				printf("\nEntre com a idade: ");
				scanf("%d",&idade);
				topo = push(topo, idade);
				imprime(topo);
				break;
				
			case 2:
				if(topo != NULL){
					topo = pop(topo, &idade);
					printf("\nValor retirado: %d/n", idade);
				}
				imprime(topo);
				break;
			default: 
				puts("\nValor invalido");
				break; 	
			 	
		}
	}while(opt != 3);	
}
//funcao push(adiciona um elemento a pilha)
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
 		
//fucao pop("retira" a ultima posicao da pilha) 	
pilha * pop(pilha * topo, int * idade){
	pilha * nohTemp;
	nohTemp = topo;
	*idade = topo->idade;
	topo = topo->prox;
	free(nohTemp); 
	return topo;	
}
 	
//funcao imporime pilha 	
void imprime (pilha * topo){
	if(topo == NULL){	
		printf("\n\nValor não encontrado !");
	}else{
		printf("\n\nDado armazenado: \n");	
	}
	//imprimindo pilha 
	while(topo != NULL){
			printf("%d -> ", topo->idade);
			topo = topo->prox;	
		}
		printf("NULL\n\n");
	}
	





