#include <stdio.h>

typedef struct arvore{
	int valor;
	struct arvore *sae;
	struct arvore *sad;
	
}Arvore;

void insereNOH(Arvore **raiz, int valor){
	if(*raiz == NULL){
		*raiz = (Arvore*)malloc(sizeof(Arvore));
		(*raiz)->valor = valor;
		(*raiz)->sad = NULL;
		(*raiz)->sae = NULL;
	}
	else{
		
	}		
		
}
