
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
	int val;
	node *prv;
	node *nxt;
};

node *frnt = NULL;
node *rear = NULL;

void enqueue(int val){
	if (frnt == NULL){
		frnt = new node();
		frnt->val = val;
		frnt->prv = NULL;
		frnt->nxt =NULL;

		rear = new node();
		rear = frnt;
	}
	else{
		node *n_node = new node();
		n_node->val = val;
		n_node->nxt = NULL;
		n_node->prv = rear;

		rear->nxt = n_node;
		rear = n_node;
	}
}

void dqueue(){
	if (frnt != NULL){
		frnt = frnt->nxt;
	}
	else
		cout<<"empty queue"<<endl;

}

void print(){
	node *tmp = frnt;
	cout<<"print queue "<<endl;
	while(tmp != NULL){
		cout<<tmp->val<<endl;
		tmp = tmp->nxt;
	}
}

int main(){
	enqueue(1);
	enqueue(2);
	enqueue(3);
	enqueue(4);
	enqueue(5);
	print();

	dqueue();
	print();

	dqueue();
	print();

}
