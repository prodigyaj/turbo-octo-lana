class Solution {
public:
    int memo[1000];
    
    int climbStairs(int n) {
        if(n==0)
            return 1;
        if(n<0)
            return 0;
        int &ret = memo[n];
        if(ret!=0)return ret;
        return ret = climbStairs(n-1) + climbStairs(n-2);
    }
};
