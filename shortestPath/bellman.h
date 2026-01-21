
/*
 *
 * Pseudo Code :
 * =============
 *
 * function BellmanFord(vertices, edges, source):
    // Step 1: Initialize distances from source to all vertices as infinite
    for each vertex in vertices:
        distance[vertex] := infinity
    distance[source] := 0

    // Step 2: Relax all edges |V| - 1 times
    for i from 1 to |V| - 1:
        for each edge (u, v) with weight w in edges:
            if distance[u] + w < distance[v]:
                distance[v] := distance[u] + w

    // Step 3: Check for negative-weight cycles
    for each edge (u, v) with weight w in edges:
        if distance[u] + w < distance[v]:
            print("Graph contains a negative-weight cycle")
            return

    return distance

 *
 * */


#define INF 999999
#define V 5 // Number of vertices

void bellmanFord(int graph[][3], int E, int src) {
    int dist[V];

    // Step 1: Initialize distances from src to all other vertices as INFINITE
    for (int i = 0; i < V; i++)
        dist[i] = INF;
    dist[src] = 0;

    // Step 2: Relax all edges |V| - 1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph[j][0];
            int v = graph[j][1];
            int weight = graph[j][2];
            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    // Step 3: Check for negative-weight cycles
    for (int j = 0; j < E; j++) {
        int u = graph[j][0];
        int v = graph[j][1];
        int weight = graph[j][2];
        if (dist[u] != INF && dist[u] + weight < dist[v]) {
            cout << "Graph contains negative weight cycle" << endl;
            return;
        }
    }

    // Print all distances
    cout << "Vertex Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << "\t\t" << dist[i] << endl;
}

