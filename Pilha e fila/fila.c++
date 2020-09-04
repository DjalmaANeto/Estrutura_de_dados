#include <iostream>
#include <conio.h>

using namespace std;

struct FILA
{
    int num;
    FILA *prox;
};

int main(){
    //a fila esta vazia, logo, o ponteiro inicio tem o valor null a operação de remoção acontece no inicio e a operação de inserção acontece no fim 
    FILA *inicio = NULL;
    FILA *fim = NULL;
    //o ponteiro aux é um ponteiro auxiliar 
    FILA *aux;
    //apresentando o menu de opções 
    int op;
    do
    {
        cout<<"\nMENU\n";
        cout<<"\n1 - Inserir na fila";
        cout<<"\n2 - Consultar toda a fila";
        cout<<"\n3 - Remover da fila";
        cout<<"\n4 - Esvaziar a fila";
        cout<<"\n5 - Sair";
        cout<<"\nDigite sua opção: ";
        cin>>op;
        if (op < 1 || op > 5)
        {
            cout<<"Opção inválida!!";
        }
        
        if (op == 1)
        {
            cout<<"Digite o número a ser inserido na fila: ";
            FILA *novo = new FILA();
            cin>>novo->num;
            novo->prox = NULL;

            if (inicio == NULL)
            {
                /* A lista esta vazia o numero inserido será o primeiro e o último da lista */
                inicio = novo;
                fim = novo;
            }
            else
            {
                /* já existe um início */
                fim->prox = novo;
                fim = novo;
            }
        }

        if (op == 2)
        {
            /* fila contem elementos e estes serão mostrados do primeiro inserido ao último */
            cout<<"\nConsultando toda a fila \n";
            aux = inicio;
            while (aux != NULL)
            {
                cout<<aux->num<<" ";
                aux = aux->prox;
            }   
        }
        
        if (op == 3)
        {
            if (inicio == NULL)
            {
                /* a fila está vazia */
                cout<<"Fila vazia!!";
            }
            else
            {
                /* a fila contem elementos e o primeiro elemento inserido será removido */
                aux = inicio;
                cout<<"Número "<<inicio->num<<" removido";
                inicio = inicio->prox;
                delete(aux);
            }
        }

        if (op == 4)
        {
            if (inicio == NULL)
            {
                /* a fila está vazia */
                cout<<"Fila vazia!!";
            }
            else
            {
                //a fila será esvaziada 
                aux = inicio;
                while (aux != NULL)
                {
                    inicio = inicio->prox;
                    delete(aux);
                    aux = inicio;
                }
                cout<<"Fila esvaziada";
            }
        }
        getch();
    } while (op != 5);
    
}