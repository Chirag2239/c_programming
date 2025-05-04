#include <stdio.h>

int main()
{
    int i, j, u, v, nodes, edges;
    printf("Total nodes: ");
    scanf("%d", &nodes);
    printf("Total edges: ");
    scanf("%d", &edges);

    int adj[nodes + 1][nodes + 1];
    //Create and init the adjacency matrix
    for(i = 0; i < nodes; i++){
        for(j = 1; j < nodes; j++){
            adj[i][j] = 0;
        }
    }

    //create edges between nodes7
    for(i = 0; i < edges; i++){
        printf("edge between nodes:\n");
        scanf("%d", &u);
        scanf("%d", &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(i = 1; i < nodes; i++){
        printf("nodes adjacent to %d are: ", i);
        for(j = 1; j < nodes; j++){
            if(adj[i][j] == 1){
                printf("%d ", j);
            }
        }
        printf("\n");
    }
}