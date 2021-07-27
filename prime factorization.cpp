#include<bits/stdc++.h>
using namespace std;


void prime_fact(int n)
{
	int c=0;
	while(n%2 == 0)
	{
		n = n/2;
		cout<<2<<" ";c++;
	}
	for(int i = 3; i <= sqrt(n); i += 2)
	{
		while(n % i == 0)
		{
			n = n/i;
			cout<<i<<" ";c++;
		}
	}
	if(n > 2)
		cout<<n<<endl;;
	cout<<c;
}

int main()
{
	int n;
	cin>>n;
	prime_fact(n);
}