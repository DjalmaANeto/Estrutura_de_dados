#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define n 100

void quick(int *item, int count, int *trocas);
void Qs(int *item, int left, int right, int *trocas);

int main(void)
{
    int *item;
    int trocas = 0;
    time_t tempo = 0;
    //incrementanod array
    item = (int *)malloc(n * (sizeof(int)));
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        item[i] = rand() % 100;
    }
    printf("\n-Teste com 100 elementos");
    // printf("\nForma desordenada: ");
    // for (i = 0; i < n; i++)
    // {
    //     printf("%i, ", item[i]);
    // }

    //ordenando elementos
    
    tempo = clock();
    quick(item, n, &trocas);
    tempo = clock() - tempo;
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for (i = 0; i < n; i++)
    // {
    //     printf("%i, ", item[i]);
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
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
    quick(item, (n*10), &trocas);
    tempo = clock() - tempo;
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*10); i++)
    // {
    //     printf("%i, ",item[i]);
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    printf("\nTempo: %0.7lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;

    //teste com 10000 elementos
    item = (int *) malloc((n*100) * (sizeof(int)));
    for ( i = 0; i < (n*100); i++)
    {
        item[i] = rand()%10000;
    }
    printf("\n\n-Teste com 10000 elementos");
    printf("\nForma desordenada: ");
    // for ( i = 0; i < (n*100); i++)
    // {
    //     printf("%i, ",item[i]);
    // }

    //ordenando elementos
    tempo = clock();
    quick(item, (n*100), &trocas);
    tempo = clock() - tempo;
    // printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*100); i++)
    // {
    //     printf("%i, ",item[i]);
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    printf("\nTempo: %0.7lf", ((double)tempo/(CLOCKS_PER_SEC)));
    trocas = 0;
    tempo = 0;
}

void quick(int *item, int count, int *trocas)
{        
    Qs(item, 0, count - 1, trocas);
}
    
void Qs(int *item, int left, int right, int *trocas)
{
    register int i, j;
    int x, y;
    i = left;
    j = right;
    x = item[(left + right) / 2];
    do
    {
        while (item[i] < x && i < right)
            i++;
        while (x < item[j] && j > left)
            j--;
        if (i <= j)
        {
            y = item[i];
            item[i] = item[j];
            item[j] = y;
            i++;
            j--;
            *trocas = *trocas + 1;
        }
    } while (i <= j);
    if (left < j)
        Qs(item, left, j, trocas);
    if (i < right)
        Qs(item, i, right, trocas);
}
