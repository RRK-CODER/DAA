#include <stdio.h>
#include <stdbool.h>
int V;
bool G[20][20];

void printSolution(int path[]);
bool isSafe(int v, int path[], int pos)
{
	if (G[path[pos - 1]][v] == 0) {
		printf("\nCaught %d here no edge", v);
		return false;
	}
	for (int i = 0; i < pos; i++) 
		if (path[i] == v) {
			printf("\nCaught %d already included", v);
			return false;
	}
	return true;
}
bool hamCycleUtil(int path[], int pos)
{
	if (pos == V)
	{
		if (G[path[pos - 1]][path[0]] == 1)
			return true;
		else
			return false;
	}
	for (int v = 1; v < V; v++)
	{
		if (isSafe(v, path, pos))
		{
			printf("\nSafe path! via %d\n", v);
			for(int i=0; i<pos; i++) {
				printf("%d ", path[i]);
			}
			printf("\n");
			path[pos] = v;
			if (hamCycleUtil(path, pos + 1) == true)
				return true;
			path[pos] = -1;
		}
	}
	return false;
}

void hamCycle()
{
	int path[V];
	for (int i = 0; i < V; i++)
		path[i] = -1;
	path[0] = 0;
	if (hamCycleUtil(path, 1) == false)
	{
		printf("\nSolution does not exist");
		return;
	}
	printSolution(path);
}
void printSolution(int path[])
{
	printf("Solution Exists:\n");
	for (int i = 0; i < V; i++)
		printf("%d ", path[i]);
	printf("%d ", path[0]);
	printf("\n");
}
int main()
{
	printf("\nEnter the number of vertices: ");
	scanf("%d", &V);

	printf("\nEnter the graph data in matrix format: ");
	for (int i = 0; i < V; i++)
	{
		for (int j = 0; j < V; j++)
		{
			scanf("%d", &G[i][j]);
		}
	}
	hamCycle();
	return 0;
}