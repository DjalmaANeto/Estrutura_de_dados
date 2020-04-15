#include <stdio.h>
#include <string.h>

#define n 8

void main(){
	int i, N;
	
	typedef struct{
		int codigo;
		char bairro[100];
		int tamanho;
		int valorv;
		int valora;
	}casas;
	casas casa[n];
	
	casas auxi;

	//preenchendo o vetor
	for(i = 0; i <= n; i ++){
		printf("\nEscreva o codigo da casa %i: ",i);
		scanf("%i",&casa[i].codigo);
		printf("Escreva o bairro da casa %i: ",i);
		scanf("%s",&casa[i].bairro);
		printf("Escreva o tamanho da casa %i: ",i);
		scanf("%i",&casa[i].tamanho);
		printf("Escreva o valor de venda da casa %i: ",i);
		scanf("%i",&casa[i].valorv);
		printf("Escreva o valor de aluguel da casa %i: ",i);
		scanf("%i",&casa[i].valora);
	}
	
	//ordenando o vetor de forma crescente pelo valor de venda 
	//laço com a quantidade de elemtos do vetor
	for(N=1;N<=n;N++){
		//laço da 1ª a penultima posição 
		for(i=0;i<=n-1;i++){
			if(casa[i].valorv > casa[i+1].valorv){
				auxi = casa[i];
				casa[i] = casa[i+1];
				casa[i+1] = auxi;
			}
		}
	}
	
	//imprimindo forma ordenada
	for(i = 0; i <= n; i++){
		printf("\nCasa codigo: %i\n\tbairro: %s\n\ttamanho: %i\n\tvalor de venda: %i\n\tvalor de aluguel: %i", casa[i].codigo, casa[i].bairro, casa[i].tamanho, casa[i].valorv, casa[i].valora);
	}
}









