#include<stdio.h>

typedef struct _Heap
{
  int *array;
  unsigned int count;
  unsigned int  capacity;
  char heap_type;
}Heap;

int parrent(Heap* heap, int index)
{
    if(index<=0 || index >= heap->count)
        return -1;
    return (index-1)/2;
}

int leftChild(Heap* heap, int index)
{
    int left = 2*index +1;
    if(left >= heap->count)
        return -1;
    return left;
}

int rightChild(Heap* heap, int index)
{
    int right = 2*index +2;
    if(right >= heap->count)
        return -1;
    return right;
}

int getMin(Heap* heap)
{
    if(0 == heap->count)
        return -1;
    return heap->array[0];
}

int getMax(Heap* heap)
{
    if(0 == heap->count)
        return -1;
    return heap->array[0];
}

void MaxHeapify(Heap * heap, int index)
{
    int left, right , max , temp;
    left = leftChild(heap, index);
    right = rightChild(heap, index);
    max = index;
    if((left != -1) && (heap->array[left] > heap->array[max]))
        max = left;
    if(right != -1 && (heap->array[right] > heap->array[max]))
        max = right;
    if(max != index)
    {
        temp = heap->array[index];
        heap->array[index] = heap->array[max];
        heap->array[max] = temp;
        MaxHeapify(heap, max);
    }

}

void resizeHeap(Heap* heap)
{
    int *arr_old = heap->array;
    heap->array = (int*)malloc(sizeof(int)* heap->capacity*2);

    if(!heap->array)
        return;
    heap->capacity = heap->capacity*2;
    for(int i=0; i<heap->count; i++)
        heap->array[i] = arr_old[i];
    free(arr_old);
}

void insert(Heap* heap, int data)
{
    int i;
    if(heap->count == heap->capacity)
        resizeHeap(heap);
     i = heap->count;

    while(i>=0 && data > heap->array[parrent(heap, i)])
    {
      heap->array[i] =  heap->array[parrent(heap, i)];
      i =  parrent(heap, i);
    }
    heap->array[i] = data;

}

int  del(Heap* heap)
{
    int data;
    if(heap->count ==0)
        return -1;
    data = heap->array[0];
    heap->array[0] = heap->array[heap->count-1];
    heap->count--;
    MaxHeapify(heap, 0);
    return data;
}

Heap* createHeap(int capacity, char heap_type)
{
  Heap* heap = (Heap*)malloc(sizeof(Heap));
  if(!heap)
        return NULL;
  heap->heap_type = heap_type;
  heap->capacity  = capacity;
  heap->count = 0;
  heap->array = (int*)malloc(sizeof(int)* heap->capacity);

  if(NULL == heap->array)
  {
    free(heap);
    return NULL;
  }
  return heap;
}

void printHeap(int arr[], int n)
{
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
}

void BuildHeap(Heap *heap, int arr[], int n)
{
    while(n > heap->capacity)
        resizeHeap(heap);
    for(int i=0; i<n; i++)
        heap->array[i] = arr[i];
    heap->count = n;
    for(int i = (n-1)/2; i>=0; i--)
    {
        MaxHeapify(heap, i);
    }

}

void heapSort(Heap* heap, int arr[], int arr_size)
{
    while(heap->capacity < arr_size)
        resizeHeap(heap);

    BuildHeap(heap, arr, arr_size);
    printf("\n Original Max Heap\n");
    printHeap(heap->array, arr_size);
    int old_size = arr_size;

    for(int i =arr_size-1; i>=0; i--)
    {
        int tempData = heap->array[0];
        heap->array[0] = heap->array[heap->count-1];
        heap->array[heap->count-1] = tempData;
        heap->count--;
        MaxHeapify(heap, 0);
        printf("\n After Heapify\n");
         printHeap(heap->array, arr_size);
    }
    heap->count = old_size;

}
 main()
{
int arr[] = { 1, 3, 5, 4, 6, 13, 10, 9, 8, 15, 17 };

    int n = sizeof(arr) / sizeof(arr[0]);

  Heap* heap = createHeap(16,1);
    //buildHeap(arr, n);

    printHeap(heap->array, n);
    heapSort(heap, arr, n);
    printf("\n After Heap Sort\n");
    printHeap(heap->array, n);
   // BuildHeap(heap, arr, n);
    //printf("\n After Heapify\n");
    //printHeap(heap->array, n);
}
