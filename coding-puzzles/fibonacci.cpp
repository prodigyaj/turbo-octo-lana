/*
* author: Ajay Nair
* Fibonacci - using dynamic programming, n<93
*/
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;
long long memo[95];
long long solve(int n)
{
	long long &ret = memo[n];
	if(ret!=-1)return ret;
	if(n<=0 || n==1)return n;
	ret = solve(n-1)+solve(n-2);
	return ret;
}

int main()
{

	int t;
	cin >> t;
	memset(memo,-1,sizeof(memo));
	while(t--)
	{
		int n;
		cin >> n;
		if(n>1)
			cout<<solve(n-1)+solve(n-2)<<endl;
		else
			cout<<n<<endl;
	}
	return 0;
}
