El ordenamiento topológico organiza los nodos de un grafo dirigido acíclico (DAG) de tal manera que, para cada arista (𝑢,𝑣) 𝑢 aparece antes que 𝑣.
si se forma un ciclo quiere decir que no es posible organizar las tareas en el orden que queremos.
https://codeforces.com/contest/510/submission/297702148

vector<vector<int>>adj;
vector<bool>vis;
vector<int>order;
int n,m;

void DFS(int v){
	vis[v]=true;
	for(int u: adj[v]){
		if(!vis[u]){
			DFS(u);
		}
	}
	order.pb(v);
}

void topological_sorting(){
	for(int node=0; node<n; node++){
		if(!vis[node]){
			DFS(node);
		}
	}
	reverse(all(order));
}
//Forma de detectar un ciclo
vector<bool> num_prc; //nodos que se estan procesando
bool cycle = false;

void DFS(int v) {
    if (num_prc[v]) {
        cycle = true;
        return;
    }
    if (vis[v]) {
        return;
    }
    num_prc[v] = true;
    for (int u : adj[v]) {
        DFS(u);
        if (cycle) return; 
    }
    vis[v] = true;
    order.pb(v);
    num_prc[v] = false;
}
