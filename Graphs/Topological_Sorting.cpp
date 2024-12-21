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
