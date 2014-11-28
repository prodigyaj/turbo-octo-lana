#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int t,n;
    cin >> t;
    while(t--)
        {
        cin >> n;
        int cnt = 0;
        int val = n;
        while(n)
        {
	    cout<<"n: "<<n<<endl;
            int d = n%10;
            n=n/10;
            if(!d)continue;
            val%d==0?cnt++:cnt;
        }
        cout<<cnt<<endl;
    }
    return 0;
}

