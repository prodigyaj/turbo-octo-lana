class Solution {
public:
    int maxSubArray(int A[], int n) {
        int current_max = A[0];
        int ending_max = A[0];
        for(int i=1;i<n;i++)
        {
            if(ending_max + A[i] < A[i])
                ending_max = A[i];
            else
                ending_max += A[i];
            current_max = max(ending_max,current_max);
        }
        
        return current_max;
    }
};
