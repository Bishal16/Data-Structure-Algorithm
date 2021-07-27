#include<bits/stdc++.h>
using namespace std;



int arr[10] = {10,1,3,20,25,-5,6,-10,11,8};
int st[10][10];

//tutorial implementation
void Compute_ST(int N)
{
    for (int i=0;i<N;i++)
    	st[0][i] = i;
    for (int k = 1;(1 << k)<N; k++)
    {
        for (int i=0;i+(1<<k)<=N;i++)
        {
            int x = st[k-1][i];
            int y = st[k-1][i+(1<<(k-1))];
            st[k][i]=arr[x]<=arr[y]?x:y;
        }
    }
}


void make_sparse_table(){
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 10-(pow(2,i)-1); j++)
		{

			int min = 100000;
			for(int k = j; k <= j+pow(2,i)-1; k++)
			{
				if(arr[k] < min)
					min = arr[k];
			}
			st[i][j] = min;
		}

	}
}

int find_min(int p, int q){
	int k, l = q-p+1, min = 100000;
	for(int i = 0; l>0 ;i++){

		k = log2(l);
		if(st[k][p] < min)
			min = st[k][p];
		l = l - pow(2,k);
		p = p + l + 1;
	}
	return min;
}

void print_sparse_table(){
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 10-(pow(2,i)-1); j++){
			cout<<st[i][j]<< "    ";
		}
		cout<<endl;
	}
}	

int main()
{
	
	make_sparse_table();

	cout<<"sparse table :"<<endl;
	print_sparse_table();

	int p, q;
	cin>>p>>q;
	cout<<"ans : " <<find_min(p,q);

	
}