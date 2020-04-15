#include <stdio.h>
#include <stdlib.h>


main(){
	
	int **v;
	int l, c, i, j;
	
	printf("Escreva as colunas da sua matriz:");
	scanf("%d",&c);
	
	v = (int **) calloc (c, sizeof(int *));
	
	printf("Escreva as linhas da sua matriz:");
	scanf("%d",&l);
	
	v = (int **) calloc (l, sizeof(int *));
	
	if(v == NULL){
		printf("** Erro: Memoria insuficiente");
		return (NULL);
	}
		
	for(i=0;i<l;i++){
		printf("\nEscreva os valores para linha %d:\n", i+1);
		scanf("%d",&v[i]);
	}
	
	for(j=0;j<c;j++){
		printf("\nEscreva os valores para coluna %d:\n", j+1);
		scanf("%d",&v[j]);
	}
	
	for(i=0;i<l;i++){
		printf("%d\t",v[i]);
		for(j=0;j<c;j++){
			printf("%d\n",v[j]);
		}	
	}

}
