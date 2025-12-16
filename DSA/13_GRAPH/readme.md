# 📚 Graph Data Structure – Interview Patterns & Roadmap

started in : 24 aug 2025

1 : Undirected Unweighted graph
  dfs and bfs

2: directed weighted graph
  dfs and bfs

3: detect cycle
  i> undirected graph
    dfs and bfs
  ii> directed graph
    dfs and bfs

4: Topo sort
  dfs and bfs(kahn algo)

5: bipartie graph

6: shortest path
  bfs for all
  from src to dest
  in DAG

7 : Dijkistra 
  unoptimied o(v^2)
  optimised: o(ElogV)
  DAG shortest path distance
  Shortest path arr in undirect weighted graph

8: Bellman ford algo
  implementation
  negative cycle detection

9: Floyd Warshall algo
  implementation 
  why prefered over belman and dijkstra

10: Practice problems
  1-> bfs for shortest path

11: Eular Path and Ckt





Mastering graphs is crucial for coding interviews (FAANG, startups, financial companies).  
They test **recursion, BFS/DFS, problem-solving, and optimization skills**.

This guide breaks down **important graph patterns → sub-patterns → example problems**.

---

## 📌 1. Traversal & Representation Patterns

**Foundation for almost every graph problem.**

- **Adjacency List vs Matrix**
  - List → space-efficient (O(V+E))
  - Matrix → simple but O(V²)
- **BFS (Breadth-First Search)**
  - Shortest path in **unweighted graph**
  - Level-order traversal
  - Connected components
- **DFS (Depth-First Search)**
  - Cycle detection
  - Topological sort
  - Connected components

✅ Example Problems:

- _Shortest Path in Binary Matrix_ (LC 1091)
- _Number of Islands_ (LC 200)

---

## 📌 2. Connected Components & Graph Coloring

**Used to group related nodes.**

- **Union-Find (Disjoint Set Union – DSU)**
  - Detect cycle in undirected graph
  - Kruskal’s MST
- **DFS/BFS**
  - Count connected components
  - Bipartite Check
- **Graph Coloring**
  - Bipartite check
  - Odd-cycle detection

✅ Example Problems:

- _Number of Provinces_ (LC 547)
- _Is Graph Bipartite?_ (LC 785)

---

## 📌 3. Cycle Detection Patterns

**Important for dependencies & deadlock detection.**

- **Undirected Graph**
  - DFS with parent check
  - Union-Find
- **Directed Graph**
  - DFS with recursion stack
  - Kahn’s Algorithm (Topo Sort)

✅ Example Problems:

- _Course Schedule_ (LC 207)
- _Detect Cycle in Undirected Graph_ (GFG classic)

---

## 📌 4. Shortest Path Patterns

**Key for maps, networking, trading systems.**

- **Unweighted Graph**
  - BFS
- **Weighted Graph (positive weights)**
  - Dijkstra’s Algorithm
- **Weighted Graph (with negative weights)**
  - Bellman-Ford
- **All-Pairs Shortest Path**
  - Floyd-Warshall
- **Grid-based Shortest Path**
  - BFS + Direction Vectors

✅ Example Problems:

- _Network Delay Time_ (LC 743 → Dijkstra)
- _Cheapest Flights Within K Stops_ (LC 787 → Bellman-Ford / BFS + PQ)

---

## 📌 5. Minimum Spanning Tree (MST)

**Classic weighted graph problem.**

- **Kruskal’s Algorithm** (Union-Find)
- **Prim’s Algorithm** (Min Heap / PQ)

✅ Example Problems:

- _Minimum Spanning Tree_ (GFG)
- _Connecting Cities With Minimum Cost_ (LC 1135)

---

## 📌 6. Topological Sorting Patterns

**Dependency resolution (courses, tasks, build systems).**

- **DFS-based Topo Sort**
- **Kahn’s Algorithm (BFS-based)**

✅ Example Problems:

- _Course Schedule II_ (LC 210)
- _Alien Dictionary_ (LC 269 – Hard)

---

## 📌 7. Flood Fill & Matrix Graph Problems

**Grid = implicit graph. Very common in interviews.**

- BFS/DFS in grid
- Multi-source BFS
- Connected components in 2D grid
- Boundary traversal

✅ Example Problems:

- _Number of Islands_ (LC 200)
- _Rotting Oranges_ (LC 994)
- _Walls and Gates_ (LC 286)

---

## 📌 8. Advanced Graph Patterns

**For tough FAANG/competitive interviews.**

- **Strongly Connected Components (SCC)**
  - Kosaraju’s Algorithm
  - Tarjan’s Algorithm
- **Bridges & Articulation Points**
  - Tarjan’s DFS
- **Eulerian Path & Circuit**
- **Hamiltonian Path** (NP-Hard, variations may appear)

✅ Example Problems:

- _Critical Connections in a Network_ (LC 1192 → Bridges)
- _Evaluate Division_ (LC 399 → Graph + DFS/BFS)

---

# 🎯 Roadmap to Practice

1. **Traversal (DFS/BFS)** → foundation
2. **Connected Components & Coloring**
3. **Cycle Detection & Topological Sort**
4. **Shortest Paths (BFS → Dijkstra → Bellman-Ford → Floyd-Warshall)**
5. **MST (Kruskal, Prim)**
6. **Grid-based Graphs (Islands, Oranges, Gates)**
7. **Advanced (SCC, Bridges, Tarjan)**

---

🔥 **Tip:**  
If you master these **8 patterns**, you’ll be able to solve **90%+ of graph interview problems**.

---
