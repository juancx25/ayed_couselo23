typedef struct _graph {
    
} graph;

 // Create a new graph
graph* graph_new();

 // Destroy a graph
void graph_destroy(graph* g);

// Add a vertex to the graph
int graph_add_vertex(graph* g, t_graph_elem vertex)

 // Get vertex by index
t_graph_elem graph_vertex_get(graph* g, int index)

// Get the index of a vertex
int graph_vertex_index(graph* g, t_graph_elem vertex, int cmp (t_graph_elem, t_graph_elem))

// Add an edge to the graph
int graph_add_edge(graph* g, int v1, int v2, int weight) 

// Add an edge to the graph by name
int graph_add_edge_byname(graph* g, t_graph_elem v1, t_graph_elem v2, int weight, int cmp (t_graph_elem, t_graph_elem))

// Remove an edge from the graph
int graph_remove_edge(graph* g, int v1, int v2, int weight)

// Remove a vertex from the graph
int graph_remove_vertex(graph* g, int v)

// Get the weight of an edge
int graph_get_edge_weight(graph* g, int v1, int v2)

// Get the cost of an edge
int graph_get_edge_cost(graph* g, int v1, int v2)

// Return 1 if exists an edge between v1 and v2, 0 otherwise
int graph_is_edge (graph* g, int v1, int v2)

// Get the vertex count
int graph_vertex_count(graph* g)

// Get the degree of a vertex (7.2.a)
int graph_vertex_degree(graph* g, int v) 

// Get ayencency list of a vertex (7.2.b) 
void graph_vertex_adjacent_list(graph* g, int v, list* L)

// Search Breadth First Search
void graph_bfs(graph* g, int v, int visit(t_graph_elem, int, void*), void* ctx)

// Search Depth First Search 
void graph_dfs(graph* g, int v, int visit(t_graph_elem, int, void*), void* ctx)
