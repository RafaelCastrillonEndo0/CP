//(Fenwick Tree o Binary Indexed Tree, BIT), una estructura de datos eficiente para realizar consultas de suma en rangos y actualizaciones puntuales en un arreglo
//Con el metodo add podemos agregar a un indice un valor delta.
//Consulta O(LogN) Actualizacion O(LogN)
//Solo funciona para operaciones acumulativas como suma, mínimo, máximo o XOR. No es adecuado para operaciones más complejas.




struct FenwickTree {
    vector<int> bit;
    int n;
    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()){
	    for (int i = 0; i < n; i++) {
	        bit[i] += a[i];
	        int r = i | (i + 1);
	        if (r < n) bit[r] += bit[i];
	    }
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
