#include <stdio.h>

main (void){
	int inteiro = 666;
	float valor = 66.6;
	char letra = 'd';
	
	int *pontInteiro = &inteiro;
	float *pontValor = &valor;
	char *pontLetra = &letra;
	
	printf("Variavel inteira= %d\nEndereco da variavel inteira= %i\n\n", inteiro, pontInteiro);
	printf("Variavel real= %0.2f\nEndereco da variavel real= %i\n\n",valor, pontValor);
	printf("Variavel char= %c\nEndereco da variavel char= %i\n\n", letra, &pontLetra);
	
	printf("Apos as modificacoes:\n");
	
	*pontInteiro = 999;
	*pontValor =  99.9;
	*pontLetra = 'b';
	
	printf("Endereco da variavel inteira alterada= %d\nVariavel inteira alterada= %i\n\n", pontInteiro, *pontInteiro);
	printf("Endereco da variavel real alterada= %d\nVariavel real alterada= %0.2f\n\n",pontValor, *pontValor);
	printf("Endereco da variavel char alterada= %d\nVariavel char alterada= %c\n\n", pontLetra, *pontLetra);
	
}
