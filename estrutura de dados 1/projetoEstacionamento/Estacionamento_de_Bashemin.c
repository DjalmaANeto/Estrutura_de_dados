#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTAM 2

struct pilha{
	char vagas[MAXTAM];
	char vagasRua[MAXTAM];
	int *manobras;
	int topo;
};

typedef struct pilha Epilha;//criando variavel pilha estacionamento 
typedef struct pilha Rpilha;//criando variavel pilha rua 

void Epilha_inicia(Epilha * p){//inicia a pilha do estacionamento vazia
	p->topo = -1;
}

void Rpilha_inicia(Rpilha *rp){//inicia a pilha da rua vazia 
	rp->topo = -1;
}

int Epilha_Vazia(Epilha *p){//verifica se a pilha estacionamento esta vazia
	if(p->topo == -1){
		return 1;//retorna 1 se a pilha esta vazia
	}else {
		return 0; //retorna 0 se a pilha n�o est� vazia
	}
}

int Rpilha_Vazia(Rpilha *rp){//verifica se a rua estacionamento esta vazia
	if(rp->topo == -1){
		return 1;//retorna 1 se a pilha rua esta vazia
	}else {
		return 0; //retorna 0 se a pilha rua n�o est� vazia
	}
}

int Epilha_Cheia (Epilha *p){//verifica se a pilha estacionamento esta cheia
	if(p->topo==MAXTAM-1){
		return 1;//retorna 1 se a pilha esta cheia 
	}else {
		return 0;//retorna 0 se a pilha n�o esta cheia 
	}
}

int Rpilha_Cheia (Rpilha *rp){//verifica se a pilha rua esta cheia
	if(rp->topo==MAXTAM-1){
		return 1;//retorna 1 se a pilha esta cheia 
	}else {
		return 0;//retorna 0 se a pilha n�o esta cheia 
	}
}

void Epilha_Push(Epilha *p, char Placa[7]){//add um carro na pilha estacionamento
	if (Epilha_Cheia(p)==1){
		printf("\nPilha cheia\n");
	} else{
		p->topo++;
		p->vagas[p->topo] = Placa[7];
	}
}

void Rpilha_Push(Rpilha *rp, char Placa[7]){//add um carro na pilha rua
	if (Rpilha_Cheia(rp)==1){
		printf("\nPilha cheia\n");
	} else{
		rp->topo++;
		rp->vagasRua[rp->topo] = Placa[7];
	}
}


char Epilha_Pop(Epilha *p){
	int aux;
	if(Epilha_Vazia(p) == 1){
		printf("ERRO: Pilha vazia");
	}else{
		aux == p->vagas[p->topo];
		p->topo--;
	}
}

char Rpilha_Pop(Rpilha *rp){
	int Raux;
	if(Rpilha_Vazia(rp) == 1){
		printf("ERRO: Pilha rua vazia");
	}else{
		Raux == rp->vagasRua[rp->topo];
		rp->topo--;
	}
}


void Epilha_Manobra(Rpilha *Rp, char Placa[7]){//funcao conta manobras dentro do estacionamento
	char Raux;
	Raux = Epilha_Pop(Rp);
	Rpilha_Push(Rp,Raux);	
}

void Rpilha_Manobra(Epilha *rp, char Placa[7]){//funcao conta manobras fora do estacionaemnto
	Epilha *Eaux;
	Eaux=Rpilha_Pop(rp);
	Epilha_Push(Eaux,Placa[7]);
}


//funcao imprime 
void imprime (Epilha *p){
	if(Epilha_Vazia(p)==1){
		printf("\n\nValor n�o encontrado, estacionamento vazio.");
	}else{
		printf("\n\nCarro estacionado: \n");	
	}
	//imprimindo pilha 
	while(Epilha_Vazia(p) == 0){
			printf("%c -> ", p->vagas[p->topo]);
			p->topo--;
		}
		printf("NULL\n\n");
	}


int main(){
	
	Epilha *p = (Epilha*)malloc(sizeof(Epilha));
	Epilha_inicia(p);
	
	Epilha *Rp = (Rpilha*)malloc(sizeof(Rpilha));
	Rpilha_inicia(Rp);
	
	int op;
	char aux;
	char Placas[7];
	char PlacaRem[7];
	
	do{
		printf("\n1 - PUSH a car\n");
		printf("2 - POP a car\n");
		printf("3 - sair\n\n");
		scanf("%d",&op);
						
		switch(op){
			case 1: 
				printf("\nEntre com a placa do carro: ");
				gets(Placas);
				p++;
				Epilha_Push(p, Placas);
				imprime(p);
				break;

			case 2:
				printf("\nInforme o carro que deseja retirar: ");
				gets(PlacaRem);
				
				do{
					Epilha_Manobra(p,PlacaRem);
					p++;
				}while(p != PlacaRem);
				
				printf("\nCarro removido:\n ");
				aux = Epilha_Pop(p->topo);
				printf("%c\n", aux);
				
				if(aux == PlacaRem)
					Rpilha_Manobra(p,Placas);
				imprime(p);
				break;
				
			default: 
			puts("\nValor invalido\n");	
			break; 	
		}
			
	}while(op!=3);
	
}
