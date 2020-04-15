#include <iostream>
#include <conio.h>

#define N 8

int main(void){

	using namespace std;

	//registro que representará a lista
	struct LISTA{
		int salario;
		char nome[100];
		LISTA *prox;
	};
	
	//ponteiro inicio apontando para null, lista começa fazia
	LISTA *inicio = NULL;
	//ponteiro fim apontara para o ultimo elemento da lista
	LISTA *fim = NULL;
	//ponteiro auxiliar 
	LISTA *aux;
	//ponteiro auxiliar para a posiçao anterior
	LISTA *anterior;
	
	int i;
	
	//preenchendo a lista 
	for(i=0; i<N; i++){
		//ponteiro novo elemento na lista
		LISTA *novo = new LISTA();
		cout<<"\nIntforme o nome do funcionario "<<i<<" :";
		cin>>novo->nome;
		cout<<"\nIntforme o salario do funcionario "<<i<<" :";
		cin>>novo->salario;
		
		if(inicio == NULL){
				//lista esta vazia, inserindo no primiro elemento
				inicio = novo;
				fim = novo;
				novo->prox = NULL;
		}else{
			//lista nao esta vazia, novo elemento sera inserido de forma decrescente
			anterior = NULL;
			aux = inicio;
		
			while(aux != NULL && novo->salario < aux->salario){
				anterior = aux;
				aux = aux->prox;
			}
			if(anterior == 	NULL){
				//o novo número a ser inserido é menor que todos da lista
				novo->prox = inicio;
				inicio = novo;
			}else if(aux == NULL){
				//novo numero é maior que todos da lista
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}else{
				//numero sera inserido entre dois numeros que ja existem
				anterior->prox = novo;
				novo->prox = aux;
			}
		}
	}
	
	cout<<"\nA - Funcionario de maior salario: ";
	aux = inicio;
	while(aux != NULL){
		if(aux->salario == inicio->salario){
			cout<<aux->nome<<", ";		
		}
		aux = aux->prox;
	}
	
	
	cout<<"\nB - Media salarial: ";
	aux = inicio;
	float soma = 0;
	float media = 0;
	while(aux != NULL){
		soma = soma + aux->salario;
		aux = aux->prox;
	}
	media = soma/N;
	cout<<media;
	
	cout<<"\nC - Digite uma faixa salarial: ";
	float faixa;
	cin>>faixa;
	i = 0;
	aux = inicio;
	while(aux != NULL){
		if(aux->salario >= faixa){
			i++;
		}
		aux = aux->prox;
	}
	if(i == 0){
		cout<<"\nNenhum funcionario na faixa salarial";
	}else{
		cout<<"\n"<<i<<" Funcionarios na faixa salarial";
	}
	
}
