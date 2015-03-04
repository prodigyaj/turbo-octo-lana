#include <iostream>

using namespace std;

int getMedian(int a1[],int l1,int h1,int a2[],int l2,int h2)
{
	int m1 = (l1+h1)/2;
	int m2 = (l2+h2)/2;

	if(a1[m1] == a2[m2])return a1[m1];

	if(l1 == m1 && l2 == m2) // Since m and n equal, total number of elementes is even, so median can be two answers.
		return max(a1[l1],a2[l2]);

	if(a1[m1] > a2[m2])
		return getMedian(a1,l1,m1,a2,m2,h2);
	else
		return getMedian(a1,m1,h1,a2,l2,m2);
}

int main()
{
	int m,n; // m and n have to be equal for this two work
	cin >> m >> n;
	cout<<"Enter elements for Array 1:\n";
	for(int i=0;i<m;i++)
		cin >> arr1[i];
	
	cout<<"Enter elements for Array 2:\n";
	for(int i=0;i<n;i++)
		cin >> arr2[i];
	

	int val = getMedian(arr1,0,m,arr2,0,n);
	cout<<"Median: "<<val<<endl;

	return 0;
}