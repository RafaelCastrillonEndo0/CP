
//El Sparse Table es una estructura de datos eficiente que permite realizar consultas rápidas en arreglos estáticos, es decir,
//arreglos que no cambian después de ser construidos. Es muy útil para problemas donde se necesita consultar valores como mínimos, máximos,
//o valores de una operación asociativa (por ejemplo, GCD o suma) en un rango específico de índices.




//O(N log N)
template <typename T>
struct sparse_table_min{
    vector<vector<T>> ST;
    
    sparse_table_min(vector<T> &A){
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
    //O(1)
    T get(int L, int R){
        R++;
        int d = 31 - __builtin_clz(R - L);
        return min(ST[d][L], ST[d][R - (1 << d)]);
    }
    
};

template <typename T>
struct sparse_table_max{
    vector<vector<T>> ST;
    sparse_table_max(vector<T> &A) {
        int N = A.size();
        int LOG = 32 - __builtin_clz(N);
        ST = vector<vector<T>>(LOG, vector<T>(N));
        for (int i = 0; i < N; i++) {
            ST[0][i] = A[i];
        }
        for (int i = 0; i < LOG - 1; i++) {
            for (int j = 0; j < N - (1 << i); j++) {
                ST[i + 1][j] = max(ST[i][j], ST[i][j + (1 << i)]);
            }
        }
    }
    
    // O(1) 
    T get(int L, int R) {
        R++;
        int d = 31 - __builtin_clz(R - L);
        return max(ST[d][L], ST[d][R - (1 << d)]);
    }
};
