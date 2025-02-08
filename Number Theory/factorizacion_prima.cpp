//Factorizacion prima de un nuemero 
//Para saber la cantidad de divisores de un numero n -> (ai1+1)*(ai2+1)*...(ak+1)
//Para saber la suma de los dividores de un numero n -> (pi1)^(ai1+1)-1/pi-1*...(pi2)^(ai2+1)-1/pi2-1
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
