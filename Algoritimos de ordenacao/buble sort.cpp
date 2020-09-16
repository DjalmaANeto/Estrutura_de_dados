#include <iostream>
#include <conio.h>

#define n 3

using namespace std;

int main(){
    int x[4], N, i, aux;

    for ( i = 0; i <= 3; i++)
    {
        cout<<"Digite a posicao "<<i<<" :";
        cin>>x[i];
    }

    for (N = 1; N <= 4; N++)
    {
        for (i = 0; i <= 2; i++)
        {
            if (x[i] > x[i+1])
            {
                aux = x[i];
                x[i] = x[i+1];
                x[i+1] = aux;
            }
        }
    }
    
    for (i = 0; i < 4; i++)
    {
        cout<<i<<" : "<<x[i]<<"\n";
    }

}