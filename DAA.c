//Graph Colouring

#include<stdio.h>
int G[50][50],x[50];  
void next_color(int k){
   int i,j;
   x[k]=1;  
   for(i=0;i<k;i++){ 
     if(G[i][k]!=0 && x[k]==x[i])  
       x[k]=x[i]+1;  
   }
}
int main(){
  int n,e,i,j,k,l;
  printf("Enter no. of vertices : ");
  scanf("%d",&n);  
  printf("Enter no. of edges : ");
  scanf("%d",&e);  
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      G[i][j]=0;     
  printf("Enter indexes where value is 1-->\n");
  for(i=0;i<e;i++){
    scanf("%d %d",&k,&l);
    G[k][l]=1;
    G[l][k]=1;
  }
  for(i=0;i<n;i++)
    next_color(i);  
  printf("Colors of vertices -->\n");
  for(i=0;i<n;i++)  
    printf("Vertex[%d] : %d\n",i+1,x[i]);
  return 0;
}

SAMPLE INPUT AND OUTPUT

Enter no. of vertices : 4
Enter no. of edges : 5
Enter indexes where value is 1-->
0 1
1 2
1 3
2 3
3 0
Colors of vertices -->
Vertex[1] : 1
Vertex[2] : 2
Vertex[3] : 1
Vertex[4] : 3

//Sum of Subset 
#include <stdio.h>
#include <stdlib.h>
static int total_nodes;
void printValues(int A[], int size){
   for (int i = 0; i < size; i++) {
      printf("%*d", 5, A[i]);
   }
   printf("\n");
}
void subset_sum(int s[], int t[], int s_size, int t_size, int sum, int ite, int const target_sum){
   total_nodes++;
   if (target_sum == sum) {
      printValues(t, t_size);
      subset_sum(s, t, s_size, t_size - 1, sum - s[ite], ite + 1, target_sum);
      return;
   }
   else {
      for (int i = ite; i < s_size; i++) {
         t[t_size] = s[i];
         subset_sum(s, t, s_size, t_size + 1, sum + s[i], i + 1, target_sum);
      }
   }
}
void generateSubsets(int s[], int size, int target_sum){
   int* tuplet_vector = (int*)malloc(size * sizeof(int));
   subset_sum(s, tuplet_vector, size, 0, 0, 0, target_sum);
   free(tuplet_vector);
}
int main(){
   int set[] = { 5, 6, 12 , 54, 2 , 20 , 15 };
   int size = sizeof(set) / sizeof(set[0]);
   printf("The set is ");
   printValues(set , size);
   generateSubsets(set, size, 25);
   printf("Total Nodes generated %d\n", total_nodes);
   return 0;
}

SAMPLE INPUT AND OUTPUT
The set is     5    6   12   54    2   20   15
    5    6   12    2
    5   20
Total Nodes generated 127

//N-Queen Problem 
#include<stdio.h>
#include<math.h>
 
int board[20],count;
 
int main()
{
int n,i,j;
void queen(int row,int n);
 
printf(" - N Queens Problem Using Backtracking -");
printf("\n\nEnter number of Queens:");
scanf("%d",&n);
queen(1,n);
return 0;
}
void print(int n)
{
int i,j;
printf("\n\nSolution %d:\n\n",++count);
 
for(i=1;i<=n;++i)
  printf("\t%d",i);
 
for(i=1;i<=n;++i)
{
  printf("\n\n%d",i);
  for(j=1;j<=n;++j)
  {
   if(board[i]==j)
    printf("\tQ"); 
   else
    printf("\t-"); 
  }
}
}
 int place(int row,int column)
{
int i;
for(i=1;i<=row-1;++i)
{
  if(board[i]==column)
   return 0;
  else
   if(abs(board[i]-column)==abs(i-row))
    return 0;
}
 
return 1; 
}

void queen(int row,int n)
{
int column;
for(column=1;column<=n;++column)
{
  if(place(row,column))
  {
   board[row]=column; 
   if(row==n) 
    print(n); 
   else 
    queen(row+1,n);
  }
}
}

SAMPLE INPUT AND OUTPUT

Enter number of Queens:4

Solution 1:

        1       2       3       4

1       -       Q       -       -

2       -       -       -       Q

3       Q       -       -       -

4       -       -       Q       -

Solution 2:

        1       2       3       4

1       -       -       Q       -

2       Q       -       -       -

3       -       -       -       Q

4       -       Q       -       -

TREE TRAVERSAL
#include <stdio.h>
#include <stdlib.h>

struct node {
   int data; 
	
   struct node *leftChild;
   struct node *rightChild;
};

struct node *root = NULL;

void insert(int data) {
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;

   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;

      while(1) { 
         parent = current;
         
         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;                
            
            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }  //go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }            
   }
}

struct node* search(int data) {
   struct node *current = root;
   printf("Visiting elements: ");

   while(current->data != data) {
      if(current != NULL)
         printf("%d ",current->data); 

      //go to left tree
      if(current->data > data) {
         current = current->leftChild;
      }
      //else go to right tree
      else {                
         current = current->rightChild;
      }

      //not found
      if(current == NULL) {
         return NULL;
      }
   }
   
   return current;
}

void pre_order_traversal(struct node* root) {
   if(root != NULL) {
      printf("%d ",root->data);
      pre_order_traversal(root->leftChild);
      pre_order_traversal(root->rightChild);
   }
}

void inorder_traversal(struct node* root) {
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);          
      inorder_traversal(root->rightChild);
   }
}

void post_order_traversal(struct node* root) {
   if(root != NULL) {
      post_order_traversal(root->leftChild);
      post_order_traversal(root->rightChild);
      printf("%d ", root->data);
   }
}

