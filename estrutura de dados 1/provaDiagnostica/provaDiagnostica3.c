#include <stdio.h>

void main(){
	
int *v;
int n, i;

printf("Escreva o tamanho do seu vetor:");
scanf("%d",&n);

v = malloc(n * sizeof(int));

printf("\nEscreva os valores par seu vetor:\n");
for(i=0;i<n;i++){
	scanf("%d",&v[i]);
}

for(i=0;i<n;i++)
	printf("\nVetor posicao %i: %d",i, v[i]);
	
}
