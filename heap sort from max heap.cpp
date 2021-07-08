#include<bits/stdc++.h>
using namespace std;

int max_heap[8] = {0, 13, 9, 8, 6, 5, 2, 1};

void heapyfy_max(int hs, int start){
	int l, r, largest;
	l = start*2;
	r = start*2+1;

	if (l <= hs && max_heap[l] > max_heap[start])
		largest = l;
	else
		largest = start;
	if(r <= hs && max_heap[r] > max_heap[largest])
		largest = r;

	if( largest != start ){
		swap(max_heap[start], max_heap[largest]);
		heapyfy_max(hs, largest);
	}
}

void print_heap(int hs){
	int c=1;
	for (int i=1 ; i <= hs; i++){

if(i==1)cout<<"      ";
if(i==2)cout<<"   ";
//if(i==1)cout<<"\t\t";

		cout<<max_heap[i];
		if(i%2==0)
			cout<<"--";
		else
			cout<<"\t";
		if(i == pow(2, c) - 1){
			c++;
			cout<<endl;}
		}
	}
	cout<<endl<<endl;
}


int main(){
	int hs = 7, sorted_array[7];
cout<<"its initial tree :"<<endl;
	print_heap(hs);// first raw tree
	for(int i = 0; i<=7; i++){
		swap(max_heap[hs], max_heap[1]);
		sorted_array[hs] = max_heap[hs];
		hs--;
		heapyfy_max(hs, 1);
		//printing new heap
		print_heap(hs);

		}
	cout<<"the sorted array :"<<endl;
	for(int i = 1; i<8; i++)
		cout<<sorted_array[i]<<endl;
}


