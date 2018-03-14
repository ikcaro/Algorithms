#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <limits.h>

typedef struct heap_ {
    int *arr;
    int size;
    int max;
} HEAP;


void swap(int *a, int *b)
{
    static int tmp;

    tmp = *a;
    *a  = *b;
    *b  = tmp;
}

void heap(HEAP *h, int max)
{
    h->arr = malloc(max * sizeof(int));
    h->max = max;
    h->size = 0;
}

int _parent(int i)
{
    return (i - 1) / 2;
}

void _heapify(HEAP *h, int i)
{
    int left  = (2 * i) + 1;
    int right = (2 * i) + 2;
    int smallest;

    if (left < h->size && h->arr[left] < h->arr[i])
        smallest = left;
    else
        smallest = i;

    if (right < h->size && h->arr[right] < h->arr[smallest])
        smallest = right;

    if (smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        _heapify(h, smallest);
    }
}

void build_heap(HEAP *h)
{
    int i;

    for (i = (h->size / 2) - 1; i >= 0; --i)
        _heapify(h, i);
}

void insert_k(HEAP *h, int val)
{
    int i = 0;

    if (h->size == h->max)
        return;

    i = h->size;
    h->size++;
    h->arr[i] = val;

    while (i > 0 && h->arr[_parent(i)] > h->arr[i]) {
        swap(&h->arr[i], &h->arr[_parent(i)]);
        i = _parent(i);
    }
}

int extract_min(HEAP *h)
{
    int root = INT_MAX;

    if (h->size <= 0)
        return root;

    root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    _heapify(h, 0);

    return root;
}

int main()
{
    HEAP h = {NULL, 0, 0};
    int n = 0;
    int i = 0;
    int val = 0;
    int cost = 0;

    heap(&h, 5001);

    while (1) {
        scanf("%d", &n);
        if (n == 0)
            break;

        cost = 0;
        h.size = n;
        for (i = 0; i < n; ++i)
            scanf("%d", &h.arr[i]);
        build_heap(&h);

        while (h.size > 1) {
            val  = extract_min(&h);
            val  += extract_min(&h);
            cost += val;
            insert_k(&h, val);
        }

        printf("%d\n", cost);
    }

    return 0;
}
