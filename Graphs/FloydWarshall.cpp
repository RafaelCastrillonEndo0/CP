void FloydWarshall(vector<vector<int>>&d){
	for(int k=0; k<n; k++){//k-> nodo intermedio
		for(int i=0; i<n; i++){//-> i->nodo de inicio
			for(int j=0; j<n; j++){//j->nodo de destino
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				/*
	            Consideramos si la distancia que hay actualmente
	            entre el nodo i y j es mayor 
	            a la distancia entre ir al nodo intermedio y del intermedio 
	            ir al nodo de destino (j)
	            */
			}
		}
	}
}
//formar la matriz d
void init_d(vector<vector<int>>& adj, vector<vector<int>>& d, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i == j) {d[i][j] = 0;} 
            else if(adj[i][j] > 0) {d[i][j] = adj[i][j];}
            else{d[i][j] = INF;}
        }
    }
}


