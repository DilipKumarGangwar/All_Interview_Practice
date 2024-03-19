#include<iostream>
#include<thread>
#include<windows.h>
using namespace std;
int done = false;
void f(int x)
{
    cout<<"cd";
   Sleep(5000);
   done = true;

}

int main()
{
    thread t(f,3);
    cout<<"Wait "<<endl;
    while(!done)
    {

    }
    cout<<"done ";
    t.join();
}
