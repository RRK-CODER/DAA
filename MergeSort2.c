#include<stdio.h>
 
void mergesort(int a[],int low ,int high);
void merge(int a[],int i1,int j1,int i2,int j2);
 
int main()
{
int a[30],n,i;
printf("Enter no of elements:");
scanf("%d",&n);
printf("Enter array elements:");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
mergesort(a,0,n-1);
printf("\nSorted array is :");
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
 
void mergesort(int a[],int low,int high)
{
int mid;
if(low<high)
{
mid=(low+high)/2;
mergesort(a,low,mid); //left recursion
mergesort(a,mid+1,high); //right recursion
merge(a,low,mid,mid+1,high); //merging of two sorted sub-arrays
}
}
 
void merge(int a[],int i1,int j1,int i2,int j2)
{
int temp[50]; //array used for merging
int low,high,k;
low=i1; //beginning of the first list
high=i2; //beginning of the second list
k=0;
while(low<=j1 && high<=j2) //while elements in both lists
{
if(a[low]<a[high])
temp[k++]=a[low++];
else
temp[k++]=a[high++];
}
while(low<=j1) //copy remaining elements of the first list
temp[k++]=a[low++];
while(high<=j2) //copy remaining elements of the second list
temp[k++]=a[high++];
//Transfer elements from temp[] back to a[]
for(low=i1,high=0;low<=j2;low++,high++)
a[low]=temp[high];
}