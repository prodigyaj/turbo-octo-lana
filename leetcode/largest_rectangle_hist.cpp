#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &h) {

    	int max_h = 0;
    	// Note this is a brute force solution (On^2) and will fail in leetcode
    	for(int i=0;i<h.size();i++)
    	{
    		int cur = h[i];
    		max_h = max(max_h,h[i]);
    		int counter = 1;
    		for(int j=i+1;j<h.size();j++)
    		{
    			counter++;
    			if(h[j]<cur)
    				cur = h[j];
    			max_h = max(max_h,cur*counter); //keep counting the area for every new element we find.
    		}
    	}
        return max_h;
    }
};

int main()
{
	int vv[] = {2,1,5,6,2,3};
	vector <int> in (begin(vv),end(vv));
	Solution s;
	int val = s.largestRectangleArea(in);
	cout<<"Value: "<<val<<endl;
	return 0;
}