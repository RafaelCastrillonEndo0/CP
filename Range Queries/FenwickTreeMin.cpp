//Logramos obtener el minimo para un  rango desde [0,R] no funciona para consultar rangos entre [L,R]
//complejidad -> update ( O(LogN) ) -> Constructor ( O(NLogN) )
//La operación update ajusta el valor en el índice idx y propaga la actualización a través de los nodos relevantes del Fenwick Tree.


struct FenwickTreeMin {
    vector<int> bit;
    int n;
    const int INF = (int)1e9;

    FenwickTreeMin(int n) {
        this->n = n;
        bit.assign(n, INF);
    }

    FenwickTreeMin(vector<int> a) : FenwickTreeMin(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            update(i, a[i]);
    }

    int getmin(int r) {
        int ret = INF;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret = min(ret, bit[r]);
        return ret;
    }

    void update(int idx, int val) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] = min(bit[idx], val);
    }
};

void solve(){
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	FenwickTreeMin	ftm(a);
	int r;cin>>r;
	r--;
	cout<<ftm.getmin(r)<<endl;
	
}
