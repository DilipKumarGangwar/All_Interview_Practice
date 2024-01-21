
#include <iostream>

using namespace std;

template <typename T >

class Unique_ptr 
{
   T *res;
   public:
     explicit Unique_ptr<T>(T * myRes=nullptr) : res(myRes)
     {
      
     }
     
     ~Unique_ptr()
    {
        cout<<"dest.."<<endl;
        delete res;
    }

     T& operator*()
     {
        return *res;
     }

     T* operator->()
     {
        return res;
     }

     T* get()
     {
        return res;
     }

      Unique_ptr<T>( Unique_ptr<T>& other ) = delete;
     Unique_ptr<T>& operator=( Unique_ptr<T>& other ) = delete;
    
     //move constr
     Unique_ptr( Unique_ptr<T>&& other )
     {
          res= other.res;
          other.res = nullptr;
     }

     Unique_ptr<T>& operator=( Unique_ptr<T>&& other )
     {
        if(this != &other)
        {   
            if(res)
               delete res;
          res= other.res;
          other.res = nullptr;
          cout<<"came inside.."<<endl;
        }
        return *this;
     }

     void reset(T *res = nullptr)
     {
        if(res != nullptr)
          delete res;
        this->res= res;
     }

    

};


int main()
{
     Unique_ptr<int> p1;
   Unique_ptr<int> p2(new int(10));
   cout<<p2.get()<<" "<<*p2<<endl;
    Unique_ptr<int> p3(new int(108));
   cout<<p3.get()<<" "<<*p3<<endl;
   Unique_ptr<int> p4 = move(p3);
   cout<<p4.get()<<" "<<*p4;

   p3 = move(p2);
    cout<<p3.get()<<" "<<*p3<<endl;
   p3.reset();
   if(p3.get() == nullptr)
      cout<<"null..";
   return 0;
}