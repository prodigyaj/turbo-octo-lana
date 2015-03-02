#include <iostream>

using namespace std;

int dp[1000005];
int arr[1000005];
int n;

int solve(int x)
{
	if(x==n)return 0;

	int &ret = dp[x];
	if(ret!=0)return ret;

	for(int i=x+1;i<n;i++)
	{
		if(arr[i] > arr[x])
			ret = max(ret,1+solve(i));
	}
	return ret;

}

int main()
{
	memset(dp,0,sizeof(dp));
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> arr[i];
	int m = -1;
	for(int i=0;i<n;i++)
	{
		m = max(m,1+solve(i));
	}
	cout << m << endl;
}
