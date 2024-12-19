vector<vector<pair<int, int>>> adj;
vector<ll>d;
vector<int>p;
 
void dijkstra(int s, vector<ll>& d, vector<int>& p) {
    int n = sz(adj);
    d.assign(n, INF);
    p.assign(n, -1);
    vector<bool> vis(n, false);  
    priority_queue<pair<ll, int>> q;  
    d[s] = 0;
    q.push({0, s});  
    while (!q.empty()) {
        int a = q.top().second;  
        q.pop();
        if (vis[a]) continue;
        vis[a] = true;
        for (auto u : adj[a]) {
            int b = u.first;
            ll w=u.second;
            if (d[a] + w < d[b]) {
                d[b] = d[a] + w;
                p[b] = a;
                q.push({-d[b], b});
            }
        }
    }
}
vector<int>rpath(int s, int t, vector<int>const &p){
	vector<int>path;
	for(int v=t; v!=s; v=p[v]){
		path.pb(v);
	}
	
	path.pb(s);
	reverse(all(path));
	return path;
}
















