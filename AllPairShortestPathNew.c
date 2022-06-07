#include<stdlib.h>
#include<stdio.h>
#define NODE 7
#define INF 999

//Cost matrix of the graph
int costMat[NODE][NODE] = {
   {0, 3, 6, INF, INF, INF, INF},
   {3, 0, 2, 1, INF, INF, INF},
   {6, 2, 0, 1, 4, 2, INF},
   {INF, 1, 1, 0, 2, INF, 4},
   {INF, INF, 4, 2, 0, 2, 1},
   {INF, INF, 2, INF, 2, 0, 1},
   {INF, INF, INF, 4, 1, 1, 0}
};
void floydWarshal(){
   int cost[NODE][NODE]; 
   for(int i = 0; i<NODE; i++)
      for(int j = 0; j<NODE; j++)
         cost[i][j] = costMat[i][j];
         for(int k = 0; k<NODE; k++){
            for(int i = 0; i<NODE; i++)
               for(int j = 0; j<NODE; j++)
                  if(cost[i][k]+cost[k][j] < cost[i][j])
                     cost[i][j] = cost[i][k]+cost[k][j];
   }
printf("The matrix:\n");
   for(int i = 0; i<NODE; i++){
      for(int j = 0; j<NODE; j++)
         printf("%d ",cost[i][j]);
      printf("\n");
   }
}
int main(){
   floydWarshal();
}