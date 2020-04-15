#include <stdio.h>
#include <string.h>

void main(){
	
	char X[62] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 'A', 'B', 'C' , 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L','M', 'N', 'O', 'P', 'Q', 'R', 'S', 'U', 'V', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 'u', 'v', 'x', 'y', 'z'};
	char np[62];
	
	int i;
	for(i=0;i<=62;i++){
		printf("%s", X[i]);
	}
	
	
	//digitando o número para ser buscado no vetor 
	printf("Digite um elemento a ser buscado: ");
	scanf("%s",&np);
	
	//busca binária
	int achou = 0;
	int inicio = 0;
	int fim = 62;
	int meio = (inicio + fim)/2;
	while(inicio <= fim && achou == 0){
		if(strcmp(X[meio],np) == 0){
			achou = 1;
		}
		else{
			if(strcmp(np, X[meio]) < 0){
				fim = meio-1;
			}
			else{
				inicio = meio + 1;
			}
			meio = (inicio + fim)/2;
		}
	}
	
	if(achou == 0){
		printf("Numero nao encontrado no vetor");
	}
	else{
		printf("Numero encontrado na posicao %i", meio);
		}
	
}
