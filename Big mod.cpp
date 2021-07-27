// find  (2^100) % m


#include<bits/stdc++.h>
using namespace std;


int bigMOd(int a, int b, int m){
	if(b == 0)
		return 1 % m;
	
	int x = bigMOd(a, b/2, m);
	x = (x * x) % m;
	
	if(b % 2 == 1)
		x = (x * a) % m;
	return x;
}

int main(){

	int a = 2, b = 5, m = 10;
	int ans = bigMOd(a, b , m);
	cout<<ans;
}



