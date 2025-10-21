#include <stdio.h>

#define MAX 100

int arr[MAX];
int size = 0;

void insert(int value, int pos)
{
    if (size >= MAX)
    {
        printf("Array dolu, ekleme yapılamaz\n"); // overflow oluyorr
        return;
    }
    if (pos < 0 || pos > size)
    {
        printf("Gecersiz index\n");
        return;
    }

    for (int i = size; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    size++;
}

void delete(int pos)
{
    if (size <= 0)
    {
        printf("Array is empty\n"); // underflow, olmayan bir elemanı zaten pop()layamayız
        return;
    }
    if (pos < 0 || pos >= size)
    {
        printf("Gecersiz index!\n");
        return;
    }

    for (int i = pos; i < size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    size--;
}

int search(int value)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

int main()
{

    insert(10, 0);
    insert(20, 1);
    insert(15, 1);

    delete(1);
    delete(0);

    int pos = search(20);
    if (pos != -1)
        printf("20 bulundu, pozisyon: %d\n", pos);
    else
        printf("20 bulunamadi\n");

    return 0;
}
