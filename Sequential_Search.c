#include <stdio.h>
#include <conio.h>
void main()
{
 int A[100],i,n,found,T;
 //clrscr();
 printf("Enter the size of array :");
 scanf("%d",&n);
 printf("\nEnter the values :\n");
 for(i=0;i<n;i++)
 {
  printf("A[%d] = ",i);
  scanf("%d",&A[i]);
 }
 printf("\nEntered values in array :\n");
 printf("\nA[%d] = { ",n);
 for(i=0;i<n;i++)
 {
  printf("%d ",A[i]);
 }
  printf("}");
 printf("\n\nEnter the target value :");
 scanf("%d",&T);
 for(i=0;i<n;i++)
 {
  if(A[i]==T)
   {
     found=1;
     break;
   }

 }
 if(found==1)
 {
  printf("\n%d is found and the index value is A[%d]",A[i],i);
 }
 else
 {
  printf("\n%d is not found ",T);
 }
 getch();
}