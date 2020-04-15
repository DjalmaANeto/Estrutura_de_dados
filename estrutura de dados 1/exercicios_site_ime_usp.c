#include <stdio.h>
#include <stdlib.h>

struct NODE{
	int conteudo;
	struct NODE *next;
};
typedef struct NODE node;

void imprime(node *le);

void imprime(node *le){
	if(le != NULL){
		printf("%d\n", le->conteudo);
		imprime(le->conteudo);
	}
}



int main (void){
	node *le;
	imprime(le);
}
