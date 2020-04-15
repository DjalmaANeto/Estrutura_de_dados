#include <stdio.h>

#define N 14

void main(){
	int i, j, x[N], n;
	
	//preenchendo o vetor sem repeticao
	for(i=0; i<=N; i++){
	    printf("\nDigite um numero: ");
		scanf("%i", &x[i]);
		for (j=0; j<i; j++){
			if (x[i] == x[j]){
				printf("Esse numero ja foi digitado, digite outro!\n");
				i--;	
			}    
		}
	}
	
	//busca sequencial 
	printf("\n\nBusca sequencial");
	printf("\nDigite o numero a ser buscado: ");
	scanf("%i", &n);
	
	//buscando número digitado no vetor
	int achou = 0;
	i = 0;
	while(i <= N && achou == 0){
		if(x[i] == n)
			achou = 1;
		else
			i++;
	}
	if(achou == 0)
		printf("\nNumero não encotrado no vetor");
	else
		printf("\nNumero encontrado em posicao ");
		if(i%2 == 0)
			printf("par.");
		else
			printf("impar."); 
		
	//busca binária
	printf("\n\nBusca binaria");
	printf("\nDigite o numero a ser buscado: ");
	scanf("%i",&n);
	
	//buscando o número digitado no vetor
	achou = 0;
	int inicio = 0;
	int fim = N;
	int meio = (inicio + fim)/2;
	
	while(inicio <= fim && achou == 0){
		if(x[meio] == n)
			achou = 1;
		else{
			if(n < x[meio]){
				fim = meio-1;
			}
			else{
				inicio = meio + 1;
			}
			meio = (inicio + fim)/2;
		}
	}
	if(achou == 0)
		printf("\nNumero não encotrado no vetor");
	else
		printf("\nNumero encontrado em posicao ");
		if(meio%2 == 0)
			printf("par.");
		else
			printf("impar.");
}
