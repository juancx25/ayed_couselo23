#include "graph_m.h"

int graph_print(t_graph_elem value, int v_id, void* dummy){
    printf("%c, ", value);
    return 1;
}

int main(){
    graph* g = graph_new(5);
    graph_add_vertex(g, 'A');
    graph_add_vertex(g, 'B');
    graph_add_vertex(g, 'C');
    graph_add_vertex(g, 'D');
    graph_add_vertex(g, 'E');
    graph_add_edge(g, 0, 1, 1);
    graph_add_edge(g, 1, 3, 1);
    graph_add_edge(g, 3, 2, 1);
    graph_add_edge(g, 3, 4, 1);
    graph_add_edge(g, 4, 0, 1);

    graph_bfs(g, 0, graph_print, NULL);
    printf("\n");

    graph_dfs(g, 0, graph_print, NULL);
    printf("\n");

    free(g);
    return 0;
}