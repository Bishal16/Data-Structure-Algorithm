#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct node{
	bool endmark;
	node* next[27];
	node(){
		endmark = false;
		for(int i = 0; i < 26; i++)
			next[i] = NULL;
	}
};
node* root;

void insert_trie(char* str, int len){
	node* curr_node = root;

	for(int i = 0; i < len; i++){
		int id = str[i] - 'a';
		if( curr_node->next[id] == NULL){
			curr_node->next[id] = new node;
			curr_node = curr_node->next[id];
		}
		curr_node->endmark = true;
	}
}
bool search_trie(string str, int len){
	node* curr_node = root;
	bool flag = true;

	for(int i = 0; i<len; i++){
		int id = str[i] - 'a';
		if (curr_node->next[id] != NULL)
			curr_node = curr_node->next[id];

		else{
			flag = false;
			break;
		}
	}
	if (curr_node->endmark == false)
		flag = false;
	return flag;
}

void delete_trie(node* cur){
	for (int i = 0; i < 26; i++)
		if(cur->next[i] != NULL)
			delete_trie(cur->next[i]);
	delete (cur);
}
int main(){
	root = new node;
	char str[10] = {'a','b','s'};//abs';
	insert_trie( str, 3);
	//cout<<root->next[3];
	if(search_trie("ab", 3))
		cout<<"found";
	else
		cout<<"not found";


	//delete whole trie
	delete_trie(root);
}
