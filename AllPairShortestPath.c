#include<stdio.h>
int i,j,k,n,temp,cost[6][6],a[6][6],tcost[6];
int mincost=999;
int min(int a,int b)
{
    if(a<b)
        return a;
    else return b;
}
void allpath()
{
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=cost[i][j];
        }
    }
    for(k=0;k<n;k++)
    {
        printf("\nValue of matrix %d:\n",k+1);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                temp=a[i][k]+a[k][j];
                a[i][j]=min(a[i][j],temp);
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
}

int main()
{
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j)
                continue;
            printf("\nEnter value of %d %d: ",i+1,j+1);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }
    allpath();
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            tcost[i]+=a[i][j];
        }
    }
    for(i=0;i<n;i++)
        printf("\nmin cost from %d: %d",i+1,tcost[i]);
    for(i=0;i<n;i++)
    {
        if(tcost[i]<mincost)
            mincost=tcost[i];
    }
    return 0;
}