#include<iostream>
using namespace std;

int main(){
	int arr[10] = {5,2,66,9,14,9,7,3,5,11}; ///given array

	int cum_sum[11] ;
	cum_sum[0] = 0;

	cout<<"input array    : ";
	for(int i = 0; i < 10; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"cumulative sum : ";
	for(int i = 1; i <= 10; i++){
		cum_sum[i] = cum_sum[i-1] + arr[i-1];
		cout<<cum_sum[i]<<" ";
	}

}
