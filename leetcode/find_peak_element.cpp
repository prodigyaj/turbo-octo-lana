class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        
        int peak = 0;
        int index= 0;
        for(int i=0;i<num.size();i++)
        {
            if(i==0)
            {
                peak = num[i];
                index = i;
            }
            else
            {
                if(num[i]>peak)
                {
                    peak = num[i];
                    index = i;
                    if(i == num.size()-1)
                        return index;
                    else
                    {
                        if(num[i+1]<peak)
                            return index;
                    }
                }
            }
        }
        
        return index;
    }
};
