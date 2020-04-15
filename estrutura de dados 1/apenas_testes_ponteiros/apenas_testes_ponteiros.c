#include <stdio.h>
#include <stdlib.h>
//testando ponteiros 

int main(){
	
	int a, b, c;
	int x;
	int *ptr;
	
	a=10;
	b=30;
	c=50;
	
	ptr = &a;
	printf("\nValor de a: %d. Conteudo de a: %d\n", ptr, *ptr);
	ptr = &b;
	printf("\nValor de b: %d. Conteudo de b: %d\n", ptr, *ptr);
	ptr = &c;
	printf("\nValor de c: %d. Conteudo de c: %d\n", ptr , *ptr);
	ptr = &x;
	printf("\nO endereço de X é: %p\n", ptr);
	
	printf("\nTestando a passagem por derreferencia:\n");
	printf("Acessando o Conteúdo de uma Posição de Memória através de um Ponteiro\n");
	x = 5;
	ptr = &x;
	printf("valor de X: %d, derreferenciando o ponteiro ptr.\n", *ptr);
	*ptr = 10;
	printf("valor de X: %d, derreferenciando o ponteiro ptr do lado esquerdo.\n", *ptr);
	
	printf("\nTestando alocação dinamica de memoria:\n");
	ptr = 	malloc(sizeof(int));
	if(ptr==NULL){
		printf("\nMemoria insuficiente.\n");
	} 
	printf("Endereco de ptr: %p\n", ptr);
	*ptr = 90;
	printf("Conteudo de ptr: %d\n", *ptr);
	free(ptr);
	printf("Endereco free de ptr: %p\n", ptr);
	printf("Conteudo free de ptr: %d\n", *ptr);
	
	printf("\nTestando alocação de vetores:\n");
	int i;
	i=1;
	ptr = (int*)malloc(sizeof(int)*10);//ptr foi alocado como um ponteiro de 10 posições, agora ptr se comporta exatamente como um vetor de 10 posições
	for(i=0;i<=10;i++){
		ptr[i]=i;
	}
	int ii;
	for(ii=0;ii<10;ii++){
		printf("ptr[%d] = %d\tEndereço[%d] = %p\n", ii, ptr[ii], ii, ptr);
		free (ptr);
	}
	
	printf("\nTestando aritimetica de ponteiros:\n");
	int *aponta;
	aponta = ptr;//aponta aponta para a o inicio da area alocada por ptr
	*aponta = 10;//colocando 10 na posicao inicial de ptr 
	do{
		aponta++;//avançando com o contador;
		printf("%p\n", aponta); 
		printf("%p\n", *aponta);
	}while(*aponta<=10);
	aponta--;
	free(aponta);
	
}


