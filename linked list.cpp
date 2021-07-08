
/*Created by Mahathir Bishal
https://web.facebook.com/mahathirmohammad.bishal/
*/
#include<stdio.h>
#include<iostream>
using namespace std;

struct node{
	int val;
	node *nxt;
};
node *root=NULL;


int append(int val){
	if (root==NULL){
		root = new node();
		root->val=val;
		root->nxt=NULL;
	}
	else{
		node *rcopy=root;

		while (rcopy->nxt!=NULL){
			rcopy=rcopy->nxt;
		}
		node *new_node= new node();
		new_node->val=val;
		new_node->nxt=NULL;

		rcopy->nxt=new_node;
	}
}

int print(){
	int i;
	node *rcopy=root;
	for ( i=0; rcopy->nxt!=NULL ;i++){
		cout<<i<<" "<<rcopy->val<<endl;
		rcopy=rcopy->nxt;
	}
	cout<<i<<" "<<rcopy->val<<endl;

}

int delet(int val){
	if (val==root->val){
		root=root->nxt;
	}
	else{
		node *temp=root,*prv;
		while(temp->val!=3){
			prv=temp;
			temp=temp->nxt;
		}
		prv->nxt=temp->nxt;
	}

}

int main(){
	int i=0,val;
	while(i<5){
		cin>>val;
		append(val);
		i++;
	}
	cout<<"the linked list printed :"<<endl;
	print();

	delet(3);
	cout<<"deleted linked list printed :"<<endl;
	print();

}
