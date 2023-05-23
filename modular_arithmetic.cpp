#include<iostream>
long long int addMod(long long x,long long y,int mod){
	return ((x)%mod + (y)%mod)%mod;
}
long long int multMod(long long x,long long y,int mod){
	return( (x%mod) * (y%mod))%mod;
}
