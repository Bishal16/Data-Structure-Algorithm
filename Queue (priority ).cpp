#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int heap[110] = {0/*extra*/, 2, 7, 19, 25, 26, 17, 1, 90, 3, 36};
int hs = 10;
void heapyfy_max(int hs, int start){
	int l, r, largest;
	l = start * 2;
	r = start * 2 + 1;

	if (l <= hs && heap[l] > heap[start])
		largest = l;
	else
		largest = start;
	if(r <= hs && heap[r] > heap[largest])
		largest = r;

	if(largest != start){
		swap(heap[start], heap[largest]);

		heapyfy_max(hs, largest);
	}
}

void print_heap(int hs){
	int c=1;
	for (int i=1 ; i <= hs; i++){
		if(i==1)cout<<"      ";
		if(i==2)cout<<"   ";
		if(i==4)cout<<" ";

		cout<<heap[i];
		if(i%2==0)
			cout<<"--";
		else
			cout<<"\t";
		if(i == pow(2, c) - 1){
			c++;
			cout<<endl;
		}
	}
	cout<<endl<<"__________________"<<endl;
}

void insert_pq( int val){
	if(val !=0){
		hs++;
		heap[hs] = val;
	}
	int largest, l, r, parent = hs / 2;


	l = parent * 2;
	r = parent * 2 + 1;

	if (l > 1 && heap[l] > heap[parent])
		largest = l;
	else
		largest = parent;
	if ( r>1 && heap[r] > heap[largest])
		largest = r;
	if(largest != parent){
		swap(heap[parent], heap[largest]);
		insert_pq(parent, 0);
	}
}

int main(){
	//int hs = 10;
	int priority_q[hs];

	cout<<"initial tree :"<<endl;
	print_heap(hs);

	//confirming the tree is max_heap
	for( int i = hs/2 ; i >= 1; i-- ){
		heapyfy_max(hs, i);
	}

	cout<<"max heap :"<<endl;
	print_heap(hs);// max heap

	for ( int i = hs; i >= 1; i--){
		priority_q[i-1] = heap[1];
		swap(heap[1], heap[i]);
		//hs--;
		heapyfy_max(i-1, 1);
		print_heap(i-1);
	}

	cout<<"print priority :"<<endl;
	for(int i = 9; i >= 0; i--)
		cout<<priority_q[i]<<endl;


	cout<<"heap size : "<<hs<<endl;
print_heap(hs);
	//insert element
	insert_pq(hs , 89);
	print_heap(hs);
}


//online code
/*


Sharif Hasan - CSE, PUST
Apr 24, 2020 02: 14 PM

#include<bits/stdc++.h>

using namespace std;

void heapify_bottom_to_root(vector <int> &tree,int at){
    int parent=at/2;
    if(parent==0) return;
    if(tree[at]>tree[parent]){
        swap(tree[at],tree[parent]);
        heapify_bottom_to_root(tree,parent);
    }
}

void insert(vector <int> &tree,int number){
    tree.push_back(number);
    heapify_bottom_to_root(tree,tree.size()-1);
}

void heapify_root_to_bottom(vector <int> &tree,int at){
    int left=2*at;
    int right=2*at+1;

    if(left<tree.size()&&tree[left]>=tree[right]&&tree[left]>tree[at]){
        swap(tree[left],tree[at]);
        heapify_root_to_bottom(tree,left);
    }else if(right<tree.size()&&tree[right]>tree[left]&&tree[right]>tree[at]){
        swap(tree[right],tree[at]);
        heapify_root_to_bottom(tree,right);
    }
}
int pop(vector <int> &tree){
    if(tree.size()==1) return -1;
    int max= tree[1];
    tree[1]=tree.back();
    tree.erase(tree.end()-1);
    heapify_root_to_bottom(tree,1);
    return max;
}

int top(vector <int> tree){
    if(tree.size()==1) return -1;
    return tree[1];
}

//Main function
int main()
{
    vector <int> arr={2,7,19,25,26,17,1,90,3,36};
    vector <int> tree(1);

    int i=1;
    //auto p:arr;
    //cout<<p<<"_____";
    for(auto a:arr){
        insert(tree,a);
        ++i;
    }
    int top=0;
    while((top=pop(tree))!=-1){
        cout<<top<<endl;
    }
    return 0;
}
*/
