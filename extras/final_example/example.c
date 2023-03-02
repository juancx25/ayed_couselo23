#include "../../ADTs/graph/graph_m.h"
#include "../../ADTs/stack/stack_dynamic.h"
#include "../../utils/vector/vector_utils.h"

typedef struct _vertexAndDegree{
    int node_id;
    int node_degree;
} vertexAndDegree;

int cmp_vertexAndDegree(void* vad1, void* vad2){
    vertexAndDegree* a = (vertexAndDegree*)vad2;
    vertexAndDegree* b = (vertexAndDegree*)vad1;
    int result = a->node_degree - b->node_degree;
    if (result == 0){
        result = a->node_id - b->node_id;
    }
    return result;
}

stack* graph_get_stack_degree(graph* g){
    int graphSize = graph_vertex_count(g);
    stack* result = stack_new(graphSize);
    vector* degree_count = vector_new();
    for (int i=0;i<graphSize;i++){
        vertexAndDegree* aux = (vertexAndDegree*)malloc(sizeof(vertexAndDegree));
        aux->node_id = i;
        aux->node_degree = graph_vertex_degree(g, i);
        vector_push(degree_count, (void*)aux);
    }
    vu_shell_sort(degree_count, cmp_vertexAndDegree);
    for (int i=0;i<graphSize;i++){
        int node_id = ((vertexAndDegree*)vector_get(degree_count, i))->node_id;
        push(result, graph_vertex_get(g, node_id));
    }
    vector_free(degree_count);
    return result;
}

void printIntStack(stack* s){
    if (!stack_isempty(s)){
        printf("%c\n", pop(s));
        printIntStack(s);
    }
}

//t_elem_stack is int
int main(){
    graph* g = graph_new(5);
    graph_add_vertex(g, '1');
    graph_add_vertex(g, '2');
    graph_add_vertex(g, '3');
    graph_add_vertex(g, '4');
    graph_add_vertex(g, '5');

    graph_add_edge(g, 0, 1, 1);
    graph_add_edge(g, 1, 3, 1);
    graph_add_edge(g, 1, 2, 1);
    graph_add_edge(g, 1, 4, 1);
    graph_add_edge(g, 2, 4, 1);
    graph_add_edge(g, 3, 0, 1);
    graph_add_edge(g, 3, 4, 1);
    graph_add_edge(g, 4, 1, 1);
    graph_add_edge(g, 4, 2, 1);

    stack* result = graph_get_stack_degree(g);
    
    printIntStack(result);

    return 0;
}