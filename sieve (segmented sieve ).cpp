
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cout<<"Enter the range of number a & b : ";
	cin>>a>>b;
	
	

	//normal sieve upto sqrt(b)

	int sqb = sqrt(b);
	int root_sieve[sqb+1];
	for(int  i = 0; i <= sqb; i++)
		root_sieve[i] = 1;

	
	for(int i = 2; i <= sqb; i+=2)
		root_sieve[i] = 0;		//root_sieve[x] = 0 indicate not prime
	root_sieve[2] = 1;//corner case

	for(int i = 3; i <= sqb; i+=2){
		for(int j = i*i; j <= sqb; j+=i){
			root_sieve[j] = 0;
		}
	}
	//checking
	//for(int i = 2; i <= sqb; i+=1)
	//	cout<<"["<<i<<"] = "<<root_sieve[i]<<endl ;



	int sieve[b+1];
	for(int i = a; i <= b; i++)
		sieve[i] = 1;

	for(int i = 2; i <= sqb; i+=1){
		int x = 0;

		if(root_sieve[i] == 1){
			while(x <= b){
				if(x >= a){
					sieve[x] = 0;
				}
				x = x + i;
			}
		}
	}


	cout<<"prime number from "<<a<<" to "<<b<<" is :"<<endl;
	for(int i = a; i <= b; i++)
		if(sieve[i] == 1)
			cout<<i<<" " ;

		
}