// C++ program to demonstrate
// delete operation in binary
// search tree
#include <bits/stdc++.h>
using namespace std;
void printFun(int test)
{
    if (test < 1)
        return;
    else {
        cout << test << " ";
        printFun(test - 1); // statement 2
        cout << test << "- ";
        return;
    }
}
void fib(int a, int b){
    while(a<20){cout<<a<<" ";
	int t = a;
	a = b;
    b = t + b;
}
  //  if(a<20)
    //    fib(a, b);
}

// Driver Code
int main()
{
    int test = 3;
  //  printFun(test);
  fib(0, 1);
}


