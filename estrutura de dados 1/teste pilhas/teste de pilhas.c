#include <stdio.h>
#include <stdlib.h>

//criando um tipo Pilha
struct Pilha{
	int placas;
	struct Pilha * prox;
};

//criando pilha do tipo Pilha 
typedef struct Pilha pilha; 

//fun��o pushAcar
pilha * pushAcar(pilha * topo, int placas);
//fun��o popAcar
pilha * popAcar(pilha * topo, int * placas);
//funcao imprime 
void imprime (pilha * topo);

void main(){
	pilha * topo = NULL;
	int placas;
	int op;
	
	do{
		printf("1 - PUSH a car\n");
		printf("2 - POP a car\n");
		printf("3 - sair\n\n");
		scanf("%d",&op);
		
		switch(op){
			case 1: 
				printf("\nEntre com a placa do carro: ");
				scanf("%i",&placas);
				topo = pushAcar(topo, placas);
				imprime(topo);
				break;
				
			case 2:
				if(topo != NULL){
					topo = popAcar(topo, &placas);
					printf("\nValor retirado: %d\n", placas);
				}
				imprime(topo);
				break;
				
			default: 
				puts("\nValor invalido\n");
				break; 	
		}
		
	}while(op!= 3);	
	
}

//funcao push
pilha * pushAcar(pilha * topo, int placas){
	pilha * novoNoh;
	novoNoh = (pilha * ) malloc(sizeof(pilha));
	if(novoNoh != NULL){
		novoNoh->placas = placas;
		novoNoh->prox = topo;
		topo=novoNoh;
		return topo;
	}else{
		printf("\nErro durante aloca��o de mem�ria");
		return NULL;
	}
}

//funcao popAcar
pilha * popAcar(pilha * topo, int * placas){
	pilha * nohTemp;
	nohTemp = topo;
	* placas = topo->placas;
	topo = topo->prox;
	free(nohTemp);
	return topo;
	}

//funcao imporime pilha 	
void imprime (pilha * topo){
	if(topo == NULL){
		printf("\n\nValor n�o encontrado !");
	}else{
		printf("\n\nDado armazenado: \n");	
	}
	//imprimindo pilha 
	while(topo != NULL){
			printf("%d -> ", topo->placas);
			topo = topo->prox;
		}
		printf("NULL\n\n");
	}
	
