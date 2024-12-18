struct Edge {
    int a, b, cost;
}; 
 
void solve(){
	int n,m,v,t;cin>>n>>m>>v>>t;
	vector<Edge>edg;
	vector<int>d(n,INF);
	d[v]=0;
	vector<int>p(n,-1);
	int x;
	for(int i=0; i<n; i++){
		x=-1;
		for(Edge e: edg){
			if(d[e.a]<INF){
				if(d[e.b]>d[e.a]+e.cost){
					d[e.b]=max(-INF,d[e.a]+e.cost);
					//asegura que la mejora no sea mayor -INF
					p[e.b]=e.a;
					x=e.b;
				}
			}
		}
	}
	//si x despues de n iteraciones se sigue actualizando
	//quiere decir que hay un ciclo negativo
	if(x==-1){
		cout<<"-1"<<endl;
		return;
	}
	int y=x;
	for(int i=0; i<n; i++){
		y=p[y];
	}
	vector<int>path;
	for(int cur=y;; cur=p[cur]){
		path.pb(cur);
		if(cur==y && sz(path)>1){
			break;
		}
	}
	reverse(all(path));
	//Ciclo Negativo
	for(int u: path){
		cout<<u<<" ";
	}
	
}