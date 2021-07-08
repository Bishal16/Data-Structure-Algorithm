#include<iostream>
using namespace std;

int arr[100]; /// arr = { 0,0,0,0,0,0,0,0,0,0,0,0.............  }
int tree[100];



/*void update(int idx, int val, int n){
    while(idx <= n){
        tree[idx] = tree[idx] + val;
        idx = idx + (idx & -idx);
    }

}

int query(int idx){
    int sum = 0;
    while(idx >0 ){
        sum = sum + tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}*/

int main(){
    int n;
    cin>>n;
    for(int i = 1; i <= n; i++ ){
        cin>>arr[i];
       // update(i, arr[i], n);
    }
    
    for(int i = 1; i <= n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    for(int i = 1; i <= n; i++ ){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

}