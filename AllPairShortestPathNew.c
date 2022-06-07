#include<stdlib.h>
#include<stdio.h>
#define NODE 5
#define INF 999

//Cost matrix of the graph
int costMat[NODE][NODE] = {
   {0,1,-3,2,-4},
   {3,0,-4,1,-1},
   {7,4,0,5,3},
   {2,-1,-5,0,-2},
   {8,5,1,6,0}
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