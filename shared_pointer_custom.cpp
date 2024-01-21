
#include <iostream>

using namespace std;

template <typename T >

class Shared_ptr
{
   T *res;
   int* counter;
   void incrementCounter()
   {
    if(counter != nullptr)
       (*counter)++;
   }

   void decrementCounter()
   {
     if(counter != nullptr)
     {
       (*counter)--;
       if( (*counter) == 0)
       {
           if(res)
           {
              delete res;
              delete counter;
           }
       }    

     }
   }
   public:
     explicit Shared_ptr(T * myRes=nullptr) : res(myRes),counter(new int(1))
     {
      
     }
     
     ~Shared_ptr()
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
//copy constr
      Shared_ptr( const Shared_ptr<T>& other ) 
      {
           res = other.res;
           counter = other.counter;

          // (*counter)++;
          incrementCounter();
      }

      //copy assignment
     Shared_ptr<T>& operator=( Shared_ptr<T>& other ) 
     {
         if(this != &other)
         {
            decrementCounter(); //for this object
            res = other.res; //move
            counter = other.counter;

            incrementCounter(); //for this object

         }
     }
    
     //move constr
     Shared_ptr( Shared_ptr<T>&& other )
     {
        
          res= other.res;
          counter= other.counter;

          other.res = nullptr;
          other.counter=nullptr;
     }

   //move assignment
     Shared_ptr<T>& operator=( Shared_ptr<T>&& other )
     {
        if(this != &other)
        {   
          decrementCounter();
          res= other.res;
          counter = other.counter;
          other.res = nullptr;
          other.counter = nullptr;
          cout<<"came inside.."<<endl;
        }
        return *this;
     }

     void reset(T *res = nullptr)
     {
        decrementCounter();
        this->res= res;
        //fresh counter start
         counter = new int(1);
     }

     int get_count()
     {
       if(counter)
         return *counter;
       return 0;  
     }
    

};


int main()
{
    // shared_ptr<int> p1;
   Shared_ptr<int> p2(new int(10));
   cout<<p2.get()<<" "<<*p2<<" "<<p2.get_count()<<endl;
    Shared_ptr<int> p3(new int(108));
  cout<<p3.get()<<" "<<*p3<<" "<<p3.get_count()<<endl;
   Shared_ptr<int> p4 = p3;
  // cout<<p3.get()<<" "<<*p3<<" "<<p3.get_count()<<endl;;
    cout<<p4.get()<<" "<<*p4<<" "<<p4.get_count()<<endl;

   p2 = move(p3);
   cout<<p2.get()<<" "<<*p2<<" "<<p2.get_count()<<endl;
   cout<<p4.get()<<" "<<*p4<<" "<<p4.get_count()<<endl;
//    Shared_ptr<int> p4(new int(10));
//    cout<<p4.get()<<" "<<*p4<<endl;
//   // p4=p3;

    //p3.reset();
   return 0;
}