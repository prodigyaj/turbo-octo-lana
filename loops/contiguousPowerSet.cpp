/* Generate all contiguous subsets of a string */

#include<iostream>
using namespace std;

int main()
{
 int subsetCount = 0;
 string input;
 cin>>input;
 
 cout<<endl;
 for(int i=1;i<=input.length();i++)
 {
  for(int j=0;j<=input.length()-i;j++)
  {
   for(int k=0;k<i;k++)
       cout<<input[k+j];
   cout<<endl;
   subsetCount++;
  }
 }

 cout<<"Total contiguous subsets: "<<subsetCount<<endl;
 cout<<"Which follows the identity: n.(n+1)/2 : "<<input.length()<<"."<<input.length()+1<<"/2"<<endl;
}
 
