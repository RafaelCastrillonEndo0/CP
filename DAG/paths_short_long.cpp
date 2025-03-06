#include <bits/stdc++.h>
using namespace std;
 
#define Fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
const ll INF = 1e12;
const ll MOD =998244353;
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vii vector<pair<int, int>>
#define vli vector<pair<ll, int>>
#define vll vector<pair<ll, ll>>

int n;
vector<vector<int>>adj,paths;
vi indegree, order;

void topoSort(){
	indegree.assign(n,0);
	for(int i=0; i<n; i++){
		for(int v: adj[i])
			indegree[v]++;
	}
	queue<int>q;
	for(int i=0; i<n; i++)
		if(indegree[i]==0)
			q.push(i);
	while(!q.empty()){
		int u=q.front();
		order.pb(u);
		q.pop();
		for(int v: adj[u]){
			indegree[v]--;
			if(indegree[v]==0)
				q.push(v);
		}
	}
}

void shortest(int node){
	topoSort();
	vi dist(n,-INT_MAX), parent(n,-1);
	dist[node]=0;
	paths.assign(n,{});
	for(int u: order){
		if(dist[u]==-INT_MAX)continue;
		for(int v: adj[u]){
			if(dist[v]<dist[u]+1){
				dist[v]=dist[u]+1;
				parent[v]=u;
			}
		}
	}
	for(int v=0; v<n; v++){
		if(dist[v]==-INT_MAX)continue;
		vi path_tm;
		for(int x=v; x!=-1; x=parent[x])
			path_tm.pb(x);
		reverse(all(path_tm));
		paths[v]=path_tm;
	}
	
}

void solve(){
	int m;
	cin>>n>>m;
	adj.assign(n,vector<int>());
	for(int i=0; i<m; i++){
		int u,v;cin>>u>>v;
		u--;v--;
		adj[u].pb(v);
	}
	shortest(0);
	for(int u: order)cout<<u+1<<' ';
	cout<<endl;
	for(int i=0; i<n; i++){
		if(paths[i].empty()){
			cout<<"No se puede alcanzar el nodo ->"<<i+1<<endl;
		}else{
			cout<<"Camino mas corto a ->"<<i+1<<endl;
			for(int node: paths[i])cout<<node+1<<' ';
			cout<<endl;
		}
	}
	
}

 
int main() {
    Fast
    //int t;cin>>t;
    //cout << fixed << setprecision(6);
   	//while(t--){
    	solve();
    //}
    return 0;
}