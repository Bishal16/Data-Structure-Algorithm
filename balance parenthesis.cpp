#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
int main(){
string bracket="((())){}";
stack <char> s,t;

for (int i=0 ; i<bracket.size(); i++){
	if(bracket[i]=='(' || bracket[i] == '{' || bracket[i] == '{' )
		s.push(bracket[i]);
	else
		t.push(bracket[i]);
}
/*
while(s.empty()==2){
	cout<<s.top()<<"  "<<t.top()<<endl;
	s.pop();
	t.pop();
}//
while(s.empty()==2){
	char s1=s.top(), t1=t.top();
	cout<<s1<<"  "<<t1<<endl;
	if (s1!=t1){
		cout<<"wrong"<<endl;
		cout<<"llll";
		return 0;
	}
	s.pop();
	t.pop();
}
cout<<"okay";
}

*/

//string s;
int checkBalance(s){
	stack <char> mystack;
	if (s=="")
		return 1;
	for (int i=0;i<s.size();i++){
		char c=s[i];
		if ( c=="(" || c=="{" )
			mystack.push(c) //#push the opening bracket
		else{
			if (mystack.empty())
				return 2;
			if ( c=="{" & mystack.peek()!="}")// #the brackets dont match
				return 2;
			if ( c=="(" & mystack.peek()!=")")// #the brackets dont matchs
				return 2;
			mystack.pop();// #pop matching brackets
		}
	}
	if ( mystack.empty())// #stack must be empty at the end
		return 1;
	return 2;
}


int main(){
int a;
string p="(){}";
if (checkBalance(p)==1)
	a=5;
else
	a=6;
cout<< a;}
/*print checkBalance("()(((")
print checkBalance("()(}")
*/

