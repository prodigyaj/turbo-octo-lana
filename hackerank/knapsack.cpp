#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[2005];
int dp[2005][2005];
int N,k; 
int solve(int n,int sum)
{
    if(n==N)return 0;
    if(sum == k)return 0;
    
    int &ret = dp[n][sum];
    if(ret!=0)return ret;

    if(sum + arr[n] <= k)
        ret = arr[n] + solve(n,sum+arr[n]);
    if(n+1<N)
        ret = max(ret,solve(n+1,sum));
    return ret;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t;
    cin >> t;

    while(t--)
    {
         
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        cin >> N >> k;
        
        for(int i=0;i<N;i++)
            cin >> arr[i];
        
        int val = solve(0,0);
        
        cout << val << endl;

    }
    return 0;
}
