#include <iostream>
#include <conio.h>

int main(void){
	using namespace std;
	
	//definindo o registrlista
	struct LISTA{
		int num;
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
	
	//menu de opções 
	int op, numero, achou;
	do{
		cout<<"\n\nMenu:\n";
		cout<<"\n1 - Inserir no inicio da lista";
		cout<<"\n2 - Inserir no fim da lista";
		cout<<"\n3 - Consultar lista do inicio ao fim";
		cout<<"\n4 - Consultar lista do fim ao inicio";
		cout<<"\n5 - Remover da lista";
		cout<<"\n6 - Esvaziar a lista";
		cout<<"\n7 - Sair\n";
		cin>>op;
		
		if(op < 1 || op > 7){
			cout<<"\nOpcao invalida.";
		}
		
		//Inserindo no início da lista
		if(op == 1){
			cout<<"\nDigite o número a ser inserido: ";
			//ponteiro novo elemento na lista
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
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
			cout<<"\nNumero inserido no inicio da lista\n";	
		}
		
		//inserindo no final da lista
		if(op == 2){
			cout<<"\nDigite o número a ser inserido: ";
			//ponteiro novo elemento na lista
			LISTA *novo = new LISTA();
			cin>>novo->num;
			
			if(inicio == NULL){
				//a lista esta vazia e o elemento sera inserido na primeira posição
				inicio = novo;
				fim = novo;
				novo->prox = NULL;
				novo->ant = NULL;
			}else{
				//lista contem elementos e o novo elemento será inserido no fim da lista
				fim->prox = novo;
				novo->ant = fim;
				novo->prox = NULL;
				fim = novo;
			}
			cout<<"\nNumero inserido no fim da lista.\n";
		}
		
		//imprimindo a lista do inicio ao fim
		if(op == 3){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elementos sera imprimida do inicio ao fim
				cout<<"\nConsultando a lista do inicio ao fim: \n";
				cout<<"NULL - ";
				aux = inicio;
				while(aux != NULL){
					cout<<aux->num<<" - ";
					aux = aux->prox;
				}
				cout<<"NULL";
			}
		}
		
		//imprimindo a lista do fim ao inicio
		if(op == 4){
			if(inicio == NULL){
				//lista esta vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elementos sera imprimida do fim ao inicio 
				cout<<"\nConsultando a lista do fim ao inicio: \n";
				cout<<"NULL - ";
				aux = fim;
				while(aux != NULL){
					cout<<aux->num<<" - ";
					aux = aux->ant;
				}
				cout<<"NULL";
			}	
		}
		
		//removendo da lista
		if(op == 5){
			if(inicio == NULL){
				//lista está vazia 
				cout<<"\nLista vazia.";
			}else{
				//lista contem elemeentos
				cout<<"\nDigite o elemento a ser removido: ";
				cin>>numero;
				//todas as ocorrencias da lista igual a numero serao exclidas
				aux = inicio;
				achou = 0;
				while(aux != NULL){
					if(aux->num == numero){
						//numero digitado foi encontrado e sera excluido
						achou++;
						if(aux == inicio){
							//numero a ser removido é o primeriro
							inicio = aux->prox;
							if(inicio != NULL){
								inicio->ant = NULL;
								delete(aux);
								aux = inicio;
							}	
						}else if( aux == fim){
							//numero a ser removido é o último da lista
							fim = fim->ant;
							fim->prox = NULL;
							delete(aux);
							aux = NULL;
						}else{
							//numero a ser removido está no meio da lista
							aux->ant->prox = aux->prox;
							aux->prox->ant = aux->ant;
							//auxiliar 2
							LISTA *aux2;
							aux2 = aux->prox;
							delete(aux);
							aux = aux2;
						}
					}else{
						aux = aux->prox;
					} 
				}
				if(achou == 0){
					cout<<"\nNumero não encontrado.";
				}else if(achou == 1){
					cout<<"\nNumero removido 1 vez.";
				}else{
					cout<<"\nNumero removido "<<achou<<" vezes";
				}
			}
		}
		
		if(op == 6){
			if(inicio == NULL){
				//lista esta vazia
				cout<<"\nLista vazia.";
			}else{
				//esvaziando lista
				aux = inicio;
				while(aux != NULL){
					inicio = inicio->prox;
					delete(aux);
					aux = inicio;
				}
				cout<<"\nLista esvaziada.";
			}
		}
		
	}while(op!=7);		
}





