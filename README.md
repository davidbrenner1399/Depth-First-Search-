# Depth-First-Search-

Depth First Search Graph

Functions:

    Graph::Graph(const char* filename) This is the constructor. It reads data in from the input file of the graph given in adjacency matrix representation and builds the graph with a adjacency list representation. This method sets the value of size, builds the vectors labels and adj_list. For example, for the following line of input: D 0 1 0 0 1 0 0 Add edges to adj_list[3], which records edges starting from vertex D, by adding values 1 and 4, which are indexes for vertices B and E.

    void Graph::Depthfirst(int v) This private function is used to traverse a graph in the depth-first traversal/search algorithm starting at the vertex with the index value of v. To implement this method (and together with the Traverse method below), you may need several global variable and objects. For example, container objects to record the visiting order of all vertices, the container object to record the paths of traversing edges, and an integer indicating the current order in traversing.

    void Graph::Traverse() This public function is used to traverse a graph and invokes the above Depthfirst method. You will also need to display traverse result: the list of vertices in the order of their visit and the list of edges showing the path(s) of the traversal. At beginning of this method, you need to initialize the global variable(s) and object(s) used in Depthfirst.

    void Graph::Print() const This function prints the adjacency list for the graph. The following line is an example from an output: D: B, E, It indicates there are edges from vertex D to vertices B and E.
