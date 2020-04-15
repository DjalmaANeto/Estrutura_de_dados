#include <iostream>
#include <conio.h>

int main(void){
	using namespace std;
	
	//definindo o registrlista
	struct LISTA{
		int notaf;
		char nome[100];
		LISTA *prox;
		LISTA *ant;
	};
	
	//ponteiro de inicio, contera o primeiro esdereço da lista
	//inicia com NULL
	LISTA *inicio = NULL;
	
	//ponteiro fim contera o último endereço da lista
	LISTA *fim = NULL;
	
	//ponteiro auxiliar 
	LISTA *aux;
		
	int i;
	
	for(i = 0; i <= 5; i++){
		LISTA *novo = new LISTA();
		cout<<"\nInforme o nome do aluno "<< i <<" :";
		cin>>novo->nome;
		cout<<"\nInforme a nota do aluno "<< i <<" :";
		cin>>novo->notaf;
		
		if(inicio == NULL){
			//a lista esta vazia e o elemento sera inserido na primeira posição
			inicio = novo;
			fim = novo;
			novo->prox = NULL;
			novo->ant = NULL;
		}else{
			//a lista já contém elementos, e o novo elemento sera inserido no inicio
			novo->prox = inicio;
			inicio->ant = novo;
			novo->ant = NULL;
			inicio = novo;
		}
	}
	
	//imprimindo aprovados
	int notas = 0;
	aux = inicio;
	while(aux != NULL){
		if(aux->notaf >= 7){
			cout<<"\n"<<aux->nome<<" aprovado";
			notas++;	
		}
		aux = aux->prox;
	}
	if(notas == 0){
		cout<<"\nNenhum aluno aprovado.";
	}
}




