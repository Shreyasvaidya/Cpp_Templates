#include<iostream>

const int mod = 1000000007;
long long modularAdd(long long a, long long b,int modulus = mod){
	return (a%modulus+ b%modulus)%modulus; 
}
long long modularMult(long long a, long long b,int modulus = mod){
	return ((a%modulus)* (b%modulus))%modulus;
}
void modularPrecomputeFactorial(long long upperLimit,long long *arr){
	arr[0]=1;
	arr[1] = 1;
	for(int i=2;i<=upperLimit;i++){
		arr[i] = modularMult(arr[i-1],i);
	}
}
long long binExpo(long long n,long long pow, int modulus = mod){
	long long ans=1;
	long long toBeMultiplied = n;
	while(pow>0){
		if(pow%2){
			ans = modularMult(ans,toBeMultiplied);
		}
		pow = pow>>1;
		toBeMultiplied =modularMult(toBeMultiplied,toBeMultiplied);
	}
	return ans;
}

long long modInv(long long n){
	return binExpo(n,mod-2);
}
long long modular_nCr(long long n,long long r,long long *factorialArr,int modulus = mod){
	long long Nr = factorialArr[n]%mod;
	long long Dr = modularMult(factorialArr[r],factorialArr[n-r]);
	return modularMult(Nr,modInv(Dr));
}
