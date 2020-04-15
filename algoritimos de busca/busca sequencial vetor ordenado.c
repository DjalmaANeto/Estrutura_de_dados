//WORKING 

#include <stdio.h>

#define N 10

void main(){
	int x[N], n, i, achou;
	
	for(i = 0; i <= N; i++){
		printf("Digite o %i numero: ", i);
		scanf("%i",&x[i]);
	}
	
	printf("Digite o numero a ser buscado: ");
	scanf("%i",&n);
	
	//buscando o numero digitado
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
