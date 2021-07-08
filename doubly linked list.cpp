#include<iostream>
using namespace std;

struct node{
	int val;
	node *left;
	node *right;

};

node *root=NULL;

void insert_node(int val){
	if (root==NULL){
		root=new node();
		root->val=val;
		root->left=NULL;
		root->right=NULL;

	}
	else{
		node *x=root;
		node *y;

		while(x != NULL){
			if (val < x->val){
				y = x;
				x = x->left;
			}
			else{
				y = x;
				x = x->right;
			}
		}
		node *n_node = new node();
		n_node->val = val;
		n_node->left = NULL;
		n_node->right = NULL;

		if (n_node->val < y->val)
			y->left = n_node;
		else
			y->right = n_node;

	}
}

void print_preorder(node *current)
{
	if(current==NULL) return;
	cout<<current->val<<endl;
	print_preorder(current->left);
	print_preorder(current->right);

}

int main(){

insert_node(3);
insert_node(2);
insert_node(4);
insert_node(7);
insert_node(5);

print_preorder(root);

cout<<endl<<endl;
cout<<root->val<<endl;
cout<<root->left->val<<endl;
cout<<root->right->val<<endl;
cout<<root->val<<endl;
cout<<root->val<<endl;
}

