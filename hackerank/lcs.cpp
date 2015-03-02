#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

int a[102],b[102];
int dp[102][102];
int m,n;

//Solves Recursively Top-Down
int solve(int x,int y)
{
	if(x==m || y == n)return 0;
	int &ret = dp[x][y];
	if(ret !=-1) return ret;

	if(a[x] == b[y])
		ret=1 + solve(x+1,y+1);
	else
		ret = max(solve(x+1,y),solve(x,y+1));
	//Returns the max common subsequence value
	return ret;
}

//Solves Iteratively Bottom Up
void Solve()
{
	for(int i=1;i<=m;i++)
		for(int j=1;j<=n;j++)
		{
			if(a[i-1] == b[j-1])
			{
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else
			{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
}

int main()
{


	cin >> m >> n;

	for(int i=0;i<m;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>b[i];

	memset(dp,0,sizeof(dp));
	Solve();

	//Printing the Path, works with Iterative DP, geeksforgeeks inspired
	int i = m, j = n;
	vector <int> val;
	while (i > 0 && j > 0)
	{
		if (a[i-1] == b[j-1])
		{
			val.push_back(a[i-1]);
			i--; j--;   
		}

		else if (dp[i-1][j] > dp[i][j-1])
			i--;
		else
			j--;
	}

	reverse(val.begin(),val.end());
	for(int i=0;i<val.size();i++)
		cout<<val[i]<<" ";

	cout<<endl;
	return 0;
}
