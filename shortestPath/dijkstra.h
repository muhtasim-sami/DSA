
/* Pseudo Code :
 * =============
 *
 * function Dijkstra(Graph, source):
    for each vertex v in Graph:
        dist[v] ← INFINITY
        prev[v] ← UNDEFINED
        add v to Q
    dist[source] ← 0

    while Q is not empty:
        u ← vertex in Q with min dist[u]
        remove u from Q

        for each neighbor v of u still in Q:
            alt ← dist[u] + Graph.Edges(u, v)
            if alt < dist[v]:
                dist[v] ← alt
                prev[v] ← u

    return dist[], prev[]

 *
 * */

#ifndef DIJKSTRA_H_INCLUDED
#define DIJKSTRA_H_INCLUDED

#define V 9
#define INF 999999   // infinite value, like INT_MAX

// Find vertex with minimum distance not yet processed
int minDistance(int dist[], int visited[]) {
    int min = INF;
    int minIndex = -1;

    for (int i = 0; i < V; i++) {
        if (visited[i] == 0 && dist[i] < min) {
            min = dist[i];
            minIndex = i;
        }
    }
    return minIndex;
}

// Print shortest distances
void printSolution(int dist[]) {
    cout << "Vertex   Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

// Dijkstra algorithm
void dijkstra(int graph[V][V], int src) {
    int dist[V];
    int visited[V];

    // Initialize distances and visited array
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Main loop
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, visited);

        if (u == -1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++) {
            if (visited[v] == 0 &&
                graph[u][v] != 0 &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

#endif // DIJKSTRA_H_INCLUDED
