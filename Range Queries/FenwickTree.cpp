(Fenwick Tree o Binary Indexed Tree, BIT), una estructura de datos eficiente para realizar consultas de suma en rangos y actualizaciones puntuales en un arreglo
con el metodo add se logra modificar correctamente un indice y asi mismo se modifica donde la modificacion en el indice hace un cambio
Consulta O(LogN)
Actualizacion O(LogN)





struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

void solve(){
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	FenwickTree ft(a);
	int l,r;cin>>l>>r;
	l--;r--;
	cout<<ft.sum(l,r)<<endl;
}
