#include <stdio.h>
int main()
{
int arr[100], swap, i, j , n;
printf("Enter the number of elements in the array\n");
scanf("%d", &n);
printf("Enter the elements of the array \n");
for(i=0; i< n; i++)
{
    scanf("%d ", &arr[i]);
    
}

for(i=1; i<n ; i++)
{
    int key=arr[i];
    int j=i-1;
    while(j>=0 && arr[j]>key)
    {
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}

printf("Sorted list\n");
for(i=0; i<n ; i++)
printf("%d", arr[i]);

return 0;

}