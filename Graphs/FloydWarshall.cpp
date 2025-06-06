#include <bits/stdc++.h>
using namespace std;
 
#define Fast ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define ff first
#define ss second
#define pb push_back
#define all(x) x.begin(), x.end()
#define sz(x) int(x.size())
#define vi vector<int>
#define vb vector<bool>
#define vl vector<ll>
#define vii vector<pair<int, ll>>
#define vli vector<pair<ll, int>>
#define vll vector<pair<ll, ll>>
#define forn(i, n) for (int i = 0; i < (n); ++i)
const ll INF = LLONG_MAX  / 4;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e6 + 3;


//distancias minimas entre todos los nodos
void floyd(vector<vl> &d, int &n){
	for(int k = 0; k < n; k++){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(d[i][k] < INF && d[k][j] < INF){
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
				}
			}
		}
	}
}

void init(vector<vl> &adj, vector<vl> &d, int &n){
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j) d[i][j] = 0;
			else if(adj[i][j] > 0) d[i][j] = adj[i][j];
			else d[i][j] = INF;
		}
	}
}

void solve(){
	int n,m,q; cin >> n >> m >> q;
	vector<vl> adj(n, vl(n, 0));
	for(int i = 0; i < m; i++){
		int u,v;
		ll c;
		cin >> u >> v >> c;
		u--; v--;
		//grafo no dirigido
		if(adj[u][v] == 0 || adj[v][u] == 0){
			adj[u][v] = c;
			adj[v][u] = c;
		}else{
			adj[u][v] = min(adj[u][v], c);
			adj[v][u] = adj[u][v];
		}
	}
	vector<vl> d(n, vl(n));
	init(adj, d, n);
	floyd(d, n);
	while(q--){
		int u,v; cin >> u >> v;
		u--; v--;
		if(d[u][v] == INF) cout << -1 << endl;
		else cout << d[u][v] << endl;
	}

}


int main() {
    Fast
    //int t; cin >> t;
   	//while(t--){
    	solve();
    //}
    return 0;
}
