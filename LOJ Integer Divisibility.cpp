#include<bits/stdc++.h>
using namespace std;



int no_of_digits(int d, int s){
	//while(true){
		int r = 0;
		int i = 0;
		while(true){
			r = ((r * 10) + s) % d;
			i++;
			if(r == 0)
				break;
		}
		return i;
	// }
}

int main(){
	int t, n , digit;
	cin>>t;
	for(int i = 0; i < t; i++){
		cin>>n>>digit;
		cout<<"Case "<<i+1<<": "<<no_of_digits(n, digit)<<endl;
	}
}