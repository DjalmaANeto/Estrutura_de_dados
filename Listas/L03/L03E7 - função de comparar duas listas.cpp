#include <iostream>
#include <conio.h>
using namespace std;

//definindo a struct lista 
struct LISTA{
	int num;
	struct LISTA *prox;//ponteiro de encadeamento 
};

//lista inicia vazia
//ponteiro inicio contera sempre o primeiro elemento da lista
LISTA *inicio1 = NULL;
LISTA *inicio2 = NULL;

//ponteiro fim contera o final da lista 
LISTA *fim1 = NULL;
LISTA *fim2 = NULL;

//criando um ponteiro auxiliar
LISTA *aux = NULL;
	
//ponteiro auxiliar da versao anterior
LISTA *anterior;

void pushI(LISTA *inicio, LISTA *fim);
void pushF(LISTA *inicio, LISTA *fim);
void print(LISTA *inicio);
void pull(LISTA *inicio, LISTA *fim);
void delet(LISTA *inicio);
int menorValor(LISTA *inicio);

int main(void){

	int op;

	
	do{
//		clrscr();
		cout<<"\nMENU";
		cout<<"\n1 - Inserir numero no inicio da lista";
		cout<<"\n2 - Inserir numero no fim da lista";
		cout<<"\n3 - Consutar toda a lista";
		cout<<"\n4 - Remover da lista";
		cout<<"\n5 - Esvaziar a lista";
		cout<<"\n6 - Encontra o menor valor";
		cout<<"\n7 - Sair";
		cout<<"\nDigite a opcao: ";
		cin>>op;
			
		if(op < 1 || op > 7){
			cout<<"\nOpcao invalida";
		}
		
		if(op == 1){//inserindo no inicio da lista			
			do{
				cout<<"\nInserir no inicio da lista1 ou lista2: ";
				cin>>op;
				if (op != 1 && op != 2)
				{
					cout<<"\nEscolha entre a lista 1 ou 2.";
				}
			} while (op != 1 && op != 2);
			if (op == 1)
			{
				pushI(inicio1, fim1);
			}else
			{
				pushI(inicio2, fim2);
			}
		}
		
		if(op == 2){//inserindo no fim da lista
			
			
		}
		
		if(op == 3){//consulta toda a lista
			print(inicio1);
			cout<<"\n";
			print(inicio2);		
		}
		
		if(op == 4){//Remove item da lista 
			
		}
		
		if(op == 5){//esvaziar toda a lista 
			
		}
		
		if(op == 6){//consultando o menor valor
			do{
				cout<<"\nConsultar lista1 ou lista2: ";
				cin>>op;
				if (op != 1 && op != 2)
				{
					cout<<"\nEscolha entre a lista 1 ou 2.";
				}
			} while (op != 1 && op != 2);
			if (op == 1)
			{
				cout<<"\nMenor valor: "<<menorValor(inicio1)<<"\n";
			}else
			{
				cout<<"\nMenor valor: "<<menorValor(inicio2)<<"\n";
			}
		}
		
	}while(op != 7);
}

void pushI(LISTA *inicio, LISTA *fim){
	cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				novo->prox = inicio;
				inicio = novo;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no inicio da lista!" ;
}

void pushF(LISTA *inicio, LISTA *fim){
	cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox = NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no fim da lista!" ;
}

void print(LISTA *inicio){
	//verifica se lista esta vazia 
	if(inicio == NULL){
		//lista esta vazia
		cout<<"Lista vazia!";
	}else{
		//lista contem elementos a serem mostrados 
		cout<<"\nConsultando toda a lista: \n";
		aux = inicio;
		while(aux != NULL){
			cout<<aux->num<<" - ";
			aux = aux->prox;
		}
	}
}

void pull(LISTA *inicio, LISTA *fim){
//verifica se lista esta vazia
			int numero;
			if(inicio == NULL){
				//lista esta vazia
				cout<<"Lista vazia!";
			}else{
				//removendo elemento da lista
				cout<<"\nDigite o elemeto a ser removido: ";
				cin>>numero;
				//todos os itens da lista igual a numero sera removido
				aux = inicio;
				anterior = NULL;
				int achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						//numero encontrado na lista, sera removido removido
						achou++;
						if(aux == inicio){
							//numero encontrado na primeira posicao
							inicio = aux->prox;
							delete(aux);
							aux = inicio;
						}else if(aux == fim){
							//o numero a ser removido � o �ltimo da lista
							anterior->prox = NULL;
							fim = anterior;
							delete(aux);
							aux = NULL;
						}else{
							//numero a ser removido esta no meio da lista
							anterior->prox = aux->prox;
							delete(aux);
							aux = anterior->prox;
						}	
					}else{
						anterior = aux;
						aux = aux->prox;
					}
				}
				if(achou == 0){
					cout<<"Numero nao encontrado!";
				}else if(achou == 1){
					cout<<"Numero "<<numero<<" removido 1 vez";
				}else{
					cout<<"Numero "<<numero<<" removido "<<achou<<" vezes"; 
				}
			}
}

void delet(LISTA *inicio){
	//verificando se a lista esta vazia 
	if(inicio == NULL){
		cout<<"Lista esta vazia!";
	}else{
	//lista sera esvaziada
	aux = inicio;
		while(aux != NULL){
			inicio = inicio->prox;
			delete(aux);
			aux = inicio;
		}
	cout<<"lista esvaziada";
	}
}

int menorValor(LISTA *inicio){
	int menor = inicio->num;
	if (inicio == NULL){
		return 0;
	}
	while(inicio != NULL){
		if(inicio->num < menor){
			menor = inicio->num;
		}
		inicio = inicio->prox;
	}
	return menor;
}















