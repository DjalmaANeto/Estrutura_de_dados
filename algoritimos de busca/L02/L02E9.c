#include <stdio.h>

#define N 2

typedef struct{
	int codigo;
	char descricao[100];
	int preco;
}PRODUTO;

PRODUTO prod[N];

int particao(PRODUTO prod[], int p, int r);
void quicksort(PRODUTO prod[], int p, int r);

void main(){
	int i;
	
	//preenchendo vetor 
	for(i = 0; i <= N; i++){
		printf("\nescreva o codigo: ");
		scanf("%i",&prod[i].codigo);
		printf("escreva o descriao: ");
		scanf("%s",&prod[i].descricao);
		printf("escreva o preco: ");
		scanf("%i",&prod[i].preco);
	}
	
	//ordenando por codigo
	quicksort(prod, 0, N);
	
	//imprimindo vetor 
	for(i = 0; i <= N; i++){
		printf("\ncodigo: %i  ", prod[i].codigo);
		printf("descriao: %s  ", prod[i].descricao);
		printf("preco: %i", prod[i].preco);
	}
	
	//busca sequencial
	printf("\n\nBusca sequencial:");
	int n;
	int compara;
	printf("\nDigite o codigo a ser buscado: ");
	scanf("%i",&n);
	
	//buscando o numero digitado
	int achou = 0; 
	i = 0;
	while(i <= N && achou == 0 && n >= prod[i].codigo){
		if (prod[i].codigo == n){
			achou = 1;
		}else{
			i++;
			compara++;
		} 
	}
	
	if (achou == 0)
		printf("Codigo nao encontrado no vetor");
	else
		printf("Codigo encontrado na posicao %i apos %i comparacoes.", i, compara);
		
	
	//busca binária 
	printf("\n\nBusca binaria:");
	int np;
	//digitando o número para ser buscado no vetor 
	printf("\nDigite o número a ser buscado: ");
	scanf("%i",&np);
	
	//buscando o número digitado no vetor
	achou = 0;
	int inicio = 0;
	int fim = N;
	int meio = (inicio + fim)/2;
	compara = 0;
	
	while(inicio <= fim && achou == 0){
		if(prod[meio].codigo == np)
			achou = 1;
		else{
			if(np < prod[meio].codigo){
				fim = meio-1;
				compara++;
			}
			else{
				inicio = meio + 1;
				compara++;
			}
			meio = (inicio + fim)/2;
			compara++;
		}
	}
	if(achou == 0)
		printf("Numero nao encontrado no vetor");
	else
		printf("Numero encontrado na posicao %i apos %i comparacoes", meio, compara);
		
}

void troca(PRODUTO prod[], int i, int j)
{
	PRODUTO aux;
	aux = prod[i];
	prod[i] = prod[j];
	prod[j] = aux;
}

int particao(PRODUTO prod[], int p, int r)
{
	PRODUTO pivo;
	int  i, j;
	pivo = prod[(p+r)/2];
	i = p-1;
	j = r+1;
	
	while(i < j){
		do{
			j = j - 1;
		}while(prod[j].codigo > pivo.codigo);
		do{
			i = i + 1;
		}
		while(prod[i].codigo < pivo.codigo);
		if(i < j) troca(prod, i, j);
	}
	return j;
}

void quicksort(PRODUTO prod[], int p, int r)
{
	int q;
	if(p < r){
		q = particao(prod, p, r);
		quicksort(prod, p, q);
		quicksort(prod, q+1, r);
	}
}



