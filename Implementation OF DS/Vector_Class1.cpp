#include <iostream>
#include <stdexcept>
using namespace std;
template<typename T>
class Vector {
private:
    T *array;
    size_t  capacity;
    size_t size;

public:
    // // Define iterator type
    // typedef T* iterator;
    // typedef const T* const_iterator;

    Vector() : capacity(1), size(0) {
        array = new T[capacity];
    }

    ~Vector() {
        delete[] array;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            // Double the capacity if the array is full
            capacity *= 2;
            T *temp = new T[capacity];
            for (size_t i = 0; i < size; ++i) {
                temp[i] = array[i];
            }
            delete[] array;
            array = temp;
        }
        array[size++] = value;
    }

    void pop_back() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        --size;
        // Call the destructor of the last element
        array[size].~T();
    }

    T& front() {
        if (size == 0) {
            throw std::out_of_range("Vector is empty");
        }
        return array[0];
    }
    
    T& back()
    {
       if (size == 0) 
            throw std::out_of_range("Vector is empty");
        return array+size;
    }
    
    size_t getSize()
    {
        return size;
    }
    
    size_t getCapacity()
    {
        return capacity;
    }

    // // Begin and end functions for iterators
    // iterator begin() {
    //     return array;
    // }

    T* begin() const {
        return array;
    }

    // iterator end() {
    //     return array + size;
    // }

    T * end() const {
        return array + size;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    // T& operator[](size_t index) {
    //     if (index >= size) {
    //         throw std::out_of_range("Index out of range");
    //     }
    //     return array[index];
    // }
    // 1 2 3 4 5
    void insert(auto it,int val)
    {
        //3 cases
        /*
         
          1. Inserting in case when size == capacity
               a) insert at last of the last elements
               b) insert from 0 to size-1
          2. Inserting otherwise
              a)   insert at last of the last elements
              b)        insert from 0 to size-1
        */
         size_t pos = it - array;
         
         if(size== capacity)
         {
             
             //increase capacity
             capacity = capacity*2;
              int *temp = new int[capacity];
              
            if(pos == size)   //insert at size => last of last elemennt
            {
              
               //copy normally to temp
               for ( size_t i = 0; i < size; ++i) 
                temp[i] = array[i];
               
                array[pos]= val; 
            }
            else //insert from 0 to size-1
            {
                int i;  
                for ( i = size-1; i != pos; --i) {
                    temp[i+1] = array[i];
                }
              
                temp[i+1] = array[i];
                
                  //copy your value
                temp[pos]=val;
                
                //copy front elements
                for(int i=0;i<pos;i++)
                {
                    temp[i] = array[i];
                }   
                delete[] array;
                array = temp;
            }
         }
         else   
         {
             if(pos == size)   //insert at size => last of last elemennt
            {
              
               //copy normally the data
                array[pos]= val; 
            }
            else
            {
                 size_t i;
                for ( i = size-1; i != pos; --i) 
                    array[i+1] = array[i];
                
                //copy
                array[i+1] = array[i];
                array[pos]=val;
            }
         }
         size++;
    }
    
    void clear() 
    {
        // Call the destructor for each element
        for (size_t i = 0; i < size; ++i) {
            array[i].~T();
        }
        size = 0; // Reset size to zero
        capacity=1;
    }
    
    void erase(auto it)
    {
        //no shifting if last element to delete
        //else shifting first 
        size_t pos = it- array;
        if(pos == size -1) //last element
        {
            array[pos].~T();
          
        }
        else
        {
            for (size_t i = pos; i < size; ++i) 
                array[i] = array[i+1];
            //call destructor for last elements
            array[size].~T();
        
        }
          size--;
    }
    
};

int main() {
    Vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(30);
    vec.push_back(4);

    std::cout << "Vector elements: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    cout<<endl;
    
    vec.insert(vec.begin()+2,100);
      std::cout << "Vector elements: ";
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
    cout<<endl;
     vec.insert(vec.begin()+4,200);
     cout<<vec.getCapacity()<<endl;
     for (auto it = vec.begin(); it != vec.end(); ++it) 
        std::cout << *it << " ";
     cout<<endl;
     vec.insert(vec.begin(),300);
     cout<<vec.getCapacity()<<endl;
     for (auto it = vec.begin(); it != vec.end(); ++it) 
        std::cout << *it << " ";
     cout<<endl;
     vec.insert(vec.begin()+2,400);
     cout<<vec.getCapacity()<<endl;
     for (auto it = vec.begin(); it != vec.end(); ++it) 
        std::cout << *it << " ";
     cout<<endl;
     //NOw capacity increases
     vec.insert(vec.begin()+2,500);
     cout<<vec.getCapacity()<<endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) 
        std::cout << *it << " ";
    
    cout<<endl;
    
      vec.insert(vec.begin()+9,20);  //insert at end of last element
      cout<<"At last "<<endl;
       for (auto it = vec.begin(); it != vec.end(); ++it) 
        std::cout << *it << " ";
    
    
    cout<<endl;
     cout<<vec.getCapacity()<<endl;
     
     Vector<char> v2;
     v2.push_back('a');
     v2.push_back('b');
     v2.push_back('c');
     
      cout<<"2nd Vector "<<endl;
      for (auto it = v2.begin(); it != v2.end(); ++it) 
        std::cout << *it << " ";
     cout<<endl;        
     for (char element : v2) 
        std::cout << element << " ";
    
    //vector_name.insert(position, size, val)
    
   // v2.insert(v2.begin()+1,4,'e');
   
  
   
   //ERASE....
   /*
     vector_name.erase(position);    for deletion at specific position
     vector_name.erase(starting_position, ending_position);    // for deletion in range
   */
      
    v2.erase(v2.begin()+1);        
     cout<<"New Size=<<"<<v2.getSize();
     cout<<"\nNew Vector v2: ";
     for (char element : v2) 
        std::cout << element << " ";
    
     //CLEAR()..
   
   v2.clear();
    return 0;
}
