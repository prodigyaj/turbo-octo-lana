#include <iostream>
#include <cmath>

double epsilon = 0.000001;
using namespace std;

int main()
{
	int t;

	cin >> t;
	while(t--)
	{
		int r,k;
		cin >> r >> k;
		int count = 0;

		for(int y=0;y*y<r;y++)
		{
			double X = sqrt(r - y*y);
			int x = (int)X;
			if(abs(x-X) <= epsilon)
				count+=4;
		}
		if(count>k)
			cout<<"impossible"<<endl;
		else
			cout<<"possible"<<endl;
	}
}