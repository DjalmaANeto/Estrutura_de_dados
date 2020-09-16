#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define n 100

void shellSort(int *item, int count, int *trocas);

int main(void)
{
    int *item;
    int trocas = 0;
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
    shellSort(item, n, &trocas);
    printf("\n");
    // printf("\nForma ordenada: ");
    // for (i = 0; i < n; i++)
    // {
    //     printf("%i, ", item[i]);
    // }
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
    shellSort(item, (n*10), &trocas);
    printf("\n");
    // printf("\nForma ordenada: ");
    // for ( i = 0; i < (n*10); i++)
    // {
    //     printf("%i, ",item[i]);
    // }
    free(item);
    printf("\n\nTrocas: %i", trocas);
    trocas = 0;

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
    shellSort(item, (n*100), &trocas);
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

void shellSort(int *item, int count, int *trocas)
{
    int i, j, value;
    int gap = 1;
    while (gap < count)
    {
        gap = 3 * gap + 1;
    }
    while (gap > 1)
    {
        gap /= 3;
        for (i = gap; i < count; i++)
        {
            value = item[i];
            j = i - gap;
            while (j >= 0 && value < item[j])
            {
                item[j + gap] = item[j];
                j -= gap;

                *trocas = *trocas + 1;
            }
            item[j + gap] = value;
        }
    }
}
