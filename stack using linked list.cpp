#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *nxt;
	node *prv;
};

node *root = NULL;
node *top = NULL;


void s_push(int val){cout<<"Push "<<val<<endl;
	if (root == NULL){
		root = new node();
		root->val = val;
		root->nxt = NULL;
		root->prv = NULL;
	}
	else{
		top = root;
		node *prev_top;
		while(top!= NULL){
			prev_top = top;
			top = top->nxt;
		}
		node *n_node = new node();
		n_node->val = val;
		n_node->nxt = NULL;
		n_node->prv = prev_top;

		prev_top->nxt = n_node;
		top = n_node;

	}
}

void s_pop(){cout<<"POP"<<endl;
	if (top == NULL)
		cout<<"stack underflow"<<endl;

	else if (top->prv == NULL)
			top = NULL;
	else{
		top->prv->nxt = NULL;
		top = top->prv;}
	}


bool s_empty(){cout<<"is_empty ? "<<endl;
	if (top == NULL)
		return true;
	else
		return false;
}

void s_print(){cout<<"Print"<<endl;
	node *tmp = top;
	while(tmp!= root){
		cout<<tmp->val<<endl;
		tmp = tmp->prv;
	}
	cout<<root->val<<endl;
}


int main(){
	s_push(5);
	s_push(10);
	s_push(15);
	s_push(20);
	s_push(25);

	s_print();

	s_pop();

	s_print();

	if (s_empty())
		cout<<"empty"<<endl;
	else
		cout<<"not empty"<<endl;

}
