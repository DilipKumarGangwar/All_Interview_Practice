
#include <iostream>

using namespace std;

class A 
{
  
  string name;
  int *p;
  int size;
  public:
  
  A()
  {
    cout<<"Default:"<<endl;
    p=nullptr;
    size =0;
  }
  A(string name,int size)
  {
     cout<<"parameters:"<<endl;
       this->name=name;
       this->size= size;
       p= new int[size];
      fill(p,p+size,10);
      
  }

  //copy constr

  A(const A &other)
  {
     cout<<"copy:"<<endl;
     name = other.name;
     size= other.size;
     //shallow copy
   //  p = other.p; 
     //DEEP COPY
   //  create a new space
     p = new int[other.size];
     for(int i=0;i< size;i++)
         p[i]= other.p[i];
  }
// assignment op

  A& operator=(const A &other)
  {
   cout<<"assignment:"<<endl;
   if( this != &other)
   {
      
     name = other.name;
     size= other.size;
   cout<<"deleting memory.."<<endl;
     delete p;
     p = new int[other.size];
     for(int i=0;i< size;i++)
         p[i]= other.p[i];
   }
   else
     cout<<"self assign.."<<endl;
   return *this;  
    
  }
  void print()
  {
    cout<<"name ="<<name<<endl;
    cout<<"size = "<<size<<endl;
    cout<<"p="<<p<<endl;
    for(int i=0;i<size;i++)
       cout<<p[i]<<" ";
    cout<<endl;   
  }
  ~A()
  {
    cout<<"Destr.."<<endl;
    delete p;
  }
  
};

int main()
{
   A a;
   A b("dilip",4);
   b.print();
   A c("kumar",5);
   c.print();
   A d = b;
   d.print();
   cout<<"Asisgnment op....."<<endl;
   c= b;
   c.print();
   return 0;
}