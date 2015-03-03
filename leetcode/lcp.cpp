#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {

        string common="";
        if(strs.size()==0)return common;
        if(strs.size() == 1)return strs[0];
        int col = 0;
        bool flag = false;
        char cur;
        while(col<strs[0].size())
        {
            for(int i=0;i<strs.size();i++)
            {

                if(i == 0 && ((strs[i].size()-1)>=col))
                        cur = strs[i][col];
                else if(i==0)
                {
                    flag = true;
                    break;
                }
                if(i!=0)
                {
                    if( (strs[i].size()-1) < col ||  strs[i][col] != cur)
                    {
                        flag = true;
                        break;
                    }
                }

            
            }
            
            if(flag == true)
                break;
            else
                common.push_back(cur);
            col++;
        }

        return common;

    }
};

int main()
{

	Solution s;
	vector<string> S;
	string a = "c";
	S.push_back("a");
	S.push_back("b");
	cout<<s.longestCommonPrefix(S)<<endl;;

	return 0;

}
