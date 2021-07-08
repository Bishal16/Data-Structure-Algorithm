#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int operatorPrecedance(char ch){
	if (ch=='^')
		return 5;
	else if(ch=='*')
		return 4;
	else if( ch=='/')
		return 3;
	else if(ch=='+')
		return 2;
	else if(ch=='-' )
		return 1;
	else
		return -1;

}

void print_current_stack_situation(stack <int> cur_temp_s){
	cout<<"temp stack print : "<<endl;
	while(!cur_temp_s.empty()){
		cout<<cur_temp_s.top()<<"__"<<endl;
		cur_temp_s.pop();
		}
if(cur_temp_s.empty())
	cout<<"faka temp stack "<<endl<<endl<<endl;
}

string infix_to_postfix_conversion(string infix){
	char ch;

	stack <char> myStack;
	string postFix="";
	for (int i=0; infix[i]; i++){
		ch = infix[i];

		if (ch == '(')
			myStack.push(ch);
		else if (ch == ')'){
			while ( !myStack.empty() && myStack.top() != '('){
				postFix = postFix + myStack.top();
				myStack.pop();
			}
			if(!myStack.empty() && myStack.top()=='(')
				myStack.pop();
		}
		else{
			int operator_prec = operatorPrecedance(ch);

			if (operator_prec == -1) //found operand
				postFix = postFix + ch;

			else{ //found operator
				if (myStack.empty())
					myStack.push(ch);
				else{
					while ( !myStack.empty() && myStack.top() != '(' && operatorPrecedance(myStack.top()) >= operator_prec){//GONDOGOL
						postFix = postFix + myStack.top();
						myStack.pop();
					}
					myStack.push(ch);
				}
			}
		}
	}
	while(!myStack.empty()){
		postFix = postFix + myStack.top();
		myStack.pop();
	}
	return postFix;
}

int postFix_evaluation(string postFix){
	stack <char> main_s;
	stack <int> temp_s;
	int ans=0;
	char ch;
	for (int i = postFix.size() - 1 ; i>=0 ; i--){
		ch = postFix[i];
		main_s.push(ch);
	}

	for(int i = 0; !main_s.empty() ; i++){
		if(operatorPrecedance(main_s.top()) == -1){
			temp_s.push(main_s.top()-'0');
			main_s.pop();
		}
		//print_current_stack_situation(temp_s);if (i==3) break;//////
		else {
			int prec = operatorPrecedance(main_s.top());
			int temp_top = temp_s.top();
				//temp_top-=48;  //because char converted into int
				temp_s.pop();

			int temp_prv = temp_s.top();
				//temp_prv-=48;  //because char converted into int
				temp_s.pop();


			if ( prec == 5)
				ans = pow(temp_prv, temp_top);

			else if(prec == 4)
				ans = temp_prv * temp_top;

			else if(prec == 3)
				ans = temp_prv / temp_top;

			else if(prec == 2)
				ans = temp_prv + temp_top;

			else if(prec == 1)
				ans = temp_prv - temp_top;

			temp_s.push(ans);
			main_s.pop();



			if (main_s.empty())
				return temp_s.top();
			//cout<<"____"<<temp_prv<<" "<<prec<<" "<<temp_top<<" "<<ans<<endl<<endl;
			//print_current_stack_situation(temp_s);
		}
	}
}

int main(){
	int ans;// (A+(B^C)*D)/C
	string infix = "(1+(2^3)*4)/3",postFix;
	postFix = infix_to_postfix_conversion(infix);
	//cout<<"Post fix = "<<postFix<<endl;
	ans = postFix_evaluation(postFix);
	cout<<"infix"<<"  \t\t ----> "<<"postFix"<<"   ---->"<<"\tans"<<endl;
	cout<<infix<<"   ---->   "<<postFix<<"   ---->   "<<ans<<endl;
}
