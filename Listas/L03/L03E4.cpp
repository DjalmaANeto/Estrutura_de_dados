	#include <iostream>
	#include <conio.h>
	#include <string.h>
	
	#define N 6
	
	int main(void){
		using namespace std;
		
		//definindo o registrlista
		struct LISTA{
			int salario;
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
		//preenchendo lista
		for(i = 1; i <= N; i++){
			LISTA *novo = new LISTA();
			cout<<"\nInforme o nome do "<<i<<" funcionario: ";
			cin>>novo->nome;
			cout<<"\nInforme o salario do "<<i<<" funcionario: ";
			cin>>novo->salario;
			
			if(inicio == NULL){
					//a lista esta vazia e o elemento sera inserido na primeira posição
					novo->prox = NULL;
					novo->ant = NULL;
					inicio = novo;
					fim = novo;
			}else{
				//a lista contem elementos, sera inserido na ordem crescente 
				aux = inicio;
				while(aux != NULL && novo->salario > aux->salario){
				aux = aux->prox;
			}
			if(aux == inicio){
				//numero a ser inserido é menosr que todos da lista
				//sera inserido no inicio
				novo->prox = inicio;
				novo->ant = NULL;
				inicio->ant = novo;
				inicio = novo;
			}else if(aux == NULL){
				//numero a ser inserido é maior que todos na lista
				//sera inserido no fim da lista
				fim->prox = novo;
				novo->ant = fim;
				fim = novo;
				fim->prox = NULL;
			}else{
				//o novo número a ser inserido será inserido entre dois 
				//números que já estão na lista
				novo->prox = aux;
				aux->ant->prox = novo;
				novo->ant = aux->ant;
				aux->ant = novo;
			}					
		}
	}
	
	//aprenstando nomes imposto e total a receber
	aux = inicio;
	while(aux != NULL){
		if(aux->salario <= 850){
			cout<<"\nNome: "<<aux->nome<<" \tImposto: Insento \tA receber: "<<aux->salario - (aux->salario * 0);
		}else if(aux->salario >= 850 && aux->salario <= 1200){
			cout<<"\nNome: "<<aux->nome<<" \tImposto: 10% \tA receber: "<<aux->salario - (aux->salario * 0,1);
		}else if(aux->salario >= 1200){
			cout<<"\nNome: "<<aux->nome<<" \tImposto: 20% \tA receber: "<<aux->salario - (aux->salario * 0,2);
		}
		aux = aux->prox;
	}
	
	//mostrando funcionarios a partir de uma letra digitada
	char letra[100];
	cout<<"\n\nInforme uma letra para pesquisar funcionarios: ";
	cin>>letra;
	
	i = 0;
	aux = inicio;
	while(aux != NULL){
		if(strcmp(letra, aux->nome) == 0){	
			cout<<"\n"<<aux->nome<<"\tsalario: "<<aux->salario;
			i++;
		}
		aux = aux->prox;
	}
	if(i == 0){
		cout<<"\nNenhum funcionario encontrado.";
	}
	
	//a)listando nome e salarios por ordem crescente de salarios
	cout<<"\n\na) Nomes e salarios por ordem crescente de salarios: ";
	aux = inicio;
	while(aux != NULL){
		cout<<"\nNome: "<<aux->nome<<"\tSalario: "<<aux->salario;
		aux = aux->prox;
	}
	
	//a)listando nome e salarios por ordem decrescente de salarios
	cout<<"\n\nb) Nomes e salarios por ordem decrescente de salarios: ";
	aux = fim;
	while(aux != NULL){
		cout<<"\nNome: "<<aux->nome<<"\tSalario: "<<aux->salario;
		aux = aux->ant;
	}
}
