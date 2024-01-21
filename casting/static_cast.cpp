#include <iostream>

using namespace std;

int main()
{
    printf("Hello World");
//     char c='a';
//     int*p = (int*)&c;
//   *p=5;
//     cout<<*p;
//   char d='b';
//     int*p1 = static_cast<int*>(&d);
//    *p1=4;
//     cout<<*p1;
     int a=10;
    char*p1 = static_cast<char*>(&a);
   *p1='a';
    cout<<*p1;
    return 0;
}
