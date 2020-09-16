#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define n 100

void select(int *item, int count, int *trocas);

int main (void)
{
    int *item;
    int trocas = 0;
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

    //ordenando elementos 
    select(item, n, &trocas);
    printf("\n");
    printf("\nForma ordenada: ");
    for ( i = 0; i < n; i++)
    {
        printf("%i, ",item[i]); 
    }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    trocas = 0;

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
    select(item, (n*10), &trocas);
    printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*10); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    trocas = 0;
    
    //teste com 10000 elementos
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
    select(item, (n*100), &trocas);
    printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*100); i++)
    // {
    //     printf("%i, ",item[i]); 
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    trocas = 0;
}

void select(int *item, int count, int *trocas)
{
    register int a, b, c;
    int exchange, t;
    for (a = 0; a < count-1; ++a)
    {
        exchange = 0;
        c = a;
        t = item[a];
        for ( b = a+1; b < count; ++b)
        {
            if (item[b] < t)
            {
                c = b;
                t = item[b];
                exchange = 1;
            }
        }
        if (exchange)
        {
            item[c] = item[a];
            item[a] = t;
            *trocas = *trocas + 1;
        }
    }
}

