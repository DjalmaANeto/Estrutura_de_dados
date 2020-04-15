#include <stdio.h>

#define M 1
#define N 1

void main(){
	int vet[N][M];
	int np, i, j, inicio, fim, meio, achou;
	int y, x[y];
	
	//carregando os números no vetor odenados
	for(i = 0; i <= N; i++){
		for(j = 0; j <= M; j++){
			printf("Digite o [%i][%i]: ", i, j);
			scanf("%i", &vet[i][j]);
			
			//tresnaformando matriz em vetor
			x[y] = vet[i][j];
			y++;
		}
	}
	
	//digitando o número para ser buscado no vetor 
	printf("Digite o número a ser buscado: ");
	scanf("%i",&np);
	
	//buscando o número digitado no vetor
	achou = 0;
	inicio = 0;
	fim = y;
	meio = (inicio + fim)/2;
	

	while(inicio <= fim && achou == 0){
		if(x[meio] == np)
			achou = 1;
		else{
			if(np < x[meio]){
				fim = meio-1;
			}
			else{
				inicio = meio + 1;
			}
			meio = (inicio + fim)/2;
		}
	}
	
	if(achou == 0)
		printf("Numero nao encontrado no vetor");
	else
		printf("Numero encontrado na posicao %i.", meio);
}
	
