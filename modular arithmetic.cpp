// find (100!) % 97 = ?


#include<bits/stdc++.h>
using namespace std;


int find_mod(int n, int m){
	int ans = 1;
	for(int i = n; i >= 1; i--){
		ans = (ans * i ) % m;
		cout<<i%m<<endl;
	}
	ans = ans % m;
	return ans;
}


int main(){
	int n = 100, m = 97;
	cout<<find_mod(n, m)<<"__";

}