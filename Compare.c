#include <stdlib.h>
#include <stdio.h>
#include <time.h>

double bubbleSort(int N, int array[]);
double selectionSort(int N, int array[]);
double insertSort(int N, int array[]);

clock_t begin, end;

int main()
{
    int best[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int worst[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int average[] = {4, 5, 11, 16, 17, 20, 1, 6, 2, 9, 3, 12, 18, 8, 7, 10, 13, 15, 14, 19};
    int N = 20;

    printf("\n-----Best Case-----\n");
    bubbleSort(N, best);
    selectionSort(N, best);
    insertSort(N, best);

    printf("\n-------Average Case-------\n");
    bubbleSort(N, average);
    selectionSort(N, average);
    insertSort(N, average);

    printf("\n---------Worst Case---------\n");
    bubbleSort(N, worst);
    selectionSort(N, worst);
    insertSort(N, worst);
}

double bubbleSort(int N, int array[])
{
    int i, j, temp;
    printf("\nBUBBLE SORT    ---> ");

    begin = clock();
    for (i = 0; i < N - 1; i++)
    {
        for (j = 0; j < N - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    end = clock();

    printf("Spent: %f\n", ((double)(end - begin) / CLOCKS_PER_SEC));
}

double selectionSort(int N, int array[])
{
    int i, j, small, temp;
    printf("SELECTION SORT ---> ");

    begin = clock();
    for (i = 0; i < N - 1; i++)
    {
        small = i;
        for (j = i + 1; j < N; j++)
        {
            if (array[j] < array[small])
            {
                small = j;
            }
        }
        temp = array[i];
        array[i] = array[small];
        array[small] = temp;
    }
    end = clock();

    printf("Spent: %f\n", ((double)(end - begin) / CLOCKS_PER_SEC));
}

double insertSort(int N, int array[])
{
    int i, j, temp;
    printf("INSERT SORT    ---> ");

    begin = clock();
    for (i = 1; i < N; i++)
    {
        temp = array[i];
        j = i - 1;
        while ((j >= 0) && (array[j] > temp))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = temp;
    }
    end = clock();

    printf("Spent: %f\n", ((double)(end - begin) / CLOCKS_PER_SEC));
}
