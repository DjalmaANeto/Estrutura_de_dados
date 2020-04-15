#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMPLACA 7
#define QUANTVAGA 10

//criado um ripo    "pilha"
struct pilha{
	char placas[TAMPLACA];
	int n;
	float Vagas[QUANTVAGA]; 
};


//criando uma Pilha tipo pilha
typedef struct pilha Pilha;


//inicializando criaPilha
 Pilha* criaPilha(void);
//inicializando push
 Pilha* push(Pilha* p,char placas[TAMPLACA]);
 
 
 //funcao cria pilha aloca dinamicamente essa estrutura e inicializa a pilha como sendo vazia, isto é, com o número de elementos igual a zero
 Pilha* criaPilha(void)
 {
 	Pilha* p = (Pilha*)malloc(sizeof(Pilha));
 	p->n = 0;
 	return p;
 }		


//funcao push
Pilha* push (Pilha* p, char placas[TAMPLACA])
{
	if(p->n == QUANTVAGA){
		printf("\nEstacionamento lotado.\n");
	}else{
		p->Vagas[p->n]=placas[TAMPLACA];
		p->n++;
	}
}


void main(){
	Pilha * topo = NULL;
	Pilha * p;
	char placas[QUANTVAGA];
	int op;
	
	do{
		printf("1 - PUSH a car\n");
		printf("2 - POP a car\n");
		printf("3 - sair\n\n");
		scanf("%d",&op);
		
		switch(op){
			case 1: 
				printf("\nEntre com a placa do carro: ");
				gets(placas);
				topo = push(p, placas);
				break;
		/*
			case 2:
				if(topo != NULL){
					topo = popAcar(topo, &placas);
					printf("\nValor retirado: %d\n", placas);
				}
				imprime(topo);
				break;
		*/				
			default: 
				puts("\nValor invalido\n");
				break; 	
		}
		
	}while(op!= 3);	
	
}
