#include <stdlib.h>
#include <malloc.h>
#include <inttypes.h>
#include "../queue/queue_dynamic.h"
#include "../stack/stack_dynamic.h"
#include "../vector.h"

#define t_graph_elem char

/*  -> Observations:
    Using vector and matrix ADTs might be simpler and actually faster
    (could therefore be made dynamic)
*/
typedef struct _graph {
    t_graph_elem* values;
    int32_t** adj_matrix;
    uint32_t vertex_count;
    uint32_t _max_vertex_count;
} graph;

 // Create a new graph
graph* graph_new(uint32_t _max_vertex_count){
    graph* newGraph = (graph*)malloc(sizeof(graph));
    newGraph->values = (t_graph_elem*)calloc(_max_vertex_count, sizeof(t_graph_elem));
    newGraph->adj_matrix = (int**)malloc(sizeof(int*)*_max_vertex_count);
    for (uint32_t i=0;i<_max_vertex_count;i++){
        newGraph->adj_matrix[i] = (int*)calloc(_max_vertex_count, sizeof(int));
    }
    newGraph->vertex_count = 0;
    newGraph->_max_vertex_count = _max_vertex_count;
}

// Initializes a new full graph with start values
graph* graph_init(t_graph_elem* values, int32_t** adj_matrix, uint32_t vertex_count, uint32_t _max_vertex_count){
    graph* newGraph = (graph*)malloc(sizeof(graph));
    newGraph->values = values;
    newGraph->adj_matrix = adj_matrix;
    newGraph->vertex_count = vertex_count;
    newGraph->_max_vertex_count = vertex_count;
}

 // Destroy a graph
void graph_destroy(graph* g){
    free(g->values);
    for (int i=0;i<g->vertex_count;i++){
        free(g->adj_matrix[i]);
    }
    free(g->adj_matrix);
    free(g);
}

int graph_isFull(graph* g){
    return (g->vertex_count == g->_max_vertex_count);
}

// Add a vertex to the graph
int graph_add_vertex(graph* g, t_graph_elem vertex){
    int result = 0;
    if (!graph_isFull(g)){
        g->values[g->vertex_count] = vertex;
        g->vertex_count++;
        result = 1;
    }
    return result;
}

 // Get vertex by index
t_graph_elem graph_vertex_get(graph* g, int index){
    return g->values[index];
}

// Get the index of a vertex
int graph_vertex_index(graph* g, t_graph_elem vertex, int cmp (t_graph_elem, t_graph_elem)){
    uint32_t result = -1;
    int isFound = 0;
    uint32_t i = 0;
    while (!isFound && i<g->vertex_count){
        if (g->values[i] == vertex){
            result = i;
            isFound = 1;
        }
        else i++;
    }
    return result;
}

// Add an edge to the graph
void graph_add_edge(graph* g, int v1, int v2, int weight){
    g->adj_matrix[v1][v2] = weight;
}

// Add an edge to the graph by name
int graph_add_edge_byname(graph* g, t_graph_elem v1, t_graph_elem v2, int weight, int cmp (t_graph_elem, t_graph_elem)){
    
}

// Remove an edge from the graph
int graph_remove_edge(graph* g, int v1, int v2, int weight){
    int result = g->adj_matrix[v1][v2];
    g->adj_matrix[v1][v2] = 0;
    return result;
}

// Remove a vertex from the graph
int graph_remove_vertex(graph* g, int v){
    
}

// Get the weight of an edge
int graph_get_edge_weight(graph* g, int v1, int v2){
    return g->adj_matrix[v1][v2];
}

// Get the cost of an edge
int graph_get_edge_cost(graph* g, int v1, int v2){
    //???
}

// Return 1 if exists an edge between v1 and v2, 0 otherwise
int graph_is_edge (graph* g, int v1, int v2){
    return !!(g->adj_matrix[v1][v2]);
}

// Get the vertex count
uint32_t graph_vertex_count(graph* g){
    return g->vertex_count;
}

// Get the degree of a vertex (7.2.a)
uint32_t graph_vertex_degree(graph* g, int v){
    uint32_t grade = 0;
    for (uint32_t i=0;i<g->vertex_count;i++){
        grade += !!(g->adj_matrix[i][v]);
    }
    return grade;
}


int _cmp_int(void* a, void* b){
    int r1 = *((int*)a);
    int r2 = *((int*)b);
    return r1 - r2;
}

// Get ayencency list of a vertex (7.2.b) 
/*void graph_vertex_adjacent_list(graph* g, int v, list* L){}*/

// Search Breadth First Search
void graph_bfs(graph* g, int v, int (*visit)(t_graph_elem, int, void*), void* ctx){
    if (g && g->vertex_count > 0){
        queue* q = queue_new(g->vertex_count);
        vector* visited = vector_new();
        enqueue(q, v);                       //A hashtable would improve efficiency
        vector_push(visited, (void*)&(v));
        while (!queue_isempty(q)){
            uint32_t aux_id = dequeue(q);
            for (int i=0;i<g->vertex_count;i++){
                int found = vector_find(visited, (void*)&i, _cmp_int);
                if (g->adj_matrix[aux_id][i] && (found == -1)){
                    enqueue(q, i);
                    int* aux = (int*)malloc(sizeof(int));
                    *aux = i;
                    vector_push(visited, (void*)aux);
                }
            }
            visit(g->values[aux_id], aux_id, ctx);
        }
        vector_free(visited);
        queue_free(q);
    }
}

// Search Depth First Search 
void graph_dfs(graph* g, int v, int visit(t_graph_elem, int, void*), void* ctx){
        if (g && g->vertex_count > 0){
        stack* s = stack_new(g->vertex_count);
        vector* visited = vector_new();
        push(s, v);                       //A hashtable would improve efficiency
        vector_push(visited, (void*)&(v));
        while (!stack_isempty(s)){
            uint32_t aux_id = pop(s);
            for (int i=0;i<g->vertex_count;i++){
                int found = vector_find(visited, (void*)&i, _cmp_int);
                if (g->adj_matrix[aux_id][i] && (found == -1)){
                    push(s, i);
                    int* aux = (int*)malloc(sizeof(int));
                    *aux = i;
                    vector_push(visited, (void*)aux);
                }
            }
            visit(g->values[aux_id], aux_id, ctx);
        }
        vector_free(visited);
        stack_free(s);
    }
}
