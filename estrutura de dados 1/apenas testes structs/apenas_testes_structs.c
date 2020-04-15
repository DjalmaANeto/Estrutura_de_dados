#include <stdio.h>
#include <stdlib.h>

typedef struct{
	float Peso;
	int Idade;
	float Altura;
}Pessoa;

void ImprimePessoa(Pessoa P);
Pessoa setPessoa(float Peso, int Idade, float Altura);
void setPessoaP(Pessoa *P, float Peso, int Idade, float Altura);


Pessoa setPessoa(float Peso, int Idade, float Altura){
	Pessoa P;
	P.Idade = Idade;
	P.Peso = Peso;
	P.Altura = Altura;
}

void setPessoaP(Pessoa *P, float Peso, int Idade, float Altura){
	(*P).Idade=Idade;
	P->Peso = Peso;
	P->Idade = Idade;
	P->Altura = Altura;
}
	


void ImprimePessoa(Pessoa P){
	printf("Idade: %d\tPeso: %0.2f\tAltura: %0.2f\n", P.Idade, P.Peso, P.Altura);
}

void main(){
	
	int i;
	int idade;
	float altura, peso;;
	
	Pessoa John, P2, P3;
	Pessoa Povo[4];
	
	John.Idade = 15;
	John.Peso = 60.0;
	John.Altura = 1.85;
	
	Povo[4].Idade = 22;
	Povo[4].Peso = 62;
	Povo[4].Altura = 1.89;
	
	P2 = Povo[4];
	P2.Idade++;
	P2.Peso++;
	P2.Altura = P2.Altura + 0.2;
	
	ImprimePessoa(John);
	ImprimePessoa(P2);
	ImprimePessoa(Povo[4]);
	
	for(i=0;i<2;i++){
		printf("\nPessoa %i", i);
		printf("\nIdade: ");
		scanf("%i", &idade);
		printf("\nPeso: ");
		scanf("%f", &peso);
		printf("\nAltura: ");
		scanf("%f", &altura);
		P3 = Povo[i];
		Povo[i] = setPessoa(peso, idade, altura);
	}	
	
	for(i=0;i<6;i++){
		ImprimePessoa(Povo[i]);
	}
	
	printf("\nTestando a passagem de struct por referencia:\n");
	Pessoa P4;
	printf("Agora informe os dados da 4ª pessoa:\n");
	printf("\nIdade: ");
	scanf("%i", &idade);
	printf("\nPeso: ");
	scanf("%f", &peso);
	printf("\nAltura: ");
	scanf("%f", &altura);
	setPessoaP(&P4, peso, idade, altura);
	ImprimePessoa(P4);
}
