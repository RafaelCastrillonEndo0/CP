El propósito principal de un Minimum Spanning Tree es encontrar un conjunto de aristas que conecten todos los vértices de un grafo de manera eficiente,
de tal forma que la suma de los pesos de esas aristas sea lo más pequeña posible.


Propiedades clave:
Conexión de todos los vértices: Un MST debe conectar todos los vértices del grafo, sin ningún vértice desconectado.
Minimización del peso: La suma de los pesos de las aristas en el MST debe ser mínima entre todos los posibles árboles de expansión del grafo.
Árbol: El MST es un árbol, por lo que no tiene ciclos.


//Minimum Spanning tree con Union-Find
struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

struct MST {
    vector<int> parent, rank;
    vector<Edge> edges, result;
    int n, cost = 0;

    MST(int nodes) : n(nodes) {
        parent.resize(n);
        rank.resize(n, 0);
    }

    void make_set(int v) {
        parent[v] = v;
        rank[v] = 0;
    }

    int find_set(int v) {//encontrar representante del nodo
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b) {
        a = find_set(a);//representante de a
        b = find_set(b);//representante de b
        if (a != b) {
            if (rank[a] < rank[b])
                swap(a, b);
            parent[b] = a;//el representante de b ahora es a
            if (rank[a] == rank[b])
                rank[a]++;
        }
    }

    void add_edge(int u, int v, int weight) {
        edges.pb({u, v, weight});
    }
    
    void kruskal() {
        sort(all(edges));
        for (int i = 0; i < n; i++){
        	make_set(i);
        }
        for (Edge e : edges) {
            if (find_set(e.u) != find_set(e.v)) {//si no estan en la misma componente
                cost += e.weight;
                result.push_back(e);
                union_sets(e.u, e.v);//unimos u con v
            }
        }
    }
   
};
