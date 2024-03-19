//check if n is power of 4
//in bit representaion of n( if n is power of 4) , no of zero =even and no of 1s = 1

#include <iostream>
using namespace std;
int main()
{
  int n;
  cin >>n;
  int zero=0,one=0;
  while(n!=0)
  {
      if( (n & 1)== 0)
        zero++;
      else
         one++;
      n= n>>1;     
  }
  cout<<zero<<" "<<one<<endl;
  if(zero%2==0 && one == 1)
     cout<<"muliple of 4";
 else
    cout<<"Not multiple of 4";

    return 0;
}