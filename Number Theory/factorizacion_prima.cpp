//Factorizacion prima de un nuemero 
vector<int>factores;
void factors(int &n){
	for(int i=2; i*i<=n; i++){
		while(n%i==0){
			factores.pb(i);
			n/=i;
		}
	}
	if(n>1)factores.pb(n);
}
