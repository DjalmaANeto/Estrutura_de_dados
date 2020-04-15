#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define n 2

//funcionando com warnings 

typedef struct{
		char* nome[40];
		int* idade;
		char* sexo[40];
	}pessoa;
	pessoa p[n];

//quick sort
void troca(pessoa p[], int i, int j);
int particao(pessoa pp[], int p, int r);
void quicksort(pessoa pp[], int p, int r);

void main (){
	
	int i, N, troca, aux;
	char auxs[40];
	pessoa auxi;
		
	//alimentando o vetor
	for(i = 0; i <= n; i++){
		printf("\nEscreva o nome da pessoa %i: ", i);
		scanf("%s",&p[i].nome);
		printf("Escreva a idade da pessoa %i: ", i);
		scanf("%d",&p[i].idade);
		printf("Escreva o sexo da pessoa %i:", i);
		scanf("%s",&p[i].sexo);
	}
	
	//imprimindo o vetor desordenado
	printf("\nLista desordenada: ");
	for(i = 0; i <= n; i++){
		printf("\nPessoa %i: nome: %s\tidade: %i\tsexo: %s",i, p[i].nome, p[i].idade, p[i].sexo);
	}
	
	//ordenando nomes em ordem alfabética crescente quick sort
	quicksort(p, 0, n);
	
	//imprimindo o vetor ordenado
	printf("\n\nLista ordenada alfabetica crescente: ");
	for(i = 0; i <= n; i++){
		printf("\nPessoa %i: nome: %s\tidade: %i\tsexo: %s",i, p[i].nome, p[i].idade, p[i].sexo);
	}
	
	//ordenando por idades descrecentes bubble sort
	N = 1;
	troca = 1;
	while(N<=5 && troca == 1){
		troca = 0;
		for(i=0;i<=n;i++){
			if(p[i].idade < p[i+1].idade){
				troca = 1;
				auxi = p[i];
				p[i] = p[i+1];
				p[i+1] = auxi;
			}
		}
		N = N + 1;
	}
	
	//imprimindo o vetor ordenado
	printf("\n\nLista ordenada idades decrescente: ");
	for(i = 0; i <= n; i++){
		printf("\nPessoa %i: nome: %s\tidade: %i\tsexo: %s",i, p[i].nome, p[i].idade, p[i].sexo);
	}
	
}

void troca(pessoa p[], int i, int j)
{
	pessoa auxi;
	
	auxi = p[i];
	p[i] = p[j];
	p[j] = auxi;
}

int particao(pessoa pp[], int p, int r)
{
	int i, j;
	char pivo[40];
	strcpy(pivo, pp[(p+r)/2].nome);
	i = p-1;
	j = r+1;
	
	while(i < j){
		do{
			j = j - 1;
		}while(strcmp(pp[j].nome, pivo) > 0);
		do{
			i = i + 1;
		}
		while(strcmp(pp[i].nome, pivo) < 0);
		if(i < j) troca(pp, i, j);
	}
	return j;
}


void quicksort(pessoa pp[], int p, int r)
{
	int q;
	if(p < r){
		q = particao(pp, p, r);
		quicksort(pp, p, q);
		quicksort(pp, q+1, r);
	}
}

