#include <stdio.h>
void heapify(int arr[], int n, int i)
{
    int largest = i; 
    int l = 2 * i + 1; 
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
 
    if (r < n && arr[r] > arr[largest])
        largest = r;
 
    if (largest != i) {
       int swap=arr[i];
       arr[i]=arr[largest];
       arr[largest]=swap;
       
 
      heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    for (int i = n - 1; i > 0; i--) {
       int swap=arr[0];
        arr[0]=arr[i];
        arr[i]=swap;
 
        heapify(arr, i, 0);
    }
}
 
int main()
{
    int arr[100], swap, i, j , n;
printf("Enter the number of elements in the array\n");
scanf("%d", &n);
printf("Enter the elements of the array \n");
for(i=0; i< n; i++)
{
    scanf("%d", &arr[i]);
}
heapSort(arr,n);

printf("Sorted list\n");
for(i=0; i<n ; i++)
{printf("%d", arr[i]);
printf(" ");
}
return 0;
}