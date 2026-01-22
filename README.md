# Data Structures and Algorithms
## Data Structures

## Algorithms
### Shostest Path 
- Dijkstra
- Floyd Warshall
- Bellman Ford
   Quick Comparison Table

| Feature |	Dijkstra |	Bellman-Ford |	Floyd-Warshall |
|---|---|---|---|
| Type |	Single-Source Shortest Path (SSSP) | Single-Source Shortest Path	(SSSP) |	All-Pairs Shortest Path  (APSP) |
| Negative | Edges	No	| Yes	| Yes (No Negative Cycles) |
| Negative Cycle| Detection|	No |	Yes |	Yes |
| Complexity |	O(E + V log V)	| O(V * E) |	O(V^3) |
| Approach	| Greedy	| DP	| DP|

### Minimum Spanning Tree
- Kruskal
- Prim

  Quick Comparison Table

|Feature |	Kruskal| 	Prim|
|---|---|---|
|Strategy|	Grows a forest of trees by adding the smallest edges.	|Grows a single tree from a starting vertex.|
|MST Property	|Always keeps a subset of edges without cycles; it might not be connected until the end.|	Always keeps the current set of edges as a single connected tree.|
|Time Complexity	|O(E log E) or O(E log V).	|O(V²) or O(E + V log V) using Fibonacci heaps.|
|Best Graph Type|	Preferred for sparse graphs (fewer edges).|	Preferred for dense graphs (many edges).|
|Disconnected Graphs	|Works on disconnected components (returns a minimum spanning forest).|	Only works on connected graphs.|
|Data Structures|	Uses Disjoint Set Union (DSU) for cycle detection.|	Uses Priority Queues (Heaps) to find the next edge.|

### Dynamic Programming
- Longest Common Subsequence
- Matrix Chain Multiplication
- 0/1 Knapsack
