#include <stdio.h>

void printarr(char c, int *arr, int s)
{
    int i = 0;

    printf("%c [", c);
    for (i = 0; i < s; ++i)
        printf("%d ", arr[i]);
    printf("]\n");
}

int swap(int *a, int *b)
{
    static int tmp;
    
    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void heapify(int *h, int max, int i)
{
    int left  = (2 * i) + 1;
    int right = (2 * i) + 2;
    int largest;
    
    largest = (left < max && h[left] > h[i])? left: i;
    
    if (right < max && h[right] > h[largest])
        largest = right;
    
    if (largest != i) {
        swap(&h[i], &h[largest]);
        heapify(h, max, largest);
    }
}

void build_heap(int *h, int size)
{
    int i = 0;
    
    for (i = ((size / 2) - 1); i >= 0; --i)
        heapify(h, size, i);
}

void heap_sort(int *h, int size)
{
    int i = 0;
    
    build_heap(h, size);
    for (i = (size - 1); i > 0; --i) {
        swap(&h[0], &h[i]);
        heapify(h, i, 0);
    }
}

int main()
{
    int i = 0;
    int arr[] = {123, 12, 4, 234, 1, 44, 80, 200, 0, 1, -10, 400, 2};
    
    printarr('B', arr, 13);
    heap_sort(arr, 13);
    printarr('A', arr, 13);
    
    return 0;
}
