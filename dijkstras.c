#include<stdio.h>
void dijkstra(int, int [20][20], int [20], int [20], int);
void main(){
	int i, j, n, visited[20], source, A[20][20], d[20];
	printf("Enter no of vertices.\n");
	scanf("%d", &n);
	printf("Enter the adjacency matrix.\n");
	for(i=1; i<=n; i++){
		for(j=1; j<=n; j++){
			scanf("%d", &A[i][j]);
		}
	}
	printf("Enter the source node.\n");
	scanf("%d", &source);
	dijkstra(source, A, visited, d, n);
	for(i=1; i<=n; i++)
		if(i!=source)
			printf("Shortest path from %d to %d is %d.\n", source, i, d[i]);
}
void dijkstra(int source, int A[20][20], int visited[20], int d[20], int n){
	int i, j, min, u, w;
	for(i=1; i<=n; i++){
		visited[i]=0;
		d[i]=A[source][i];
	}
	visited[source]=1;
	d[source]=0;
	for(j=2; j<=n; j++){
		min=999;
		for(i=1; i<=n; i++){
			if(!visited[i]){
				if(d[i]<min){
					min=d[i];
					u=i;
				}
			}
		}
		visited[u]=1;
		for(w=1; w<=n; w++){
			if(A[u][w]!=999 && visited[w]==0){
				if(d[w]>A[u][w]+d[u])
					d[w]=A[u][w]+d[u];
			}
		}	
	}	
}
