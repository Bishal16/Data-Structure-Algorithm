#include<iostream>
using namespace std;

int arr[100]; /// arr = { 0,0,0,0,0,0,0,0,0,0,0,0.............  }
int tree[100];



void update(int idx, int val, int n){//tree build + update works for both
    while(idx <= n){
        tree[idx] = tree[idx] + val;
        idx = idx + (idx & -idx);
    }

}

void range_update(int idx_s, int idx_e, int val, int n){
    while(idx_s <= idx_e){
        int idx = idx_s;
        while(idx <= n){
            tree[idx]  = tree[idx] + val;
            idx = idx + (idx & -idx);
        }
        idx_s++;   
    }
}

int query(int idx){ 
    int sum = 0;
    while(idx >0 ){
        sum = sum + tree[idx];
        idx = idx - (idx & -idx);
    }
    return sum;
}


int reange_query(int idx_s, int idx_e){

    return query(idx_e) - query(idx_s - 1);
}



int main(){
    int n;
    cout<<"input size :";
    cin>>n;
    for(int i = 1; i <= n; i++ ){
        cin>>arr[i];
        update(i, arr[i], n);// constructing array tree


        cout<<"BIT tree :   ";
    for(int i = 1; i <= n; i++ ){
        cout<<tree[i]<<" ";
    }
    cout<<endl;
    }
    
    cout<<"Input array : ";
    for(int i = 1; i <= n; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    

    cout<<query(3)<<endl;
    cout<<reange_query(3,5)<<endl;

    int val,pos1,pos2;
    cout<<"input v p1, p2 :";
    cin>>val>>pos1>>pos2;

    update(pos1,val,5);
    cout<<"BIT tree :   ";
    for(int i = 1; i <= n; i++ ){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

    range_update(pos1,pos2,val,5);
    cout<<"BIT tree :   ";
    for(int i = 1; i <= n; i++ ){
        cout<<tree[i]<<" ";
    }
    cout<<endl;

}