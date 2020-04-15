
#include <stdio.h>

struct Noh{
	int idade;
	struct Noh *prox;
};


main(){
	struct Noh *topo;
	struct Noh *novoNoh; 
	struct Noh *newNode;
	struct Noh *nodeV2;
	
	novoNoh = (struct Noh *) malloc(sizeof(struct Noh));	//criando o novoNoh
	novoNoh -> idade = 10;
	topo = novoNoh;	
	novoNoh -> prox = NULL;
		
		
	newNode = (struct Noh*) malloc(sizeof(struct Noh));		//criando o newNode
	newNode -> idade = 5;
	newNode -> prox = topo;
	topo = newNode;
	
	
	nodeV2 = (struct Noh *) malloc(sizeof(struct Noh));		//criando o nodeV2
	nodeV2 -> idade = 42;
	nodeV2 -> prox = topo;
	topo = nodeV2;
	
	
	
	
}

