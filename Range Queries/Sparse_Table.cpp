template <typename T>
struct sparse_table{
    vector<vector<T>> ST;
    
    sparse_table(vector<T> &A){
        int N = A.size();
        int LOG = 32 - __builtin_clz(N);
        ST = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; i++){
            ST[0][i] = A[i];
        }
        for (int i = 0; i < LOG - 1; i++){
            for (int j = 0; j < N - (1 << i); j++){
                ST[i + 1][j] = min(ST[i][j], ST[i][j + (1 << i)]);
            }
        }
    }
    
    T get(int L, int R){
        R++;
        int d = 31 - __builtin_clz(R - L);
        return min(ST[d][L], ST[d][R - (1 << d)]);
    }
    
};

void solve() {
	int n;cin>>n;
	vi a(n);
	for(int i=0; i<n; i++){
		cin>>a[i];
		
	}
	sparse_table<int> st(a);
	int l,r;cin>>l>>r;
	l--;r--;
	int ans= st.get(l,r);
	cout<<ans<<endl;
	
}
