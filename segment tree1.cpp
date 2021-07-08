   #include <iostream>
#include<bits/stdc++.h>

using namespace std;
int arr[8] = {1,2,3,4,5,6,7};
int tree[4*8];

void built_segm_tree(int l, int r, int at){

	if (l == r){
		tree[at] = arr[l];
		return;
	}

	int mid = (l + r) / 2;
	int leftNode = at * 2;
	int rightNode = (at * 2) + 1;

	built_segm_tree(l, mid, leftNode );
	built_segm_tree(mid+1, r, rightNode);

	tree[at] = tree[leftNode] + tree[rightNode];
}
void update_segm_tree(int val, int idx, int l, int r, int at)
{
	if(l == r){
		tree[at] = val;
		return;
	}

	int mid = (l+r) / 2;
	int leftNode = at * 2;
	int rightNode = at * 2 + 1;
	if (idx<= mid)
		update_segm_tree(val, idx, l, mid, leftNode);
	else
		update_segm_tree(val, idx, mid+1, r, rightNode);
	tree[at] = tree[leftNode] + tree[rightNode];
}

int query_segm_tree(int rs, int re, int l, int r, int at)
{
	if (rs<=l && re>=r)
		return tree[at];
	if (re<l || r<rs)
		return 0;

	int mid =(l+r) / 2;
	int leftNode = at * 2 ;
	int rightNoede = at * 2 + 1;
	int s1 = query_segm_tree(rs, re, l, mid, leftNode);
	int s2 = query_segm_tree(rs, re, mid+1, r, rightNoede);

	return s1+s2;
}


int main(){
	built_segm_tree(0, 6, 1);
	for(int i=1; i < 4*8; i++)
		cout<<"tree["<<i<<"] = "<<tree[i]<<endl;

	update_segm_tree(2,0,0,6,1);
	for(int i=1; i < 4*8; i++)
		cout<<"tree["<<i<<"] = "<<tree[i]<<endl;
	cout<<query_segm_tree(2,5,0,6,1);
}
