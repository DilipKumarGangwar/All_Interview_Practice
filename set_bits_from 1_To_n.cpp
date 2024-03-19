#include <iostream>

using namespace std;



int main()
{
    int n;
    cin>>n;
    int count = 0;
int d = 2;
int totalSetBit = 0;
n= n+1;
while(n > (1 << count))
{
    totalSetBit += ( (n/d)*(d/2) +  ( (n%d - d/2) > 0 ? (n%d - d/2) : 0 ) );
    cout<<totalSetBit<<" ";
    count++;
    d = d*2;    
}
cout<<"casd="<<totalSetBit;
    return 0;
}
