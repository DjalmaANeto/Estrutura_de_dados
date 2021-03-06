#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define n 100

void insert(int *item, int count, int *trocas);

int main(void)
{
    int *item;
    int trocas = 0;
    time_t tempo = 0;
    //incrementanod array
    item = (int *) malloc(n * (sizeof(int)));
    int i;
    srand(time(NULL));
    for ( i = 0; i < n; i++)
    {
        item[i] = rand()%100;
    }
    printf("\n-Teste com 100 elementos");
    // printf("\nForma desordenada: ");
    // for ( i = 0; i < n; i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    
    //oredenando elementos
    tempo = clock(); 
    insert(item, n, &trocas);
    tempo = clock() - tempo;
    //imprimindo odenaçao
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < n; i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    free(item);
    printf("\nTrocas: %i", trocas);
    printf("\nTempo: %0.7lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;

    //teste com 1000 elementos
    item = (int *) malloc((n*10) * (sizeof(int)));
    for ( i = 0; i < (n*10); i++)
    {
        item[i] = rand()%1000;
    }
    printf("\n\n-Teste com 1000 elementos");
    // printf("\nForma desordenada: ");
    // for ( i = 0; i < (n*10); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }

    //ordenando elementos 
    tempo = clock();
    insert(item, (n*10), &trocas);
    tempo = clock() - tempo;
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*10); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    free(item);
    printf("\nTrocas: %i", trocas);
    printf("\nTempo: %0.7lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;

    //teste com 1000 elementos
    item = (int *) malloc((n*100) * (sizeof(int)));
    for ( i = 0; i < (n*100); i++)
    {
        item[i] = rand()%10000;
    }
    printf("\n\n-Teste com 10000 elementos");
    // printf("\nForma desordenada: ");
    // for ( i = 0; i < (n*100); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }

    //ordenando elementos
    tempo = clock(); 
    insert(item, (n*100), &trocas);
    tempo = clock() - tempo;
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*100); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    free(item);
    printf("\nTrocas: %i", trocas);
    printf("\nTempo: %0.7lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;
}

void insert (int *item, int count, int *trocas)
{ 
    register int a, b, t;
    for (a = 1; a < count; ++a) 
    {
        t = item[a];
        for (b = a - 1; b >= 0 && t < item[b]; b--){
            item[b+1] = item[b];
            *trocas = *trocas + 1; 
        }
        item[b+1] = t;
    } 
}



