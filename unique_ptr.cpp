
#include <iostream>
#include<memory>
using namespace std;


int main()
{
   std::unique_ptr<int> p1 = std::make_unique<int>(10);
    std::unique_ptr<int> p2 = std::make_unique<int>(20);
    // Use get() to obtain the raw pointer for printing
    std::cout << p1.get() << " " << *p1 << std::endl;
    std::cout << p2.get() << " " << *p2 << std::endl;
    
    // Copying Not allowed
    //unique_ptr<int> p3 = p1;
    
    //BUT You can MOVE
     unique_ptr<int> p3 = move(p1);
     cout<<p3.get()<<" "<<*p3<<endl;
     
    *p3 = 50;
     cout<<p3.get()<<" "<<*p3<<endl;
    
     std::unique_ptr<int> p4 = std::make_unique<int>(60);
    // Use get() to obtain the raw pointer for printing
    std::cout << p4.get() << " " << *p4 << std::endl;

    p4 = move(p3);
     std::cout << p4.get() << " " << *p4 << std::endl;
    p4.reset() ;//makes it null 
    p4.reset(new int(400));
    if(p4)
        std::cout << p4.get() << " " << *p4 << std::endl;
    else
      cout<<"p4 is null";    
    


//   std::unique_ptr<int[]> p7 = std::make_unique<int[]>(3);
//     std::unique_ptr<int[]> p8 = std::make_unique<int[]>(4);
//    for(int i=0;i<3;i++)
//      cout<<p7[i];
   return 0;
}