int main() {
   int i;
   int array[7] = { 27, 14, 35, 10, 19, 31, 42 };

   for(i = 0; i < 7; i++)
      insert(array[i]);

   i = 31;
   struct node * temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }

   i = 15;
   temp = search(i);

   if(temp != NULL) {
      printf("[%d] Element found.", temp->data);
      printf("\n");
   }else {
      printf("[ x ] Element not found (%d).\n", i);
   }            

   printf("\nPreorder traversal: ");
   pre_order_traversal(root);

   printf("\nInorder traversal: ");
   inorder_traversal(root);

   printf("\nPost order traversal: ");
   post_order_traversal(root);       

   return 0;
}

SAMPLE INPUT AND OUTPUT

Visiting elements: 27 35 [31] Element found.
Visiting elements: 27 14 19 [ x ] Element not found (15).

Preorder traversal: 27 14 10 19 35 31 42
Inorder traversal: 10 14 19 27 31 35 42
Post order traversal: 10 19 14 31 42 35 27

//BFS
#include<stdio.h>
#include<conio.h>
int a[20][20],q[20],visited[20],n,i,j,f=0,r=-1;
void bfs(int v) {
	for (i=1;i<=n;i++)
	  if(a[v][i] && !visited[i])
	   q[++r]=i;
	if(f<=r) {
		visited[q[f]]=1;
		bfs(q[f++]);
	}
}
void main() {
	int v;
	printf("\n Enter the number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		q[i]=0;
		visited[i]=0;
	}
	printf("\n Enter graph data in matrix form:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	printf("\n Enter the starting vertex:");
	scanf("%d",&v);
	bfs(v);
	printf("\n The node which are reachable are:\n");
	for (i=1;i<=n;i++)
	  if(visited[i])
	   printf("%d\t",i); else
	   printf("\n Bfs is not possible");
}

SAMPLE INPUT AND OUTPUT


 Enter the number of vertices:3

 Enter graph data in matrix form:
2
4
5
2
3
4
1
7
8

 Enter the starting vertex:2

 The node which are reachable are:
1       2       3

//DFS

#include<stdio.h>
#include<conio.h>
int a[20][20],reach[20],n;
void dfs(int v) {
	int i;
	reach[v]=1;
	for (i=1;i<=n;i++)
	  if(a[v][i] && !reach[i]) {
		printf("\n %d->%d",v,i);
		dfs(i);
	}
}
void main() {
	int i,j,count=0;
	printf("\n Enter number of vertices:");
	scanf("%d",&n);
	for (i=1;i<=n;i++) {
		reach[i]=0;
		for (j=1;j<=n;j++)
		   a[i][j]=0;
	}
	printf("\n Enter the adjacency matrix:\n");
	for (i=1;i<=n;i++)
	  for (j=1;j<=n;j++)
	   scanf("%d",&a[i][j]);
	dfs(1);
	printf("\n");
	for (i=1;i<=n;i++) {
		if(reach[i])
		   count++;
	}
	if(count==n)
	  printf("\n Graph is connected"); else
	  printf("\n Graph is not connected");
}

SAMPLE INPUT AND OUTPUT


 Enter number of vertices:3

 Enter the adjacency matrix:
2
4
5
2
3
4
1
7
8

 1->2
 2->3

 Graph is connected

//ALL PAIR SHORTEST PATH

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

SAMPLE INPUT AND OUTPUT

Enter the value of n: 4

Enter value of 1 2: 1

Enter value of 1 3: 1

Enter value of 1 4: 4

Enter value of 2 1: 5

Enter value of 2 3: 7

Enter value of 2 4: 8

Enter value of 3 1: 2

Enter value of 3 2: 3

Enter value of 3 4: 5

Enter value of 4 1: 6

Enter value of 4 2: 8

Enter value of 4 3: 9

Value of matrix 1:
0 1 1 4
5 0 6 8
2 3 0 5
6 7 7 0

Value of matrix 2:
0 1 1 4
5 0 6 8
2 3 0 5
6 7 7 0

Value of matrix 3:
0 1 1 4
5 0 6 8
2 3 0 5
6 7 7 0

Value of matrix 4:
0 1 1 4
5 0 6 8
2 3 0 5
6 7 7 0

min cost from 1: 6
min cost from 2: 19
min cost from 3: 10
min cost from 4: 20

//Multistage Graph

#include<stdio.h>
#include<conio.h>
int a,b,u,v,n,i,j,ne=1;
int visited[10]={0},min,mincost=0,cost[10][10];

void main()
{
printf("\n Enter the number of nodes:");
scanf("%d",&n);
printf("\n Enter the adjacency matrix:\n");
for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
{
scanf("%d",&cost[i][j]);
if(cost[i][j]==0)
cost[i][j]=999;
}
visited[1]=1;
printf("\n");
while(ne<n)
{
for(i=1,min=999;i<=n;i++)
for(j=1;j<=n;j++)
if(cost[i][j]<min)
if(visited[i]!=0)
{
min=cost[i][j];
a=u=i;
b=v=j;
}
if(visited[u]==0 || visited[v]==0)
{
printf("\n Edge %d:(%d %d) cost:%d",ne++,a,b,min);
mincost+=min;
visited[b]=1;
}
cost[a][b]=cost[b][a]=999;
}
printf("\n Minimun cost=%d",mincost);
getch();
}

SAMPLE INPUT AND OUTPUT


 Enter the number of nodes:3

 Enter the adjacency matrix:
1
4
7
2
5
8
3 
6
9


 Edge 1:(1 2) cost:4
 Edge 2:(1 3) cost:7
 Minimun cost=11

