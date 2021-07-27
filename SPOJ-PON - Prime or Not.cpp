
#include<bits/stdc++.h>
using namespace std;



int power(int x, unsigned int y, int p){
	int res = 1;
	x = x % p;

	while(y > 0)
	{
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x*x) % p;//cout<<"ff";
	}
	return res;
}

bool millerTest(int d, int n){
	int a = 2 + rand() % (n - 4);
	int x = power(a, d, n);

	if(x==1 || x == n-1)
		return true;

	while(d != n-1){
		x = (x*x) % n;
		d = d*2;

		if(x==1)
			return false;
		if (x==n-1)
			return true;
	}
	return false;
}

bool isPrime(int n, int k){
	if(n <= 1 || n == 4)
		return false;
	
	else if(n <= 3)
		return true;
	
	
	

	// find r such that n=2^(d*r+1) for some r>= 1
	int d = n-1;
	while( d%2 == 0 )
		d = d/2;			

	// iterate k times
	for(int i = 0; i < k; i++)
		if(!millerTest(d, n))
			return false;
	
	return true;
}


int main()
{
	unsigned long long n,t,i, k = 3;
	cin>>t;
	for(i=1;i<=t;i++){
		cin>>n;
		bool ans = isPrime(n, k);
		if(ans)
			cout<<"YES"<<endl;
		else if(!ans)
			cout<<"NO"<<endl;
	}
}