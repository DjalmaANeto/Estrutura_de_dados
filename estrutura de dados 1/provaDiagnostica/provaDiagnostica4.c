#include <stdio.h>
#include <stdlib.h>
//ALL HAIL TO TEACHER ALINE BLESS!

//float **Alocando_matriz(int m, int n);

float **Alocando_matriz(int m, int n){

	float **v;//ponteiro matriz bidimensional
	
	int i; //contador
	
	//alocando linhas da matiz 
	v = (float ** )calloc(m, sizeof(float *));
	
	//alocando colunas da matiz
	for ( i = 0; i < m; i++ ) {
      v[i] = (float*) calloc (n, sizeof(float));
	}
	 
	 return (v);
	 
}

void main(){
	
	float **mat; //matriz
	int L, C;//linha e coluna
	int i, j; //contadores
	
	printf("Informe o numero de linhas: ");
	scanf("%f", &L);
	printf("Informe o numero de colunas: ");
	scanf("%f", &C);
	
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			Printf("\nDigite a posicao [%0.2f][%0.2f]", i, j);
			Scanf("%f",&mat[i][j]);	
		}
	}
	
	mat = Alocando_matriz(C,L);
	
	
	
	/*
	for(i=0;i<L;i++){
		for(j=0;j<C;j++){
			
			}
	}
	*/

}


