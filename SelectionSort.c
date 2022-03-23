#include <stdio.h>
int main()
{
int arr[100], swap, i, j , n;
printf("Enter the number of elements in the array\n");
scanf("%d", &n);
printf("Enter the elements of the array \n");
for(i=0; i<n; i++)
{
    scanf("%d ", &arr[i]);
    
}

for(i=0; i<n-1 ; i++)
{
    int min_ind=i;
    for(j=i+1; j<n; j++)
    {if(arr[j]<arr[min_ind])
    min_ind=j;
    {swap=arr[min_ind];
    arr[min_ind]=arr[i];
    arr[i]=swap;
    }
}
}

printf("Sorted list\n");
for(i=0; i<n ; i++)
printf("%d ", arr[i]);

return 0;

}