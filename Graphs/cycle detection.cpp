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
#define vii vector<pair<int, int>>
#define vli vector<pair<ll, int>>
#define vll vector<pair<ll, ll>>
#define forn(i, n) for (int i = 0; i < (n); ++i)
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;
const int MAX_N = 1e6 + 3;

vector<vi> adj;
vb vis;
vi estado, p;
int inicio = -1, fin = -1;


int dfs(int u, int padre){
	estado[u] = 1;
	for(int v : adj[u]){
		if(v == padre) continue;
		if(estado[v] == 0){
			p[v] = u;
			if(dfs(v, u)) return 1;
		}else if(estado[v] == 1){
			inicio = v;
			fin = u;
			return 1;
		}
	}
	estado[u] = 2;
	return 0;
}

void solve(){
	int n,m; cin >> n >> m;
	adj.resize(n);
	vis.resize(n);
	p.resize(n);
	estado.resize(n, 0);
	for(int i = 0; i < m; i++){
		int u,v; cin >> u >> v;
		u--; v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	for(int i = 0; i < n; i++){
		if(estado[i] == 0 && dfs(i, -1)) break;
	}
	if(inicio == -1) cout << "IMPOSSIBLE" << endl;
	else{
		vi res;
		res.pb(inicio);
		for(int v  = fin; v != inicio; v = p[v]){
			res.pb(v);
		}
		res.pb(inicio);
		reverse(all(res));
		cout << sz(res) << endl;
		for(int v : res) cout << v + 1<< ' ';
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
