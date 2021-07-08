#include<bits/stdc++.h>
using namespace std;

int max_heap[8] = {0, 100, 15, 41, 41, 16, 31, 13};

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

//void print_heap()


int main(){
	int hs = 7, sorted_array[7];
	for(int i = 0; i<=7; i++){
		swap(max_heap[hs], max_heap[1]);
		sorted_array[hs] = max_heap[hs];
		hs--;
		for ( int x = hs / 2; x >=1; x--)
			heapyfy_max(hs, x);
		}

	for(int i = 1; i<8; i++)
		cout<<sorted_array[i]<<endl;
	}


/*while(true){
			swap(max_heap[hs], max_heap[1]);
			sorted_array[hs] = max_heap[hs];
			hs--;
			if(hs == 0)
				break;
			heapyfy_max(hs, x);
			}*/
