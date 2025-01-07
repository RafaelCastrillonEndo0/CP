//Ventana deslizante, se está encontrando el valor más pequeño en una venta de K elementos
//O(n)

void solve() {
    int n, k;cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
    	while(!dq.empty() && dq.front()<=i-k){//eliminar elementos fuera de la ventana
    		dq.pop_front();
    	}
        while (!dq.empty() && a[dq.back()] >= a[i]) {//eliminar elemento que no son utiles para el minimo
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            ans.pb(a[dq.front()]);
        }
    }
    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;
}
