#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define n 100

void quick(int *item, int count);
void Qs(int *item, int left, int right);

int main(void)
{
    int *item;
    //incrementanod array
    item = (int *)malloc(n * (sizeof(int)));
    int i;
    srand(time(NULL));
    for (i = 0; i < n; i++)
    {
        item[i] = rand() % 100;
    }
    printf("\n-Teste com 100 elementos");
    printf("\nForma desordenada: ");
    for (i = 0; i < n; i++)
    {
        printf("%i, ", item[i]);
    }

    //ordenando elementos
    quick(item, n);
    printf("\n");
    printf("\nForma ordenada: ");
    for (i = 0; i < n; i++)
    {
        printf("%i, ", item[i]);
    }
    free(item);

    //teste com 1000 elementos
    item = (int *) malloc((n*10) * (sizeof(int)));
    for ( i = 0; i < (n*10); i++)
    {
        item[i] = rand()%1000;
    }
    printf("\n\n-Teste com 1000 elementos");
    printf("\nForma desordenada: ");
    for ( i = 0; i < (n*10); i++)
    {
        printf("%i, ",item[i]);
    }

    //ordenando elementos
    quick(item, (n*10));
    printf("\n");
    printf("\nForma ordenada: ");
    for ( i = 0; i < (n*10); i++)
    {
        printf("%i, ",item[i]);
    }
    free(item);

    //teste com 10000 elementos
    item = (int *) malloc((n*100) * (sizeof(int)));
    for ( i = 0; i < (n*100); i++)
    {
        item[i] = rand()%10000;
    }
    printf("\n\n-Teste com 10000 elementos");
    printf("\nForma desordenada: ");
    for ( i = 0; i < (n*100); i++)
    {
        printf("%i, ",item[i]);
    }

    //ordenando elementos
    quick(item, (n*100));
    printf("\n");
    printf("\nForma ordenada: ");
    for ( i = 0; i < (n*100); i++)
    {
        printf("%i, ",item[i]);
    }
    free(item);
}

void quick(int *item, int count)
{        
    Qs(item, 0, count - 1);
}
    
void Qs(int *item, int left, int right)
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
        }
    } while (i <= j);
    if (left < j)
        Qs(item, left, j);
    if (i < right)
        Qs(item, i, right);
}
