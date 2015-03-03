class Solution {
    int memo[100];
public:
    int numTrees(int n) {
        if(n==0) return 1;
        if(n==1)return 1;
        if(n==2)return 2;
        int &ret = memo[n];
        if (ret!=0)return ret;
        int sum = 0;
        for(int i=1;i<=n;i++)
                sum+= numTrees(i-1)*numTrees(n-i);

        return ret=sum;

    }
};
