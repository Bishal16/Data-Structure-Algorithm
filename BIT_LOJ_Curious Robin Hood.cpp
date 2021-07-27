#include <iostream>
using namespace std;
int sack[100005];
int tree[100005];

void update(int i,int val, int n){
	while(i<=n){
		tree[i] = tree[i] + val;
		i = i + (i & (-i));
	}
}
int query(int i){
	int sum = 0;
	while(i>0){
		sum = sum + tree[i];
		i = i - (i & -i);
	}
	return sum;
}

void print(int n){
	for(int  i=1;i<=n;i++)
			cout<<tree[i]<<" ";
		cout<<endl;
}
void prints(int n){
	for(int  i=1;i<=n;i++)
			cout<<sack[i]<<" ";
		cout<<endl;
}


int main(){
	int n,q,t,cmd,pos,v,i,j,x;
	cin>>t;

	for(x=1;x<=t;x++){
		
		cin>>n>>q;
		//clear BIT array
		for(i=1;i<=n;i++)
			tree[i]=0;

		for(i=1;i<=n;i++){
			cin>>sack[i];
			// creating BIT array
			update(i,sack[i],n);
		}

		//cout<<"    tree : ";print(n);
		//cout<<"    sack : ";prints(n);
		cout<<"Case "<<x<<":"<<endl;

		for(i=0;i<q;i++){
			cin>>cmd>>pos;
			
			if(cmd==1){
				int ans = query(pos+1)-query(pos);
				cout<<ans<<endl;
				update(pos+1,-ans,n);
			}
			else if(cmd==2){
				cin>>v;
				
				update(pos+1,v,n);
			}
			else{
				cin>>j;
				int x = query(j+1);
				int y = query(pos);
				cout<<x-y<<endl;
			}
			//cout<<"    tree : ";print(n);
			//cout<<"    sack : ";prints(n);
		}
	}
}