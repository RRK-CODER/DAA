#include <stdio.h>
#include <stdlib.h>
void BinarySearch(int A[], int size, int key)
{
int low=0, high = size-1, mid=0;

while(low<=high)
{
    mid = low + (high - low )/2;
    if(A[mid]==key)
    return mid;
    else if(A[mid]< key)
    {
        low = mid+1 ;
            }
            else 
            {
                high = mid-1;
            }
}
return -1;
}

void main()
{
 int size,key,A[100],position,j;
 
 printf("Enter the size of the array :");
 scanf("%d",&size);
for(j=0;j<size;j++)
 {
  printf("A[%d] = ",j);
  scanf("%d",&A[j]);
 }
 printf("\nEntered values in array :\n");
 printf("\n");
 printf("{ ");
for(j=0;j<size;j++)
 {
 printf("%d ",A[j]);

 }
 printf("}");
 printf("\n\nEnter the key value :");
 scanf("%d",&key);
 position=BinarySearch(A,size,key);
 if(position==-1)
  {
   printf("\n%d is not found ",key);
  }
 else
  {
   printf("\n%d is found and the index value is A[%d]",key,position);
  }
 getch();
}