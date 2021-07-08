#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int arr[6] ;
void make_parent(){
	for(int i=1; i<=5; i++)
		arr[i] = i;
}

int find_representative(int x){
	if (arr[x] == x)
		return x;

	arr[x] =  find_representative(arr[x]);// key point
}

void make_friend(int a, int b){
	int u, v;
	u = find_representative(a);
	v = find_representative(b);

	if(u==v)
		cout<<a<<" "<<b<<" already are friend. "<<endl;
	else
		arr[u] = v;
}
int main(){
	make_parent();
	for(int i=1;i<=5;i++)
		cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
	cout<<endl<<endl;

	int a,b;
	while(5){
		cin>>a>>b;
		make_friend(a, b);
		for(int i=1;i<=5;i++)
			cout<<"arr["<<i<<"] = "<<arr[i]<<endl;
		cout<<endl<<endl;
	}


}
