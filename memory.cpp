#include <iostream>
#include<memory>
using namespace std;


void fun()
{
    for(int i=0;i<100000;i++)
    {
        cout<<"Hi\n";
        int *p= new int(10);
    }
    

}

int main()
{
    fun();
    return 0;
}