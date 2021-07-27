#include<bits/stdc++.h>
using namespace std;

int N = 100;
int status[100/32];

bool check(int num, int pos){
	return (bool)(num & (1<<pos));
}

int sett(int num, int pos){
	return (num | (1<<pos));
}

void sieve(){
	for( int i = 3; i <= sqrt(N); i += 2){
		if(check(status[i/32], i%32) == 0){
			for(int j = i*i; j <= N; j += 2*i){
				status[j/32] = sett(status[j/32], j%32);
			}
		}
	}
}

int main(){
	sieve();
	//print the sieve
	cout<<2<<endl;
	for(int i = 3; i <= N; i+=2){
		bool x = (bool) ( status[i/32] & (1<<(i%32) ) );
		if( x==0){//check(status[i/32], i%32) == 0
			cout<<i<<endl;
		}
	}	
}