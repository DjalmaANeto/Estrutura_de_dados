#include<stdio.h>

void troca(int x[], int inicio, int meio, int fim)
{
	int i, aux[10], posicao_livre, inicio_vetorA, inicio_vetorB;
	
	posicao_livre = inicio;	
	inicio_vetorA = inicio;	
	inicio_vetorB = meio+1;	
	
	while(inicio_vetorA<=meio && inicio_vetorB<=fim) 
	{
		if(x[inicio_vetorA] <= x[inicio_vetorB])
		{
			aux[posicao_livre] = x[inicio_vetorA];
			inicio_vetorA = inicio_vetorA+1;
		}
		else
		{
			aux[posicao_livre] = x[inicio_vetorB];
			inicio_vetorB = inicio_vetorB+1;
		}
		
		posicao_livre+=1;
	}
	
	for(i=inicio_vetorA; i<=meio; i++)
	{
		aux[posicao_livre] = x[i];
		posicao_livre+=1;
	}
	
	for(i=inicio_vetorB; i<=fim; i++)
	{
		aux[posicao_livre] = x[i];
		posicao_livre+=1;
	}
	
	for(i=inicio; i<=fim; i++)
	{
		x[i] = aux[i];
	}
}

void merge(int x[], int inicio, int fim)
{
	int meio;
	
	if(inicio<fim)
	{
		meio = (inicio+fim)/2;
		merge(x, inicio, fim);
		merge(x, meio+1, fim);
		troca(x, inicio, meio, fim);
	}
}

main()
{
	int x[10], y[10], z[20];
	int i, j, k;
	
	printf("\n	Vetor A");
	for(i=0; i<=9; i++)
	{
		printf("\nDigite um número: ");
		scanf("%i", &x[i]);
	}
	
	printf("\n	Vetor B");
	for(j=0; j<=9; j++)
	{
		printf("\nDigite um número: ");
		scanf("%i", &y[j]);
	}
	
	merge(x, 0, 9);
	merge(y, 0, 9);
	
	for(k=0; k<=9; k++)
	{
		z[k] = x[k];
	}
	
	for(k= 9; k<=19; k++)
	{
		z[k] = y[k-20];
	}
	
	printf("\n\n	Junção dos vetores");
	
	for(k=0; k<=19; k++)
	{
		printf("\n[%i]", z[k]);
	}
	
	merge(z, 0, 19);
	
	printf("\n\n	Vetor final: ");
	for(k=0; k<=19; k++)
	{
		printf("[%i] ", z[k]);
	}
}
