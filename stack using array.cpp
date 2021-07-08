#include<bits/stdc++.h>
using namespace std;

int stk[100];
int top=-1;

void push_val(int val){
	if (top==99)
		cout<<"stack overflow"<<endl;
	else{
	top++;
	stk[top]=val;
	}
}
void pop_val(){
	if (top==-1)
		cout<<"stack underflow"<<endl;
	top--;
}
bool s_empty(){
	if (top==-1)
		return true;
	else
		return false;
}
int print_val(int top){
	int i=0;
	while(i<=top){
		cout<<stk[i]<<endl;
		i++;
	}
}

int main(){


	push_val(50);
	push_val(52);
	push_val(53);
	push_val(54);

	print_val(top);
	pop_val();

	if (s_empty())
		cout<<"empty"<<endl;
	else
		cout<<"not empty"<<endl;


}
