#include<iostream>
#include<bits/stdc++.h>

using namespace std;
struct node{
	int val;
	node* left;
	node* right;
};
node* root = NULL;

void insert_bst(node* nd, int val){
	node* n_node =new node();
	n_node->val = val;
	n_node->left = NULL;
	n_node->right = NULL;

	if (nd == NULL){
		root = new node();
		root = n_node;
	}
	else{
		if(val <= nd->val && nd->left != NULL)
			insert_bst(nd->left, val);
		if(val <= nd->val && nd->left == NULL)
			nd->left = n_node;

		if(val > nd->val && nd->right != NULL)
			insert_bst(nd->right, val);
		if(val > nd->val && nd->right == NULL)
			nd->right = n_node;
	}
}

bool search_bst(node* root, int src){
	if (root == NULL)
		return false;
	else if(src == root->val )
		return true;
	else if(src < root->val )
		search_bst(root->left, src);
	else
		search_bst(root->right, src);
}

void preorder_traversal(node * root){
	cout<<root->val<<endl;

	if(root->left != NULL)
		preorder_traversal(root->left);
	if(root->right != NULL)
		preorder_traversal(root->right);
}

void postorder_traversal(node * root){
	if(root->left != NULL)
		preorder_traversal(root->left);
	if(root->right != NULL)
		preorder_traversal(root->right);

	cout<<root->val<<endl;
}

void inorder_traversal(node * root){
	if(root->left != NULL)
		preorder_traversal(root->left);

	cout<<root->val<<endl;

	if(root->right != NULL)
		preorder_traversal(root->right);
}

int max_bst(node* parent){
	int max=-1;
	if(parent == NULL)
		return max;
	while(1){
		if(parent->val > max)
			max = parent->val;
		parent = parent->right;
		if(parent == NULL)
			break;
	}
	return max;
}

int min_bst(node *parent){
	int min = 10000;
	if (parent == NULL)
		return min;
	while(1){
		if (parent->val < min){
			min = parent->val;
			parent = parent->left;
		}
		if( parent == NULL )
			break;
	}
	return min;
}

void delete_bst(node* parent, int del){
	if ( parent == NULL){
		cout<<"Empty tree !!"<<endl;
		return;
	}
	while(1){
		node* tmp;
		tmp = parent;
		if ( del < parent->val)
			parent = parent->left;
		else if( del > parent->val)
			parent = parent->right;

		///node with no child
		if(parent->val == del && parent->left == NULL && parent->right == NULL){
			cout<<parent->val<<"  p v"<<endl;
			tmp->left = NULL;
			parent = NULL;
			break;
		}
		///node with only right child
		else if(parent-> val == del && parent->left == NULL){
			if(tmp->right == parent)
				tmp->right = parent->right;
			else
			tmp->left = parent->right;
			break;
		}
		///node with only right child
		else if(parent-> val == del && parent->right == NULL){
			if(tmp->right == parent)
				tmp->right = parent->left;
			else
				tmp->left = parent->left;
		}
		///node has two child
		else if(parent-> val == del && parent->right != NULL && parent->left != NULL){
			//find right max of parent
			node* nparent = parent->right;
			node* ntmp;
			int mn = 1000;
			while(1){
				//ntmp = nparent;
				if (nparent->val < mn){
					mn = nparent->val;
					ntmp = nparent;
					nparent = nparent->left;
				}
				if (nparent == NULL)
					break;
			}
			cout<<parent->val<<" pt nt "<<ntmp->val<<endl;
			parent->val = ntmp->val;

			ntmp->val = 0;
			ntmp = NULL;
/*
			if(tmp->right == parent)
				tmp->right = parent->left;
			else if(tmp->left == parent)
				tmp->left = ntmp;*/
			break;
		}
	}

	/*if(del < parent->val)
		delete_bst(parent->left, del);
	else if(del > parent->val)
		delete_bst(parent->right, del);*/
}

int main(){

	int arr [100] = {8, 3, 10, 1, 6, 14, 4, 7, 13};
	for(int i = 0; i <9; i++)
		insert_bst(root, arr[i]);

	if( search_bst(root, 140))
		cout<<"Found"<<endl;
	else
		cout<<"Not Found"<<endl;


	cout<<"preorder tracersal :"<<endl;
	preorder_traversal(root);

	cout<<"postorder tracersal :"<<endl;
	postorder_traversal(root);

	cout<<"inorder tracersal :"<<endl;
	inorder_traversal(root);

	//cout<<"--> "<<root->right->right->left->val<<endl;

	int max = max_bst(root);
	cout<<"max value is : "<<max<<endl;

	int min = min_bst(root);
	cout<<"min value is : "<<min<<endl;

	delete_bst(root, 4);
cout<<"4 deleted"<<endl;
	cout<<"inorder tracersal :"<<endl;
	inorder_traversal(root);

	delete_bst(root, 6);
cout<<"6 deleted"<<endl;
	cout<<"inorder tracersal :"<<endl;
	inorder_traversal(root);

	delete_bst(root, 3);
cout<<"3 deleted"<<endl;
	cout<<"inorder tracersal :"<<endl;
	inorder_traversal(root);

}
