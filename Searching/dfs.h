#ifndef DFS_H_INCLUDED
#define DFS_H_INCLUDED


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

    void dfs(int start) {
        int visited[MAX] = {0};
        dfsUtil(start, visited);
    }

private:
    void dfsUtil(int v, int visited[]) {
        visited[v] = 1;
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                dfsUtil(i, visited);
            }
        }
    }
};


#endif // DFS_H_INCLUDED
