El propósito principal de un Minimum Spanning Tree es encontrar un conjunto de aristas que conecten todos los vértices de un grafo de manera eficiente, de tal forma que la suma de los pesos de esas aristas sea lo más pequeña posible.


Propiedades clave:
Conexión de todos los vértices: Un MST debe conectar todos los vértices del grafo, sin ningún vértice desconectado.
Minimización del peso: La suma de los pesos de las aristas en el MST debe ser mínima entre todos los posibles árboles de expansión del grafo.
Árbol: El MST es un árbol, por lo que no tiene ciclos.




struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};


struct DMST {
    int n;
    vector<Edge> edges;
    vector<int> parent, min_in_edge, component, visited;

    DMST(int nodes) : n(nodes) {}

    void add_edge(int u, int v, int weight) {
        edges.pb({u, v, weight});
    }

    void initialize_min_in_edges(int root) {
        min_in_edge.assign(n, INF);
        parent.assign(n, -1);
        for (auto &e : edges) {
            if (e.u != e.v && e.weight < min_in_edge[e.v]) {
                min_in_edge[e.v] = e.weight;
                parent[e.v] = e.u;
            }
        }
        min_in_edge[root] = 0;
    }

    int find_cycles_and_assign_components(int &component_count, int root, int &cost) {
        visited.assign(n, -1);
        component.assign(n, -1);
        for (int i = 0; i < n; i++) {
            if (visited[i] == -1) {
                int curr = i;
                while (curr != -1 && visited[curr] == -1) {
                    visited[curr] = i;
                    curr = parent[curr];
                }
                if (curr != -1 && visited[curr] == i) {
                    int node = curr;
                    do {
                        component[node] = component_count;
                        cost += min_in_edge[node];
                        node = parent[node];
                    } while (node != curr);

                    component_count++;
                }
            }
        }

        if (component_count == 0) {
            for (int i = 0; i < n; i++) {
                if (i != root && parent[i] != -1) {
                    cost += min_in_edge[i];
                }
            }
            return 0;
        }

        for (int i = 0; i < n; i++) {
            if (component[i] == -1) {
                component[i] = component_count++;
            }
        }

        return component_count;
    }

    void rebuild_edges(int component_count) {
        vector<Edge> new_edges;
        for (auto &e : edges) {
            int u = component[e.u];
            int v = component[e.v];
            if (u != v) {
                new_edges.pb({u, v, e.weight - min_in_edge[e.v]});
            }
        }
        edges = move(new_edges);
        n = component_count;
    }

    int find_dmst(int root) {
        int cost = 0;
        while (true) {
            initialize_min_in_edges(root);
            int component_count = 0;
            if (find_cycles_and_assign_components(component_count, root, cost) == 0) {
                break;
            }

            rebuild_edges(component_count);
            root = component[root];
        }

        return cost;
    }
};
