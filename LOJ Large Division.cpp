#include<bits/stdc++.h>
using namespace std;


bool divisible(string s, long long b){
	int r = 0,i;
	
	if(s[0] == '-') i = 1;
	else i=0;

	if (b<0)
		b=abs(b);
	for(i = i; i < s.length(); i++)
		r = ((r * 10) + s[i]-'0') % b;
	
	if(r == 0) 	return true;
	else        return false;
}

int main(){
	long long t, b;
	string a;
	cin>>t;
	for(int i = 0; i < t; i++){
		cin>>a>>b;
		if(divisible(a, b))
			cout<<"Case "<<i+1<<": "<<"divisible"<<endl;
		else
			cout<<"Case "<<i+1<<": "<<"not divisible"<<endl;
	}
}