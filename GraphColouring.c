//write a c program to graph colouring
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#define MAX 100
struct node
{
    int data;
    struct node *next;
};
struct node *start=NULL;
void insert(int);
void display();
void graphColouring();
void main()
{
    int ch,item;
    while(1)
    {
        printf("\n1.Insert\n2.Display\n3.Graph Colouring\n4.Exit\n");
        printf("Enter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the item to be inserted:");
                scanf("%d",&item);
                insert(item);
                break;
            case 2:
                display();
                break;
            case 3:
                graphColouring();
                break;
            case 4:
                exit(0);
                break;
            default:
                printf("Wrong choice");
        }
    }
}
void insert(int item)
{
    struct node *temp,*ptr;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data=item;
    temp->next=NULL;
    if(start==NULL)
    {
        start=temp;
    }
    else
    {
        ptr=start;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=temp;
    }
}
void display()
{
    struct node *ptr;
    ptr=start;
    if(start==NULL)
    {
        printf("\nList is empty");
    }
    else
    {
        printf("\nList is:");
        while(ptr!=NULL)
        {
            printf("%d ",ptr->data);
            ptr=ptr->next;
        }
    }
}
void graphColouring()
{
    int i,j,k,n,m,count=0,flag=0;
    struct node *ptr;
    printf("\nEnter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the number of edges:");
    scanf("%d",&m);
    for(i=0;i<n;i++)
    {
        printf("\nEnter the adjacency matrix for vertex %d:",i+1);
        for(j=0;j<n;j++)
        {
            scanf("%d",&k);
            if(k==1)
            {
                insert(j);
            }
        }
    }
    display();
    ptr=start;
    while(ptr!=NULL)
    {
        count++;
        ptr=ptr->next;
    }
    if(count==n)
    {
        printf("\nGraph is not bipartite");
    }
    else
    {
        printf("\nGraph is bipartite");
    }
}



