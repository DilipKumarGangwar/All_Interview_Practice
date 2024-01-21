//Program to show the concept of SHARED POINTER 

#include <bits/stdc++.h> 
using namespace std; 

class Foo{
  int x;
  public:
  Foo(int x):x(x){}
  int getX(){
      return x;
  }
  ~Foo(){
      cout<<"Destructor";
  }

};
main(){
  Foo *p=new Foo(20);
  cout<<p->getX()<<endl;
  //delete p    if we do not write this the memory pointed by p is not deallocated (giving memory leak)

  shared_ptr<Foo> p1(new Foo(30));
  cout<<p1->getX()<<endl;
  
  shared_ptr<Foo> p2=make_shared<Foo>(40);
  cout<<p2->getX()<<endl;
   
  Foo *p3=p2.get();  //gives address of managed object by p2
  cout<<p3;
  cout<<p1.use_count()<<endl;   

  //P4 now points to object pointed by p1
  shared_ptr<Foo> p4(p1);  //or ...p2=p1  
  //Getting how many pointers are pointing to object pointed by p4
  cout<<p4.use_count()<<endl; //2
  //Getting how many pointers are pointing to object pointed by p1
  cout<<p1.use_count()<<endl; //2

  p4.reset(); //now p4 link is broken to which it is pointing
  cout<<p4.use_count()<<endl; //0
  cout<<p1.use_count()<<endl; //1  
  return 0; 

}