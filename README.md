#Strong Components in Directed Graphs

Undirected graphs and DAG's are both simpler structures than general directed graphs because of the structural symmetry that characterizes the reachability relationships among the vertices: In an undirected graph, if there is a path from s to t, then we know that there is also a path from t to s; in a DAG, if there is a directed path from s to t, then we know that there is no directed path from t to s.

For general directed graphs, knowing that vertex t is reachable from vertex s gives no information about whether vertex s is reachable from vertex t.

In the mathematical theory of directed graphs, a graph is said to be strongly connected if every vertex is reachable from every other vertex.


# Tarjan's strongly connected components algorithm
Tarjan's algorithm is based on a recursive DFS. 

1. We reverse the graph, by changing direction of all edges.
2. We do a DFS on the reverse graph and number the vertices in postorder.
3. We do a DFS on the original graph. Starting each time with the vertex with highest postordernumber.

This results in a DFS forest, where each DFS tree is a strongly connected component.