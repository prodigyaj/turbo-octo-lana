
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int atoi(string str) {
     
     long long pow = 1;
    long long sum = 0;
     int sign = 1;
     int count = 0;
     bool flag = false;
     string s;
     for(int i=str.size()-1;i>=0;i--)
     {
        //cout<<str[i]<<endl;
         if(str[i]<'0' || str[i]>'9')
         {
             if(str[i] == '-' || str[i] == '+' || str[i]==' ')
             {
                 if(str[i]==' ')flag = true;
                 s.push_back(str[i]);
             }
             else
             {
                 s = "";
             }
         }
        else
        {
            if(flag == true){s="";flag=false;};
            s.push_back(str[i]);

        }
     }
     
    reverse(s.begin(),s.end());
    cout<<s<<endl;
     str = "";
     flag = false;
     for(int i=0;i<s.size();i++)
     {
        if(s[i]==' ' && str.size()==0)
            continue;
        else if((s[i]>='0' && s[i]<='9') || s[i]=='-' || s[i]=='+')
            str.push_back(s[i]);
        else 
            flag = true;
            
     }
     if(flag)str = "";
     cout<<str<<endl;
     bool maxedout=false;
     for(int i=str.size()-1;i>=0;i--)
     {
        //if(str[i]==' ')continue;
        if(str[i]>='0' && str[i]<='9')
        {
            if(maxedout == false)
            {
                sum+=((long long)(str[i]-48)*pow);
                pow*=10;
            }
              if(sum >= (long long)((long long)INT_MAX+1))
              {

                 //sum = INT_MAX;
                 maxedout = true;
              }
                //else
                if(sum <= INT_MIN)
                    sum = INT_MIN;
        }
        else
        {
            count++;
            if(sign!=1 && (str[i]=='-' || str[i]=='+'))
                count=2;
            if(str[i]!='-' && str[i]!='+')
                count = 2;
        }
        if(str[i]=='-')
            sign = -1;
        
        if(str[i]=='+' && i == 0)
            sign = 2;
     }
     
     if(sign==-1)
        sum*=sign;
     if(sign == -1 && maxedout)
        sum = INT_MIN;
      else if(sign!=-1 && maxedout)
        sum = INT_MAX;
     if(count>=2)
        sum=0;
    cout << sum << endl;
     //cout << (sum > ((long long)1<<31)) << endl;
   

     return (int)sum;
        
    }
};
int main()
{
Solution s;
int val = s.atoi("-2147483647");
cout<<"Value: "<<val<<endl;
return 0;
}
