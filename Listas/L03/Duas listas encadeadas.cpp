#include <conio.h>
#include <iostream>
#include <string.h>

using namespace std;

struct LIST
{
    int num;
    LIST *next;
};

void pushBegin(LIST *head, int n);
void printL(LIST *head);

int main(void){
    int op, num;
    char l[1];
    
    LIST *headA;
    LIST *headB;
    
    do
    {
        cout<<"\n1 - Inserir no inicio";
        cout<<"\n3 - Imprimir";
        cout<<"\n7 - Sair\n";
        cin>>op;
        switch (op)
        {
        case 1:
                do
                {
                    cout<<"\nDigite lista a ou b: ";
                    cin>>l;
                } while (strcmp(l,"a") != 0 && strcmp(l,"b") != 0);
                if (strcmp(l,"a") == 0)
                {
                    cout<<"\nDigite um numero para inserir no inicio da lista a: ";
                    cin>>num;
                    pushBegin(headA, num);
                }else if (strcmp(l,"b") == 0)
                {
                    cout<<"\nDigite um numero para inserir no inicio da lisa b: ";
                    cin>>num;
                    pushBegin(headB, num);
                }            
            break;
        
        case 3:
            cout<<"\nLista A: ";
            printL(headA);
            cout<<"\nLista B: ";
            printL(headB);
            break;

        default:
            cout<<"\nDigite uma opção válida";
            break;
        }
    } while (op != 7);
    

}

void pushBegin(LIST *head, int n){
    LIST *t = new LIST();
    t->num = n;

    if (head == NULL){
        head = t;
        head->next = NULL;
        return;
    }
    t->next = head;
    head = t;
}


void printL(LIST *head){
    LIST *t;
    if (head == NULL){
        cout<<"\nLista vazia";
        return;
    }
    while (t->next != NULL)
    {
        cout<<t->num<<" - ";
        t = t->next;
    }   
}