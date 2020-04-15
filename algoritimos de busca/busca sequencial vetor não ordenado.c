//WORKING
#include <stdio.h>

#define N 10

void main(){
	int x[N], n, i, achou;
	
	//carregando os números o vetor
	//vetor com núnmero não ordenados 
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i", &x[i]);
	}
	
	//digitando o número a ser buscado no vetor
	printf("Digite o numero a ser buscado: ");
	scanf("%i", &n);
	
	//buscando número digitado no vetor
	achou = 0;
	i = 0;
	while(i <= N && achou == 0){
		if(x[i] == n)
			achou = 1;
		else
			i++;
	}
	if(achou == 0)
		printf("Numero não encotrado no vetor");
	else
		printf("Numero encontrado na posicao %i", i);
}
