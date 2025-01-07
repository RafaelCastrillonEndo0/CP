const int MAX_NODES = 1000; 

void solve() {
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n,vector<int>());
    for(int i=0; i<m; i++){
    	int u,v;cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
    }
    vector<bitset<MAX_NODES>>reach(MAX_NODES);
    for(int i=0; i<n; i++){
    	reach[i].reset();
    }
    for(int i=0; i<n; i++){
    	reach[i].set(i);
    }
    for(int v=n-1; v>=0; v--){
    	for(int u: adj[v]){
    		reach[v]|=reach[u];
    	}
    }
    for(int node=0; node<n; node++){
    	int cnt= reach[node].count();
    	cout<<cnt<<" ";
    }
    cout<<endl;
}