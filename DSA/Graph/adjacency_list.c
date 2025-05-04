#include <stdio.h>
#include <stdlib.h>

/* Structure for node */
typedef struct node{
    int data;
    struct node *next;
}node_t;

/* The structure for adjacency list
 * which is an array of list of nodes and used to create the list to 
 * its adjacent nodes.
*/
typedef struct adjlist{
    node_t *head;
}adj_list_t;


/* overall graph struct which has 
 * nodes and 
 * array of adjacency nodes - with this the edges can be created between node and adjacency nodes
*/
typedef struct GRAPH{
    int nodes;
    //denotes array of nodes and each node have individual head
    adj_list_t *array;
}graph_t;

node_t* newnodecreate(unsigned int val){
    node_t *new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = val;
    new_node->next = NULL;
    return new_node;
}

/*
<-----------Create Graph----------->
 * | N1 |*| NULL | <-- Head pointer
 * | N2 |*| NULL | <-- Head pointer
 * | N3 |*| NULL | <-- Head pointer
 * | N4 |*| NULL | <-- Head pointer
 * | N5 |*| NULL | <-- Head pointer
*/
graph_t *createGraph(unsigned int nodes){
    graph_t *my_graph = malloc(sizeof(graph_t));
    my_graph->nodes = nodes;

    //array is a pointer so need to give it a memory
    my_graph->array = malloc(nodes*sizeof(adj_list_t));
    //Initialize all the node heads to NULL.
    for(int i = 0; i < nodes; i++){
        my_graph->array[i].head = NULL;
    }
    return my_graph;
}

/*
<--------------------after adding edge-------------------->
 * | N0 |*|  N1  |->|  N4  |->| NULL |
 * | N1 |*|  N0  |->|  N2  |->|  N3  |->|  N4  |->| NULL |
 * | N2 |*|  N1  |->|  N3  |->| NULL |
 * | N3 |*|  N1  |->|  N2  |->|  N4  |->| NULL |
 * | N4 |*|  N0  |->|  N1  |->|  N3  |->| NULL |
*/
void addEdge(graph_t *graph, int src, int dest){
    node_t *temp = newnodecreate(dest);
    temp->next = graph->array[src].head;
    graph->array[src].head = temp;

    temp = newnodecreate(src);
    temp->next = graph->array[dest].head;
    graph->array[dest].head = temp;
}

void printGraph(graph_t *graph){
    for(int i = 0; i < graph->nodes; i++){
        node_t *temp = graph->array[i].head;
        printf("Adjacency list of vertex %d\n head ", i);
        while (temp) {
            printf("-> %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int V = 5;
    graph_t* graph = createGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    printGraph(graph);
    return 0;
}
