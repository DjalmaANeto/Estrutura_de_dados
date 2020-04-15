#include <stdio.h>

//exemplos de recursividade 

//fatorial
double fatorial(int n);
//fibonacci
int fibonacci(int numero, int x, int y);
//maximo de um vetor 
int maxR(int v[], int n);

int  main(void){
	int numero, v[numero];
	double f;
	
	//fatorial
	printf("\nDigite o numero para o fatorial: ");
	scanf("%d",&numero);
	
	f = fatorial(numero);
	
	printf("\nFatorial de %d = %.01f", numero, f);
	
	//fibonacci
	printf("\n\nDigite uma posicao para a sequencia fibonacci: ");
	scanf("%d",&numero);
	printf("\n A posicao %d na sequencia fibonacci: %d", numero, fibonacci(numero, 1, 0));
	
	//testando o valor maximo de um vetor
	printf("\n\nDigite o valor máximo de um vetor: ");
	scanf("%d",&numero);
	printf("\nPosicao maxima e: %d", maxR(v,numero));
	
}

double fatorial(int numero){
	double vfat;
	
	if(numero < 1){
		//caso o fatorial de numero <= 1 retorna 1
		return 1;
	}else{
		//recursividade
		return numero * fatorial(numero - 1);
	}
}

int fibonacci(int numero, int x, int y){
	if(numero == 0){
		return 0;
	}
	if(numero > 1){
		return y + fibonacci(numero -1, y, x+y);
	}else{
		return 1;
	}
}

//maximo de um vetor
int maxR(int v[], int n){
	if(n == 1){
		return v[0];
	}else{
		int x;
		x = maxR(v, n-1);
		if(x > v[n-1]){
			return x;
		}else{
			return v[n-1];
		}
	}
} 
