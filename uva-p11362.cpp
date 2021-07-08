#include <bits/stdc++.h>
using namespace std;


struct node{
	bool endmark;
	node* next[11];

	node(){
		endmark = false;
		for(int i = 0; i <= 9; i++ )
			next[i] = NULL;
	}
};
node* root = new node;

bool insert_PhnBook(int* number, int len){
	bool flag = false;
	node* curr_node = root;
	int matched = 0;
	for(int i = 0; i < len; i++){
		int id = number[i];

		if( curr_node -> next[id] == NULL){
			curr_node -> next[id] = new node;

		}
		else{
			matched++;
			if(matched == (i+1) && curr_node->next[id]->endmark == true){
				flag = true;
				cout<<"here ";
				break;
			}
		}
		curr_node = curr_node->next[id];
	}

	curr_node->endmark = true;
	if(matched == len){
		flag = true;
		cout<<"there ";}
	return flag;
}

int main(){
	int tc, n;
	int ph_no[11];
	cin>>tc;
	while(tc--){
		cin>>n;
		string phn_no[10001];
		int x = 0;
		for( int i = 0; i < n; i++){
			cin>>phn_no[i];
			int len = phn_no[i].length();
			for(int j = 0; j < len; j++)
				ph_no[j] = phn_no[i][j] - '0';

			bool found = insert_PhnBook(ph_no, len);
			if(found){
				x++;
			}
		}
		if (x== 0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		root = new node;
	}
}
