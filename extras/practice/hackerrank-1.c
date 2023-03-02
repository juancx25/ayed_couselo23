/* 
    Given an undirected graph, The task is to check if there is a cycle in the given graph.
 */

#include "../../ADTs/graph/graph_m.h"
#include "../../ADTs/stack/stack_dynamic.h"

int has_cycle(graph* g, int origin_id){
    int graphSize = graph_vertex_count(g);
    int* visited = (int*)malloc(graphSize);
    stack* s = stack_new(graphSize);
    push(s, origin_id);
    while(!stack_isempty(s)){
        int current_id = pop(s);
        for (int i=0;i<graphSize;i++){
            
        }
    }
    free(visited);
}

int main(){
    graph* g = graph_new(5);
    graph_add_vertex(g, '0');
    graph_add_vertex(g, '1');
    graph_add_vertex(g, '2');
    graph_add_vertex(g, '3');
    graph_add_vertex(g, '4');

    graph_add_edge(g, 0, 1, 1);
    graph_add_edge(g, 0, 3, 1);
    graph_add_edge(g, 1, 2, 1);
    graph_add_edge(g, 2, 0, 1);
    graph_add_edge(g, 3, 4, 1);

    has_cycle(g, 0);

    return 0;
}