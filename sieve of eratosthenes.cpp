#include <iostream>
#include<math.h>
using namespace std;


int sieve[100000];

int main(){
	int n;
	cin>>n;
	//int sieve[n+1];
	//for(int i = 1; i <= n; i += 1)
	//	sieve[i] = 0;
	
	for(int i = 4; i <= n; i += 2)
		sieve[i] = 1;

	for(int i = 3; i <= sqrt(n); i+=2)
		if(sieve[i] == 0)
			for(int j = i*i; j <= n; j = j+2*i  /* or j=j+i */ )
				sieve[j] = 1;
			
		
	
	sieve[1] = 1;
	for(int i = 1; i <= n; i++){
		if(sieve[i] == 0){
			cout<<i<<" ";
		}
	}

}