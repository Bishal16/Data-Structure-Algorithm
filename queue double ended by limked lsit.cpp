
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

void push_back(int val){
cout<<"push back------  "<<val<<endl;
	if (frnt == NULL){
		frnt = new node();
		frnt->val = val;
		frnt->prv = NULL;
		frnt->nxt =NULL;

		rear = new node();
		rear = frnt;
		//prv_rear = NULL;
	}
	else{
		//prv_rear = rear;

		node *n_node = new node();
		n_node->val = val;
		n_node->prv = rear;
		n_node->nxt = NULL;

		rear->nxt = n_node;
		rear = n_node;
	}
}

void push_front(int val){
cout<<"push front------  "<<val<<endl;
	if (frnt == NULL){
		cout<<"empty queue"<<endl;
	}
	else{
		node *n_node = new node();
		n_node->val = val;
		n_node->prv = NULL;
		n_node->nxt = frnt;

		frnt->prv = n_node;
		frnt = n_node;
	}


}

void pop_front(){
	cout<<"pop front------  "<<frnt->val<<endl;
	frnt = frnt->nxt;
}

void pop_back(){
	cout<<"pop back------  "<<rear->val<<endl;
	rear = rear->prv;
	rear->nxt = NULL;
}

void print(){
	node *tmp = frnt;
	cout<<"print queue :"<<endl;
	if(frnt == NULL)
		cout<<" Empty queue !!"<<endl;
	while(tmp != NULL){
		cout<<tmp->val<<endl;
		tmp = tmp->nxt;
	}
}

void clear(){
	frnt = NULL;
	rear =NULL;
}

int main(){
	push_back(1);
	push_back(2);
	push_back(3);
	push_back(4);
	push_back(5);
	print();

	push_front(-1);
	print();

	pop_front();
	print();

	pop_back();
	pop_back();
	print();

	cout<<"front element :"<<frnt->val<<endl;
	cout<< "rear element :"<<rear->val<<endl;

	clear();

	print();

}

