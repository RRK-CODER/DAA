#include <stdio.h>
int main()
{
int arr[100], swap, i, j , n;
printf("Enter the number of elements in the array\n");
scanf("%d", &n);
printf("Enter the elements of the array\n ");
for(i=0; i< n; i++)
{
    scanf("%d", &arr[i]);
}

for(i=0; i<n-1 ; i++)
{
    for(j=0; j<n-i-1; j++)
    {if(arr[j]>arr[j+1])
    {swap=arr[j];
    arr[j]=arr[j+1];
    arr[j+1]=swap;
    }
}
}
printf("Sorted list\n");
for(i=0; i<n ; i++)
{printf("%d ", arr[i]);
printf(" ");
}

return 0;

}