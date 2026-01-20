#ifndef BFS_H_INCLUDED
#define BFS_H_INCLUDED


#define MAX 10   // maximum number of vertices

class Graph {
    int V;
    int adj[MAX][MAX];   // adjacency matrix

public:
    Graph(int vertices) {
        V = vertices;

        // initialize adjacency matrix with 0
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;
        adj[v][u] = 1;   // undirected graph
    }

    void bfs(int start) {
        int visited[MAX] = {0};
        int queue[MAX];
        int front = 0, rear = 0;

        visited[start] = 1;
        queue[rear++] = start;

        while (front < rear) {
            int current = queue[front++];
            cout << current << " ";

            for (int i = 0; i < V; i++) {
                if (adj[current][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    queue[rear++] = i;
                }
            }
        }
    }
};



#endif // BFS_H_INCLUDED
