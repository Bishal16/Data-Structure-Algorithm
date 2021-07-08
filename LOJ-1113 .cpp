
#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
using namespace std;

int main(){

    int t,i;
    cin>>t;
    string comand;
    for(i = 0; i < t; i++){
		cout<<"Case "<<i+1<<":"<<endl;
		stack <string> backword, forwrd;
		string current_site = "http://www.lightoj.com/";
		while(true){
			getline(cin,comand);
			if (comand == "QUIT")
				 break;
			else{
				if (comand[0] == 'V'){ //visit
					backword.push(current_site);
					current_site = comand.erase(0,6);
					while(!forwrd.empty())
						forwrd.pop();
					cout<<current_site<<endl;
				}
				else if(comand == "BACK"){ //backword
					if (backword.empty()){
						cout<<"Ignored"<<endl;
					}
					else{
						forwrd.push(current_site);
						current_site = backword.top();
						backword.pop();
						cout<<current_site<<endl;
					}
				}
				else if(comand == "FORWARD"){
					if(forwrd.empty())
						cout<<"Ignored"<<endl;
					else{
						backword.push(current_site);
						current_site = forwrd.top();
						forwrd.pop();
						cout<<current_site<<endl;
					}
				}
			}
		}
    }
return 0;
}




