struct Edge {
    int a, b, cost;
}; 
 
void solve(){
	int n,m,v,t;
	cin>>n>>m>>v>>t;
	vector<Edge>edg;
	vector<int>d(n,INF);
	vector<int>p(n,-1);
	for(int i=0; i<m; i++){
		int x,y,c;
		cin>>x>>y>>c;
		edg.pb({x,y,c});
	}
	d[v]=0;
	for(;;){
		bool any=false;
		for(Edge e: edg){
			if(d[e.a]<INF){
				if(d[e.b]> d[e.a]+e.cost){
					d[e.b]=d[e.a]+e.cost;
					p[e.b]=e.a;
					any=true;
				}
			}
		}
		if(!any){
			break;
		}
	}
	if(d[t]==INF){
		cout<<"-1"<<endl;//no rutas de v -> t
		return;
	}
	vector<int>path;
	for(int cur = t; cur!=-1; cur=p[cur]){
		path.pb(cur);
	}
	reverse(all(path));
	//ruta de v->t
	for(int u: path)
	{
		cout<<u<<" ";
	}
	cout<<endl;
	 
}