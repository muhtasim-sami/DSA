
/*
 *
 * Pseudo Code :
 *
 * function Kruskal(Graph G):
    F := ∅  // Initialize the forest
    for each vertex v in G.Vertices do
        MAKE-SET(v)  // Create a set for each vertex

    // Sort edges by weight
    for each edge {u, v} in G.Edges ordered by increasing weight do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F := F ∪ { {u, v} }  // Add edge to the forest
            UNION(FIND-SET(u), FIND-SET(v))  // Combine sets

    return F  // Return the minimum spanning forest

 * 
 * */


struct Edge {
    int u, v, weight;
};

Edge edges[20]; // All edges
int parent[10]; // For Union-Find
int n, m;       // n = vertices (0 to n-1), m = number of edges

int find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = find(parent[x]); // Path compression
}

void unionSets(int x, int y) {
    parent[find(x)] = find(y);
}

bool cmp(Edge a, Edge b) {
    return a.weight < b.weight;
}

void kruskal() {
    // Sort edges by weight
    for (int i = 0; i < m-1; i++) {
        for (int j = i+1; j < m; j++) {
            if (edges[i].weight > edges[j].weight) {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    // Initialize parent
    for (int i = 0; i < n; i++) parent[i] = i;

    cout << "Kruskal's MST edges:\n";
    int totalWeight = 0;

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        if (find(u) != find(v)) {
            cout << u << " -- " << v << "  (weight: " << edges[i].weight << ")\n";
            totalWeight += edges[i].weight;
            unionSets(u, v);
        }
    }
    cout << "Total weight: " << totalWeight << endl;
}


