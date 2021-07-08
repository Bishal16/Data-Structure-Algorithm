
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	int tc;
	cin>>tc;
	int cnt = 1;
	while(cnt <= tc){
		cout<<"Case "<<cnt<<":"<<endl;
		int i, n, m, len=0, val;
		string comand;
		cin>>n>>m;
		deque < int > dq;
		while(m--){
			cin>>comand;
			if (comand == "pushLeft"){
				cin>>val;
				if (len >= n)
					cout<<"The queue is full"<<endl;
				else{
					dq.push_front(val);
					cout<<"Pushed in left: "<<val<<endl;
					len++;
				}
			}
			else if (comand == "pushRight"){
				cin>>val;
				if (len >= n)
					cout<<"The queue is full"<<endl;
				else{
					dq.push_back(val);
					cout<<"Pushed in right: "<<val<<endl;
					len++;
				}
			}
			else if (comand == "popLeft"){
				if (dq.empty())
					cout<<"The queue is empty"<<endl;
				else{
					cout<<"Popped from left: "<<dq.front()<<endl;
					dq.pop_front();
					len--;
				}
			}
			else if (comand == "popRight"){
				if (dq.empty())
					cout<<"The queue is empty"<<endl;
				else{
					cout<<"Popped from right: "<<dq.back()<<endl;
					dq.pop_back();
					len--;
				}
			}

		}

	cnt++;
	}

}
