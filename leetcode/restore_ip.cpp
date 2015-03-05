#include <iostream>
#include <string>
#include <vector>


using namespace std;

class Solution {
public:
    void findIP(string s,int index,int octals,string output,int output_index,vector <string> &res)
    {
    	int num = 0,power=1;
    	if(index == s.size())return;
    	if(octals == 3)
    	{
    		// If for the 4th octal, remaining numbers go more than 3, return
    		int digits = s.size()-index-1;
    		//cout<<digits<<endl;
    		if(digits>2 )
    			return;
    		int p = power;
    		//cout<<output<<endl;
    		for(int i=1;i<=digits;i++)
    			p*=10;
    		//cout<<"p: "<<p<<endl;
    		num = 0;
    		for(int i=index;i<s.size();i++,p/=10)
    			num += ((s[i]-48)*p);

    		if(num < 256)
    		{
    				int k = 0;
					string temp;
	        		if(num == 0)
	        			temp.push_back('0');
	        		else
	        		{
	        			while(num!=0)
		        		{
		        			temp.push_back((num%10)+48);	        		
		        			num/=10;	        			
		        		}
	        		}
	        		reverse(temp.begin(),temp.end());
	        		for(k=0;k<temp.size();k++)
	        			output[output_index+k] = (temp[k]);
	        		if(output[output.size()-1]!=' ') //Just to eliminate errors dues to '0's, not ideal as it calculates the possibilities
	        			res.push_back(output);
    		}


    	}
    	else
    	{
	        for(int i=0;i<3 && (i+index)<s.size();i++,power*=10)
	        {
	        	int p = power;
	        	num = 0;
	        		for(int j=0;j<=i;j++,p/=10)
	        			num += ((s[index+j]-48)*p);
	        	//cout<<"Num: "<<num<<" Octals: "<<octals<<endl;
	        	//cout<<"index: "<<index<<" "<<s[index]<<endl;
	        	if(num<256)
	        	{
	        		int k = 0;
	        		string temp;
	        		//input can be zero, the below while loop will discard that
	        		if(num == 0)
	        			temp.push_back('0');
	        		else
	        		{
	        			while(num!=0)
		        		{
		        			temp.push_back((num%10)+48);	        		
		        			num/=10;	        			
		        		}
	        		}
	        		reverse(temp.begin(),temp.end());
	        		for(k=0;k<temp.size();k++)
	        			output[output_index+k] = (temp[k]);
	        		
	        		output[output_index+k] = '.';
	        		//cout<<output<<endl;
	        		findIP(s,index+i+1,octals+1,output,output_index+k+1,res);
	        	}

	        }
	     }
    }
    vector<string> restoreIpAddresses(string s) {

        vector <string> result;
        string output;
        cout<<"Input: "<<s<<endl;
        for(int i=0;i<s.size()+3;i++)    
        	output.push_back(' ');

        findIP(s,0,0,output,0,result);
        
        return result;
    }
};

int main()
{
	Solution s;
	string S;
	cin >> S;
	vector <string> res = s.restoreIpAddresses(S);

	for(int i=0;i<res.size();i++)
		cout<<res[i]<<endl;

	return 0;
}