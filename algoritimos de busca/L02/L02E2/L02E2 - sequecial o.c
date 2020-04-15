#include <stdio.h>

#define N 10

void sequencialO(int x[], int n);

void main(){
	int x[N], n, i;
	
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i",&x[i]);
	}
	
	printf("Digite o numero a ser buscado: ");
	scanf("%i",&n);
	
	sequencialO(x,n);
		
}

void sequencialO(int x[], int n){
	//buscando o numero digitado
	int achou, i;
	achou = 0; 
	i = 0;
	while(i <= N && achou == 0 && n >= x[i]){
		if (x[i] == n){
			achou = 1;
		}else{
			i++;
		} 
	}
	
	if (achou == 0)
		printf("Numero nao encontrado no vetor");
	else
		printf("Numero encontrado na posicao %i", i);
}
