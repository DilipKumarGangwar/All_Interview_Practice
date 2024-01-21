// Custom UNique ptr class with template specialisation

#include <iostream>
#include<memory>
using namespace std;


class Foo
{
   int a;
   public:
   Foo(int x)
   {
      a= x;
   }
   int get()
   {
      return a;

   }
};

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
        delete []res;
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
               delete []res;
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

template <typename T>
class Unique_ptr<T[]> {
    T *res;

public:
    explicit Unique_ptr<T[]>(T *myRes = nullptr) : res(myRes) {}

    ~Unique_ptr() {
        std::cout << "Array Destructor called" << std::endl;
        delete[] res;
    }

    T &operator[](size_t index) {
        return res[index];
    }

    T *get() {
        return res;
    }

    Unique_ptr<T[]>(Unique_ptr<T[]> &&other) {
        res = other.res;
        other.res = nullptr;
    }

    Unique_ptr<T[]> &operator=(Unique_ptr<T[]> &&other) {
        if (this != &other) {
            if (res)
                delete[] res;
            res = other.res;
            other.res = nullptr;
            std::cout << "Array Move assignment called" << std::endl;
        }
        return *this;
    }

    void reset(T *newRes = nullptr) {
        if (res != nullptr)
            delete[] res;
        res = newRes;
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

   Unique_ptr<Foo> p5 (new Foo(90));   
   cout<<p5->get()<<endl;
   Unique_ptr<int[]> p6 (new int[5]{4,5,6});   
   for(int i=0;i<5;i++)
      cout<<p6[i]<<" "<<endl;
   cout<<"p7.... "<<endl;   
   Unique_ptr<int[]> p7(new int[3]); 
   p7[0] = 5;
   p7[1]= 8;
   p7[2] =9;
   for(int i=0;i<3;i++)
      cout<<p7[i]<<" "<<endl;   
   return 0;
}