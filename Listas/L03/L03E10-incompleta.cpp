#include <iostream>
#include <conio.h>
using namespace std;

struct LIST
{
    int num;
    LIST *next;
};

int size;
 
void creatList(LIST *head);
void pushBegin(LIST *head, int n);
void pushEnd(LIST *head, int n);
void pull(LIST *head, int n);
void printL(LIST *head);
void randomInsert(LIST *head, int n, int pos);
void change(LIST *head, int n, int n1);
void invert(LIST *head);

int main(void){
    int n, op, n1;
    LIST *head = new LIST();
    creatList(head);

     do
    {
        cout<<"\n1 - Inserir no inicio";
        cout<<"\n2 - Inserir no fim";
        cout<<"\n3 - Imprimir";
        cout<<"\n4 - Excluir da lista";
        cout<<"\n5 - Inserir em qualquer posicao";
        cout<<"\n6 - Trocar posicoes";
        cout<<"\n7 - Inverter a lista";
        cout<<"\n0 - Sair\n";
        cin>>op;
        switch (op)
        {
        case 1:                
            cout<<"\nDigite um numero para inserir no inicio da lista: ";
            cin>>n;
            pushBegin(head, n);
            break;
        
        case 2:
            cout<<"\nDigite um numero para inserir no final da lista: ";
            cin>>n;
            pushEnd(head, n);
            break;
        
        case 3:
            cout<<"\nLista A: ";
            printL(head); 
            break;

        case 4:
            cout<<"\nDigite um numero para excluir da lista: ";
            cin>>n;
            pull(head, n);
            break;
                
        case 5:
            cout<<"\nInforme a posicao para inserir: ";
            cin>>n;
            cout<<"\nInforme o elemento: ";
            cin>>n1;
            randomInsert(head,n1,n);
            break;

        case 6:
            cout<<"\nTrocar elemento: ";
            cin>>n1;
            cout<<" pelo elemento: ";
            cin>>n;
            change(head, n, n1);
            break;
        
        case 7:
            cout<<"\nInvertendo a lista.";
            invert(head);
            printL(head);
            break;

        case 0:
            cout<<"\nSaindo.";
            break;

        default:
            cout<<"\nDigite uma opção válida";
            break;
        }
    } while (op != 0);

}

void creatList(LIST *head){
    head->next = NULL;
}

void pushBegin(LIST *head, int n){
    size++;
    LIST *newNode = new LIST();
    newNode->num = n;

    LIST *oldHead;
    oldHead = head->next;
    head->next = newNode;
    newNode->next = oldHead;
}

void pushEnd(LIST *head, int n){
    size++;
    LIST *newNode = new LIST();
    newNode->num = n;
    newNode->next = NULL;

    if (head->next == NULL)
    {
        head->next = newNode;
    }else
    {
        LIST *aux;
        aux = head->next;
        while (aux->next != NULL)
        {
            aux = aux->next;
        }
        aux->next = newNode;
    }
}

void pull(LIST *head, int n){
    LIST *aux = new LIST();
    LIST *back = new LIST();

    if (head == NULL)
    {
        cout<<"\nLista vazia";
    }
    else
    {
        aux = head;
        while (aux != NULL)
        {
            if (aux->num == n){
                if(aux == head)
                {
                    head = aux->next;
                    delete(aux);
                    aux = head;
                }
                else if (aux->next == NULL)
                {
                    back->next = NULL;
                    delete(aux);
                    aux = NULL;
                }else
                {
                    back->next = aux->next;
                    delete(aux);
                    aux = back->next;
                }
                
            }else
            {
                back = aux;
                aux = aux->next;
            }
        }   
    }
}

void printL(LIST *head){
   LIST *aux;
   aux = head->next;

    if(head == NULL){
        cout<<"\nLista vazia.";
        return;
    }else
    {
        while (aux != NULL)
        {
            cout<<aux->num<<" - ";
            aux = aux->next;
        }
    }
    cout<<"NULL";
}


void randomInsert(LIST *head, int n, int pos){
    if(pos >= 0 && pos <= size)
    {
        if(pos == 0)
        {
            pushBegin(head, n);
        }
        else if(pos == size)
        {
            pushEnd(head, n);   
        }else
        {
            int i;
            LIST *aux = head->next;
            LIST *back = head;
            LIST *newNode = new LIST();
            newNode->num = n;
            for (i = 1; i < pos; i++)
            {
                back = aux;
                aux = aux->next;
            }
            back->next = newNode;
            newNode->next = aux;   
        }
    }
    else
    {
        cout<<"\nElemento invalido.";
    }
}

void change(LIST *head, int n, int n1){
    LIST *aux = head->next;
    LIST *back = head;
    
    while(aux->num != n)
    {
        back = aux;
        aux = aux->next;
    }
    aux->num = n1;

    aux = head->next;
    back = head;
    while(aux->num != n1)
    {
        back = aux;
        aux = aux->next;
    }
    aux->num = n;
}

void invert(LIST *head){
    LIST *aux = head;
    LIST *inverse = new LIST();
    while (aux != NULL)
    {
        pushBegin(inverse, aux->num);
        aux = aux->next;
    }
    //testando lista inverse
    // aux = inverse;
    // while (aux != NULL)
    // {
    //     cout<<aux->num<<" ";
    //     aux = aux->next;
    // }
    delete(head);
    head->next = inverse;
}


