#include<stdio.h>
#include<conio.h>
int min(int a,int b)
{
 if(a<b)
   return a;
 else
   return b;
}
int fibosearch(int a[],int n,int key)
{
 int i,fib,fib1,fib2,offset;
 fib2=0;
 fib1=1;
 fib= fib1+fib2;

 while(fib<=n)
  {
   fib2=fib1;
   fib1=fib;
   fib=fib1+fib2;
  }
  offset=-1;
 while(fib>1)
  {
   i=min(offset+fib2,n-1);
  if (a[i]<key)
   {
    fib=fib1;
    fib1=fib2;
    fib2=fib-fib1;
  //  n=n-1;
    offset=i;
   }
 else if(a[i]>key)
  {
   fib=fib2;
   fib1=fib1-fib2;
   fib2=fib-fib1;
  // n=n-2;
  }
 else
  {
   return i;
  }
}
 if(a[offset]==key)
  {
   return offset+1;
  }
 else
 {
  return -1;
 }
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
 position=fibosearch(A,size,key);
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