#include <iostream>
#include <conio.h>

//definindo a struct lista 
struct LISTA{
	int num;
	struct LISTA *prox;//ponteiro de encadeamento 
};

int testaOrdem(LISTA *inicio);
void busca(LISTA *inicio);

using namespace std;

int main(void){
	
	int op, numero, achou;
	
	//lista inicia vazia
	//ponteiro inicio contera sempre o primeiro elemento da lista
	LISTA *inicio = NULL;
	
	//ponteiro fim contera o final da lista 
	LISTA *fim = NULL;
	
	//criando um ponteiro auxiliar
	LISTA *aux = NULL;
	
	//ponteiro auxiliar da versao anterior
	LISTA *anterior;
	
	do{
//		clrscr();
		cout<<"\n\nMENU";
		cout<<"\n1 - Inserir numero no inicio da lista";
		cout<<"\n2 - Inserir numero no fim da lista";
		cout<<"\n3 - Consutar toda a lista";
		cout<<"\n4 - Remover da lista";
		cout<<"\n5 - Esvaziar a lista";
		cout<<"\n6 - Verificar ordem crescente";
		cout<<"\n7 - Buscar numero";
		cout<<"\n8 - Sair";
		cout<<"\nDigite a opcao: ";
		cin>>op;
			
		if(op < 1 || op > 8){
			cout<<"\nOpcao invalida";
		}
		
		if(op == 1){//inserindo no inicio da lista			
			cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox == NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				novo->prox = inicio;
				inicio = novo;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no inicio da lista!" ;
		}
		
		if(op == 2){//inserindo no fim da lista
			
			cout<<"\nDigite o numero a ser inserido na lista: ";
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			//verificando se a lista esta vazia
			if(inicio == NULL){
				//lista vazia, insere-se no primeiro
				inicio = novo;
				fim = novo;
				fim->prox == NULL;
			}else{
				//se a lista ja contem elementos, insere-se no inicio 
				fim->prox = novo;
				fim = novo;
				fim->prox = NULL;
			}
			cout<<"\nNumero "<< novo->num <<" inserido no inicio da lista!" ;
		}
		
		if(op == 3){//consulta toda a lista
			//verifica se lista esta vazia 
			if(inicio == NULL){
				//lista esta vazia
				cout<<"\nLista vazia!";
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
		
		if(op == 4){//Remove item da lista 
			//verifica se lista esta vazia 
			if(inicio == NULL){
				//lista esta vazia
				cout<<"\nLista vazia!";
			}else{
				//removendo elemento da lista
				cout<<"\nDigite o elemeto a ser removido: ";
				cin>>numero;
				//todos os itens da lista igual a numero sera removido
				aux = inicio;
				anterior = NULL;
				achou = 0;
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
							//o numero a ser removido é o último da lista
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
					cout<<"\nNumero nao encontrado!";
				}else if(achou == 1){
					cout<<"\nNumero "<<numero<<" removido 1 vez";
				}else{
					cout<<"\nNumero "<<numero<<" removido "<<achou<<" vezes"; 
				}
			}
		}
		
		if(op == 5){//esvaziar toda a lista 
			//verificando se a lista esta vazia 
			if(inicio == NULL){
				cout<<"\nLista esta vazia!";
			}else{
				//lista sera esvaziada
				aux = inicio;
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"\nlista esvaziada";
			}
		}
		
		if(op == 6){//verifica ordem crescente
			if(testaOrdem(inicio) == 0){
				cout<<"\nFora de ordem crescente.";
			}else if(testaOrdem(inicio) == 1){
				cout<<"\nEm ordem crescente.";
			}else if(testaOrdem(inicio) == 2){
				cout<<"\nlista vazia.";
			}
		}
		
		if(op == 7){//busca numero
			busca(inicio);
		}
		
	}while(op != 8);
}

int testaOrdem(LISTA *inicio){
	if(inicio != NULL){
		LISTA *no = inicio;//ponteiro no servindo de auxiliar
		while(no->prox != NULL){
			if(no->num > no->prox->num){
				return 0; //fora da ordem crescente
			}
			no = no->prox;
		}
		return 1;//dentro da ordem crescente
	}else{
		return 2;
	}
}

void busca(LISTA *inicio){
	int numero, cont;
	
	cout<<"\nInforme um numero a ser buscado na lista: ";
	cin>>numero;
	
	LISTA *no = inicio;
	while(no != NULL){
		if(no->num == numero){
			cont++;
		}
		no = no->prox;
	}
	
	if(cont == 0){
		cout<<"\nNumero nao encontrado.";
	}else{
		cout<<"\nNumero encontrado "<<cont<<" vezes.";
	}
}





