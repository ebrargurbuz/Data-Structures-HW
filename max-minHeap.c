#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX 100

typedef struct
{
    int arr[MAX];
    int size;
    bool isMinHeap;
} Heap;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

bool compare(int a, int b, bool isMin)
{
    return isMin ? (a < b) : (a > b);
}

void heapifyUp(Heap *h, int i)
{
    while (i > 0)
    {
        int parent = (i - 1) / 2;
        if (compare(h->arr[i], h->arr[parent], h->isMinHeap))
        {
            swap(&h->arr[i], &h->arr[parent]);
            i = parent;
        }
        else
        {
            break;
        }
    }
}

void heapifyDown(Heap *h, int i)
{
    while (true)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int target = i;

        if (left < h->size && compare(h->arr[left], h->arr[target], h->isMinHeap))
            target = left;

        if (right < h->size && compare(h->arr[right], h->arr[target], h->isMinHeap))
            target = right;

        if (target == i)
            break;

        swap(&h->arr[i], &h->arr[target]);
        i = target;
    }
}

void insert(Heap *h, int value)
{
    if (h->size >= MAX)
    {
        printf("Hata: Heap dolu!\n");
        return;
    }
    h->arr[h->size] = value;
    heapifyUp(h, h->size);
    h->size++;
}

int extractRoot(Heap *h)
{
    if (h->size <= 0)
    {
        return h->isMinHeap ? INT_MAX : INT_MIN;
    }

    int root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);

    return root;
}

void printHeap(Heap *h)
{
    for (int i = 0; i < h->size; i++)
        printf("%d ", h->arr[i]);
    printf("\n");
}

int main()
{
    Heap minHeap = {.size = 0, .isMinHeap = true};
    Heap maxHeap = {.size = 0, .isMinHeap = false};

    int values[] = {10, 4, 15, 20, 0, 8};
    int n = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < n; i++)
    {
        insert(&minHeap, values[i]);
        insert(&maxHeap, values[i]);
    }

    printf("Min Heap: ");
    printHeap(&minHeap);
    printf("Max Heap: ");
    printHeap(&maxHeap);

    printf("\nMin Heap Root Cikarildi: %d\n", extractRoot(&minHeap));
    printf("Yeni Min Heap Durumu: ");
    printHeap(&minHeap);

    return 0;
}