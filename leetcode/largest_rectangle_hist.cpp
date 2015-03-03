#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int> &h) {

    	int max_h = 0;
    	stack <int> st;
    	// Note this is a brute force solution (On^2) and will fail in leetcode
    	int i;
    	for(i=0;i<h.size();i++)
    	{
    		

    		if(st.empty()==true)
    			st.push(i);
    		else
    			if (h[st.top()] <= h[i])
    				st.push(i);
			else
			{
				int top = st.top();st.pop();
				int next_index = (st.empty()==true)?i:i-st.top()-1; // -1 for 0 based,
				// if stack is empty after pop means that, the current value can be multiplied with all of them seen in the index so far
				int area = h[top]*next_index;
				max_h = max(area,max_h);
				i--; //dont add the current value yet
			}  
		}

		while(st.empty()!=true)
		{
				int top = st.top();st.pop();
				int next_index = (st.empty()==true)?h.size():h.size()-st.top()-1; // -1 for 0 based,
				// if stack is empty after pop means that, the current value can be multiplied with all of them seen in the index so far
				int area = h[top]*next_index;
				max_h = max(area,max_h);
		}  	
        return max_h;
    }
};

int main()
{
	int vv[] = {2,1,5,6,2,3};
	//int vv[] = {2,1,2};
	vector <int> in (begin(vv),end(vv));
	Solution s;
	int val = s.largestRectangleArea(in);
	cout<<"Value: "<<val<<endl;
	return 0;
}