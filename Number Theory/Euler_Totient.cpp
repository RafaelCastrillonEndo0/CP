//Cantidad de numeros que cumplen -> gcd(n,a) (Coprimos con n) == 1 .... desde 1... n

int phi(int n){
	int res = n;
	for(int i = 2; i * i <= n ; i++){
		if(n % i == 0){
			while(n % i == 0) n /= i;
			res -= res / i;
		}
	}
	if(n > 1) res -= res / n;
	return res;
}


//Cantidad de numeros que complen -> gcd(a,b) (Coprimos con n)  para todos los 1...n
vi phi;
void phi_n(int n){
	phi.assign(n + 1, 0);
	phi[0] = 0;
	phi[1] = 1;
	for(int i = 0; i <= n; i++){
		phi[i] = i;
	}
	for(int i = 2; i <= n; i++){
		if(phi[i] == i){
			for(int j = i; j <= n; j+=i){
				phi[j] -= phi[j] / i;
			}
		}
	}
}


//       a = base m = modulo b = exponente
//       1. cuando gcd(a,m) == 1 se y se tiene a ^ b  % m  -> se puede aplicar a ^ ( b % φ(m)) % m
	//  x ^ (   φ(m) + (n  %  φ(m)  ) % m
