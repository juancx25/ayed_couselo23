#include "../../ADTs/graph/graph_m.h"

t_graph_elem* dijkstra(graph* g, int orig_id, int dest_id){
    int* weights = (int*)malloc(sizeof(int)*graph_vertex_count(g));
    int* prev = (int*)malloc(sizeof(int)*graph_vertex_count(g));
    int* visited = (int*)malloc(sizeof(int)*graph_vertex_count(g));
    for (int i=0;i<graph_vertex_count(g);i++){
        weights[i] = graph_get_edge_weight(g, orig_id, i);
        prev[i] = orig_id;
    }
    weights[orig_id] = 0;
    int currentNode = orig_id;
    visited[orig_id] = 1;

    
    
    //char* result = (char*)malloc(sizeof(char)*graph_vertex_count(g));
}

int main(){
    graph* g = graph_new(5);
    graph_add_vertex(g, 'M');
    graph_add_vertex(g, 'L');
    graph_add_vertex(g, 'P');
    graph_add_vertex(g, 'Z');
    graph_add_vertex(g, 'B');
    graph_add_vertex(g, 'R');

    graph_add_edge(g, 0, 1, 28);
    graph_add_edge(g, 0, 2, 14);
    graph_add_edge(g, 0, 5, 65);

    graph_add_edge(g, 1, 0, 28);
    graph_add_edge(g, 1, 2, 10);
    graph_add_edge(g, 1, 4, 14);

    graph_add_edge(g, 2, 0, 14);
    graph_add_edge(g, 2, 1, 10);
    graph_add_edge(g, 2, 3, 12);
    graph_add_edge(g, 2, 4, 36);

    graph_add_edge(g, 3, 2, 12);

    graph_add_edge(g, 4, 1, 14);
    graph_add_edge(g, 4, 2, 36);
    graph_add_edge(g, 4, 5, 24);

    graph_add_edge(g, 5, 0, 65);
    graph_add_edge(g, 5, 4, 24);

    char* result = dijkstra(g, 0, 5);;
    
    for (int i=0;i<graph_vertex_count(g);i++){
        printf("%c", result[i]);
        if (i == graph_vertex_count(g)-1) printf(" --> ");
    }

    free(result);
    return 0;
}