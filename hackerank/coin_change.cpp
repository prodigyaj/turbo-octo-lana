#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
long long dp[300][55];
long long solve(int target,int arr[],int n)
{	
	if(target < 0)return 0;
	if(target == 0)return 1;
	if(n<=0 && target>0)return 0;

	long long  &ret = dp[target][n];
	if(ret!=-1)return ret;

	return ret = solve(target,arr,n-1) + solve(target-arr[n-1],arr,n);
}

int main()
{
	int arr[100];	
	int visit[55];

	memset(dp,-1,sizeof(dp));

	int target;
	cin >> target;

	int n;
	cin >> n;

	for(int i=0;i<n;i++)
		cin >> arr[i];

	dp[target][n] = solve(target,arr,n-1) + solve(target-arr[n-1],arr,n);
	cout<<dp[target][n]<<endl;
	return 0;
}
