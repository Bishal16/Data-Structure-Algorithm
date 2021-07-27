//#include<iostream>


//find (10^100) % 12 = (10^b) % c = ?

#include<bits/stdc++.h>
using namespace std;

void bigIngRem(string s, int d){
	int i;
	if(s[0] == '-')
		i = 1;
	else 
		i=0;
	int r = 0 ;
	for(i = i; i < s.length(); i++){
		r = (( r * 10 ) + s[i] - '0' ) % d;
	
	cout<<"the remainder is :"<<r<<endl;}
}


int main(){
	string s;
	int d;
	cout<<"Enter divident and divisor :"<<endl;
	cin>>s>>d;
	bigIngRem(s,d);
}

