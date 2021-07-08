
#include<bits/stdc++.h>
using namespace std;

struct node{
    int val;
    node *left;
    node *right;
};

node *create_node( int val){
    node *n_node = new node();
    n_node->val = val;
    n_node->left = NULL;
    n_node->right = NULL;

    return n_node;
}

void add_left(node *parent, node *child){
    parent->left = child;
}

void add_right(node *parent, node *child){
    parent->right = child;
}

node* create_tree(){
   // node *root = new node();
    node *two = create_node(2);
    node *seven = create_node(7);
    node *nine = create_node(9);
    add_left(two, seven);
    add_right(two, nine);


    node *one = create_node(1);
    node *six = create_node(6);
    add_left(seven, one);
    add_right(seven, six);

    node *twenty = create_node(20);
    add_left(one, twenty);

    node *five = create_node(5);
    node *ten = create_node(10);
    add_left(six, five);
    add_right(six, ten);


    node *eight = create_node(8);
    add_right(nine, eight);

    node *three = create_node(3);
    node *four = create_node(4);
    add_left(eight, three);
    add_right(eight, four);

    return two;
}

void preorder_traverse(node *root){
    cout<<"--> "<<root->val<<endl;
    if(root->left != NULL)
        preorder_traverse(root->left);
    //else
      //  cout<<root->val<<" Left empty"<<endl;


    if(root->right != NULL)
        preorder_traverse(root->right);
    //else
      //  cout<<root->val<<" right empty"<<endl;
}

void postorder_traverse(node* root){
    if (root->left != NULL)
        postorder_traverse(root->left);
    //else
      //  cout<<root->val<<" Left empty"<<endl;

    if (root->right != NULL)
        postorder_traverse(root->right);
   // else
     //   cout<<root->val<<" right empty"<<endl;
    cout<<"-->"<<root->val<<endl;
}

void inorder_traverse(node* root){
    if(root->left != NULL)
        inorder_traverse(root->left);

    cout<<"-->"<<root->val<<endl;

    if(root->right != NULL)
        inorder_traverse(root->right);
}

int main(){
    node *root = create_tree();

    cout<<"Pre order traverse : "<<endl;
    preorder_traverse(root);

    cout<<"Pre order traverse : "<<endl;
    postorder_traverse(root);

    cout<<"In order traverse : "<<endl;
    inorder_traverse(root);
}





