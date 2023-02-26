#include "../../ADTs/graph/graph_m.h"
#include "../../utils/stack/stack_utils.h"
#include "../../ADTs/vector.h"

void vec_fillWithInt(vector* v, int value){
    for (int i=0;i<v->length;i++){
        int* aux = (int*)malloc(sizeof(int));
        *aux = value;
        vector_push(v, (void*)aux);
    }
}
int vec_removeMax(vector* v){
    int maxPos = 0;
    for (int i=1;i<v->length;i++){
        if (*((int*)vector_get(v, maxPos)) < *((int*)vector_get(v, i))){
            maxPos = i;
        }
    }
    vector_remove(v, maxPos);
    return maxPos;
}

int visit(char value, int v_id, void* v){
    vector* vec = (vector*)v;
    vector_set(vec, v_id, vector_get(vec, v_id)+1);
}

stack* graph_get_stack_degree(graph* g){
    stack* s = stack_new(g->vertex_count);
    vector* vec = vector_init(g->vertex_count);
    vec_fillWithInt(vec, 0);
    graph_bfs(g, 0, visit, (void*)vec);
    while(!vector_isempty(vec)){
        push(s, vec_removeMax(vec));
    }
}

void printChar(void* value){
    printf("%c ",*((char*)value));
}

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
    
    su_printStack_rec(result, printChar);

    return 0;
}