#include <stdio.h>
#include <string.h>

#define n 3

typedef struct{
		char nome[40];
		int nota1, nota2;
		int mediaP;
	}alunos;
	alunos aluno[n];
	
void bubbleSort(alunos aluno[]);
void selectionSort(alunos aluno[]);
void inserctionSort(alunos aluno[]);
	
void main(){
	
	int i;
	
	//alimentando o vetor
	for(i = 0; i <= n; i++){
		printf("\n Informe o nome do aluno %i: ",i);
		scanf("%s",&aluno[i].nome);
		printf(" Informe a nota 1 do aluno %i: ",i);
		scanf("%i",&aluno[i].nota1);
		printf(" Informe a nota 2 do aluno %i: ",i);
		scanf("%i",&aluno[i].nota2);
		aluno[i].mediaP = (aluno[i].nota1 * 2 + aluno[i].nota2 * 3) / 5;
	}
	
	
	//ordenando pelas medias ponderadas
	bubbleSort(aluno);
	//imprimindo forma ordenada
	for(i = 0; i <= n; i++){
		printf("\nAluno %s media ponderada %i", aluno[i].nome, aluno[i].mediaP);
	}

	//ordenando pela nota 1
	printf("\n");
	inserctionSort(aluno);
	//imprimindo forma ordenada
	for(i = 0; i <= n; i++){
		printf("\nAluno %s nota 1 %i", aluno[i].nome, aluno[i].nota1);
	}


	//ordenando de froma alfabética
	printf("\n\n");
	selectionSort(aluno);
	//imprimindo
	for(i = 0; i <= n; i++){
		printf("%s ", aluno[i].nome);
		if(aluno[i].mediaP >= 7)
			printf("aprovado\n");
		else
			printf("reprovado\n");
	}
}

//bubble sort
void bubbleSort(alunos aluno[]){
	int N, i;
	alunos aux;
	//ordenando o vetor de forma crescente
	//laço com a quantidade de elemtos do vetor
	for(N = 1; N <= n; N++){
		//laço da 1ª a penultima posição 
		for(i = 0; i <= n-1; i++){
			if(aluno[i].mediaP > aluno[i+1].mediaP){
				aux = aluno[i];
				aluno[i] = aluno[i+1];
				aluno[i+1] = aux;
			}
		}
	}
}

//inserction sort 
void inserctionSort(alunos aluno[]){
	int i, j;
	alunos eleito;
	//ordenando de forma crescente 
	//laço com a quantidade de elementos -1
	for(i=1;i<=n;i++){
		eleito = aluno[i];
		j = i - 1;
		//laço percorre os elementos a esquerda de eleito
		//ou até encontrar a posição para recolocação do
		//numero eleito respeitando a ordenação procurada
		while(j >= 0 && aluno[j].nota1 > eleito.nota1){
			aluno[j+1] = aluno[j];
			j = j - 1;
		}
		aluno[j+1].nota1 = eleito.nota1;
	}	
}

//selection sort
void selectionSort(alunos aluno[]){
	int i, j, pos;
	alunos eleito, menor;
	//ordenando de forma crescente 
	//laço da 1ª a penultima posição elegendo um número para comparar 
	for(i=0; i<=n-1; i++){
		eleito = aluno[i];
		menor = aluno[i+1];
		pos = i + 1;
	
		//laço com os numeros a direita do eleito, 
		//retornando o menor número a direita e sua posição	
		for(j=i+1; j<=n; j++){
			if(strcmp(aluno[j].nome, menor.nome)  < 0){
				menor = aluno[j];
				pos = j;
			}
		}
		
		//troca
		if(strcmp(menor.nome, eleito.nome) < 0){
			aluno[i] = aluno[pos];
			aluno[pos] = eleito;
		}
	}
	
}







