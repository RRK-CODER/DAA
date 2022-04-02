#include <stdio.h>
//#include <conio.h>
int a[100];
int max;
int min;
  int mm(int i, int j)
        {
            int max1, min1, mid;
        if(i==j)
        {
            max=min=a[i];
        }
        else if(i==j-1)
        {
            if(a[i]< a[j])
            {
            max=a[j];
            min=a[i];
        }
        else
        {
            max=a[i];
            min=a[j];
        }
        }
        else
        {
            mid=(i+j)/2;
            mm(i, mid);
            max1=max;
            min1=min;
            mm(mid+1, j);
        
        if(max< max1)
        {
            max=max1;
        }
        if(min>min1)
        {
          min=min1;
        }
        }

}
void main()
{
    int i, n;
    printf("Enter the size of array");
    scanf("%d", &n);
    printf("Enter the elements:");
    for(i=0; i<n; i++)
    {
       scanf("%d", &a[i]);
    }
       mm(0,n-1);
        printf("Maximum element in the list %d\n",max );
        printf("Minimum element in the list %d\n",min );
}
       

