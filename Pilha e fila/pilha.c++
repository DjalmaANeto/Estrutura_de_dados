#include <iostream> 
#include <stdio.h>
#include <conio.h>

using namespace std;

struct PILHA
{
    int num;
    PILHA *prox;
};

int main()
{
    //a pilha está vazia, logo, o ponteiro topo tem o valor null,
    //as operações de inserção e remoção acontecem no TOPO
    PILHA *topo = NULL;
    //ponteiro auxiliar aux
    PILHA *aux;
    int op;
    do
    {
        cout<<"\nMENU\n";
        cout<<"\n1 - Inserir na pilha";
        cout<<"\n2 - Consultar toda a pilha";
        cout<<"\n3 - Remover da pilha";
        cout<<"\n4 - Esvaziar a pilha";
        cout<<"\n5 - Sair";
        cout<<"\nDigite sua opcao: ";
        cin>>op;

        if(op < 1 || op > 5)
            cout<<"\nOpcao invalida!!";
        
        if (op == 1)
        {
            cout<<"\nDigite o número a ser inserido na pilha: ";
            PILHA *novo = new PILHA;
            cin>>novo->num;
            novo->prox = topo;
            topo = novo;
            cout<<"\nNúmero inserido na pilha!!";
        }
        if (op == 2)
        {
            if (topo == NULL)
            {
                //a pilha está vazia
                cout<<"Pilha vazia!!\n";
            }
            else
            {
                //a pilha contém elementos e estes serão mostrados do último ao primeiro
                cout<<"\nConsultando toda a pilha\n";
                aux = topo;
                while (aux != NULL)
                {
                    cout<<" "<<aux->num<<"\n ";
                    aux = aux->prox;
                }
            }
        }

        if (op == 3)
        {
            if (topo == NULL)
            {
                //pilha esta vazia 
                cout<<"pilha vazia!!\n";
            }
            else
            {
                //a pilha contém elementos e o último elemento inserido sera removido
                aux = topo;
                cout<<"Numero "<<topo->num<<" removido";
                topo = topo->prox;
                delete(aux);
            }
        }

        if (op == 4)
        {
            if (topo == NULL)
            {
                //a pilha está vazia 
                cout<<"Pilha vazia!!\n";
            }
            else
            {
                //a pilha será esvaziada 
                aux = topo;
                while (aux != NULL)
                {
                    topo = topo->prox;
                    delete(aux);
                    aux = topo;
                }
                cout<<"Pilha esvaziada!!\n";
            }
        }
        getch();
    } while (op != 5);
     
}