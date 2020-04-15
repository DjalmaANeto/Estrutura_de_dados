#include <stdio.h>
#include <stdlib.h>

//desafio sostenes 

struct Estacionamento{
	char placa_cliente[8];
	int manobras;
	struct Estacionamento * prox[10];
	/*struct Estacionamento * proxRua;*/
	};
	
	//criando vagas(é a pilha) tipo Estacionamento
	typedef struct Estacionamento vagas;
	//criando uma pilha na rua
	typedef struct Estacionamento vagasRua;
	
	//função add (push) carro na vaga
	vagas * PUSHCarro(vagas * topo, char placa_cliente[8]);

	
	void main(){
		
		vagas * topo = NULL; 
		char placa_carro[8];
		int op, manobras;
		
		do{
			printf("1 - PUSH a car\n");
			printf("2 - POP a car\n");
			printf("3 - exit of this\n");
			scanf("%d",&op);
			
		switch(op){
			
				case 1:
					printf("\nDigite a placa do carro a ser estacionado: "); 
					scanf("%c",&placa_carro);
					scanf("%c",&placa_carro);
					topo = PUSHCarro(topo, placa_carro);
					
					break; 
					
				case 2: 
					manobras ++;
					printf("");
					
					break;
					
				default: 
					puts("\nValor invalido");
					
			}	
			
		}while(op!=3);
	
	}
	
	
	//função PUSHCArro(push)
	vagas * PUSHCarro(vagas * topo, char placa_cliente[8]){
		
		int i;
		
		vagas * novoNoh;
		
		novoNoh = (vagas *) malloc(sizeof(vagas));
		
		if(novoNoh != NULL){
			novoNoh -> placa_cliente[8] = placa_cliente[8];
			novoNoh -> prox[i] = topo;
			topo = novoNoh;
			return topo;
			i++;
		}		
	}
	
	vagas * POPCarro(vagas * topo, char placa_cliente[8]){
		
	}
	
	//funcao imprime pilha 
	void imprime (vagas * topo){
		if ( topo == NULL ){
			printf("\n\nValor não encontrdo!");
		}else{
			printf("\n\nDado armazenado:\n");
		}
		//impressao de pilhas 
		while(topo != NULL){
			printf("%d -> ", topo->placa_cliente[8]);
			topo = topo->prox; 
		}
	}
	
