#include <stdio.h>
#include <string.h>

//merge sort
void merge(int vet[], char vets[5][20], int inicio, int fim);
void intercala (int vet[], char vets[5][20], int inicio, int fim, int meio);

//quick sort
void troca(char vets[5][20], int vet[], int i, int j);
int particao(char vets[5][20], int vet[], int p, int r);
void quicksort(char vets[5][20], int vet[], int p, int r);

main(){
	int salario[5];
	char nomes[5][20];
	char auxs[20];
	int op;
	int i;
	int aux, N, troca;
	
	//preenchendo vetores
	for(i=0; i<=5; i++){
		printf("Escreva nome[%i]: ",i);
		scanf("%s",nomes[i]);
		fflush(stdout);
		printf("Escreva o salario[%i]: ",i);
		scanf("%i",&salario[i]);
		fflush(stdout);
		printf("\n");
	}
	
	//imprimindo forma atual
	for(i=0; i<=5; i++){
		printf("nome[%i]: %s ",i, nomes[i]);
		printf(" salario[%i]: %i\n",i, salario[i]);
	}
	
	//formas de ordenar
	do{
		printf("\n1 - Ordem crescente de salario");//merge sort 
		printf("\n2 - Ordem decrescente de salario");//buble sort 2 
		printf("\n3 - Ordem alfabetica de nomes");//quick sort
		printf("\n0 - Sair\n"); 
		scanf("%i", &op);
		
		switch (op){
			case 1:
				merge(salario, nomes, 0,5);	
				//imprimindo forma ordenada
				for(i=0; i<=5; i++){
				printf("nome[%i]: %s ",i, nomes[i]);
				printf(" salario[%i]: %i\n",i, salario[i]);
				}			
			break;
			
			case 2:
				//buble sort 2
				N = 1;
				troca = 1;
				while(N<=5 && troca == 1){
					troca = 0;
					for(i=0;i<=5;i++){
						if(salario[i]<salario[i+1]){
							troca = 1;
							//trocando salarios
							aux = salario[i];
							salario[i] = salario[i+1];
							salario[i+1] = aux;
							//trocando nomes
							strcpy(auxs,nomes[i]);
							strcpy(nomes[i],nomes[i+1]);
							strcpy(nomes[i+1],auxs);
						}
					}
					N = N + 1;
				}
				
				//imprimindo forma ordenada
				for(i=0; i<=5; i++){
				printf("nome[%i]: %s ",i, nomes[i]);
				printf(" salario[%i]: %i\n",i, salario[i]);
				}
			break;
			
			case 3:
				quicksort(nomes, salario, 0, 5);
				//imprimindo forma ordenada
				for(i=0; i<=5; i++){
				printf("nome[%i]: %s ",i, nomes[i]);
				printf(" salario[%i]: %i\n",i, salario[i]);
				}
			break;
			
			case 0:
				printf("\n Encerrando.");
			break;
			
			default:
				printf("Opcao invalida.");
				
		}
				
	}while(op != 0);	
	
}

//merge sort
void intercala (int vet[],char vets[5][20], int inicio, int fim, int meio)
{
	int poslivre, inicio_vetor1, inicio_vetor2, i;
	int aux[5];
	char auxs[5][20];
	inicio_vetor1 = inicio;
	inicio_vetor2 = meio + 1; 
	poslivre = inicio;
	
	//"quebra" o vetor
	while(inicio_vetor1 <= meio && inicio_vetor2 <= fim){
		if(vet[inicio_vetor1] <= vet[inicio_vetor2]){
			aux[poslivre] = vet[inicio_vetor1];
			strcpy(auxs[poslivre], vets[inicio_vetor1]);//ordenando vetor de nomes
			inicio_vetor1 = inicio_vetor1 + 1;
		}else{
			aux[poslivre] = vet[inicio_vetor2];
			strcpy(auxs[poslivre], vets[inicio_vetor2]);//ordenando vetor de nomes
			inicio_vetor2 = inicio_vetor2 + 1;
			//ordenando vetor de nomes
			
		}
		poslivre = poslivre + 1;
	}	
	
	//se ainda existirem numeros do primeiro vetor não intercalados
	for(i = inicio_vetor1; i <= meio; i++){
		aux[poslivre] = vet[i];
		strcpy(auxs[poslivre], vets[i]);//ordenando vetor de nomes
		poslivre = poslivre + 1;
	}
	
	//se ainda existirem numeros do segundo vetor não intercalados
	for(i = inicio_vetor2; i <= fim; i++){
		aux[poslivre] = vet[i];
		strcpy(auxs[poslivre], vets[i]);//ordenando vetor de nomes
		poslivre = poslivre + 1;
	}
	
	//retorna os numeros do vetor aux para vet 
	for(i = inicio; i<=fim; i++){
		vet[i] = aux[i];
		strcpy(vets[i], auxs[i]);//ordenando vetor de nomes
	}
}

void merge(int vet[], char vets[5][20], int inicio, int fim)
{
	int meio;
	if(inicio < fim){
		meio = (inicio + fim)/2;
		//vetor 1 para intercalar
		merge(vet, vets, inicio, meio);
		//vetor 2 para intercalar
		merge(vet, vets, meio+1, fim);
		intercala(vet, vets, inicio, fim, meio);
	}
	
}

//quick sort
void troca(char vets[5][20], int vet[], int i, int j)
{
	int aux;
	char auxs[20];
	//troca nomes
	strcpy(auxs, vets[i]);
	strcpy(vets[i], vets[j]);
	strcpy(vets[j], auxs);
	//troca salarios 
	aux = vet[i];
	vet[i] = vet[j];
	vet[j] = aux;
}

int particao(char vets[5][20], int vet[], int p, int r)
{
	int i, j;
	char pivo[20];
	strcpy(pivo, vets[(p+r)/2]);
	i = p-1;
	j = r+1;
	
	while(i < j){
		do{
			j = j - 1;
		}while(strcmp(vets[j], pivo) > 0);
		do{
			i = i + 1;
		}
		while(strcmp(vets[i],pivo) < 0);
		if(i < j) troca(vets, vet, i, j);
	}
	return j;
}

void quicksort(char vets[5][20], int vet[], int p, int r)
{
	int q;
	if(p < r){
		q = particao(vets, vet, p, r);
		quicksort(vets, vet, p, q);
		quicksort(vets, vet, q+1, r);
	}
}

