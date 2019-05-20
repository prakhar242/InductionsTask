#include <stdio.h>  
  
void create_max_heap(int arr[], int size, int i)  //Build heap ie. a tree where the value of child nodes of a node are lesser than that of the node
{  

int largest = i;    
int left = 2*i + 1;    
int right = 2*i + 2;    
int temp;  
if (left < size && arr[left] >arr[largest])  
largest = left;  
  
if (right < size && arr[right] > arr[largest])  
largest = right;  
  
if (largest != i)  
{  
    temp = arr[i];  
    arr[i]= arr[largest];   
    arr[largest] = temp;  
    create_max_heap(arr, size, largest);  
}  
}  
  
void heapSort(int arr[], int size)  
{  
int i, temp;  
for (i = size/2 - 1; i >= 0; i--)  
create_max_heap(arr, size, i);  
for (i=size-1; i>=0; i--)  
{  
    temp = arr[0];  
    arr[0]= arr[i];   
    arr[i] = temp;  
    create_max_heap(arr, i, 0);  
}  
}  
  
void main()  
{  
int i, size,arr[size];  
printf("Enter size of array: ");
scanf("%d", &size);
printf("Enter array elements: ");
for(i=0; i<size; ++i)
{
   scanf("%d", &arr[i]);
}  
heapSort(arr, size);  
  
printf("Sorted elements\n");  
for (i=0; i<size; ++i)  
printf("%d ",arr[i]);  
}  
