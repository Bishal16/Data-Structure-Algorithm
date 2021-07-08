#include<bits/stdc++.h>
using namespace std;
	int heap[8] = {0, 13, 16, 31, 41, 51, 100, 41};

void max_heapify( int hs, int pp){
	int l = pp*2;
	int r = pp*2+1;
	int largest;

	if (l <= hs && heap[l] > heap[pp])
		largest = l;
	else
		largest = pp;

	if(r <= hs && heap[r] > heap[largest])
		largest = r;

	if (largest != pp){
		int tmp = heap[pp];
		heap[pp] = heap[largest];
		heap[largest] = tmp;

		max_heapify(hs, largest);// eta na korle kmne bujhbe je, jei choto ta k matroi swap kore niche deoa holo
								 //tar chaild gula j tar cheye choto noy? ei jnnoi recurseviley call kore confirm korte hobe.
	}
//	print_heap(heap, 7);
}

void print_heap(int heap[], int hs){
	for(int i = 1; i <= hs ; i++)
		//while(hs * hs --)
		cout<< heap[i]<<" ";
	cout<<endl;
}

int main() {
	int hs = 7;
	print_heap(heap, hs);

	for(int i = hs/2 ; i>=1 ; i-- ){
		max_heapify( hs, i);
		//cout<<i<<endl;
	}
	print_heap(heap, hs);
}
