#ifndef PRIMS_H_INCLUDED
#define PRIMS_H_INCLUDED


int n = 6; // Number of vertices
int graph[10][10]; // Adjacency matrix (hardcoded)
bool visited[10];
int parent[10];
int key[10];

void prim() {
    // Initialize
    for (int i = 0; i < n; i++) {
        key[i] = 999999;
        visited[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < n; count++) {
        // Find vertex with minimum key not yet visited
        int min = 999999, u = -1;
        for (int i = 0; i < n; i++) {
            if (!visited[i] && key[i] < min) {
                min = key[i];
                u = i;
            }
        }

        visited[u] = true;

        // Update neighbors
        for (int v = 0; v < n; v++) {
            if (graph[u][v] && !visited[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];.
				
            }
        }
    }

    cout << "Prim's MST edges:\n";
    int totalWeight = 0;
    for (int i = 1; i < n; i++) {
        cout << parent[i] << " -- " << i << "  (weight: " << graph[i][parent[i]] << ")\n";
        totalWeight += graph[i][parent[i]];
    }
    cout << "Total weight: " << totalWeight << endl;
}


#endif // PRIMS_H_INCLUDED
