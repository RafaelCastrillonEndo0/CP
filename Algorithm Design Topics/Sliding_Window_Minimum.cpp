void solve() {
    int n, k;cin>>n>>k;
    vector<int>a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
    	while(!dq.empty() && dq.front()<=i-k){
    		dq.pop_front();
    	}
        while (!dq.empty() && a[dq.back()] >= a[i]) {
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