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
