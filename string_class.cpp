
#include <iostream>
#include<cstring>
using namespace std;

class String
{
  
   char *name;
  int size;
  public:
  
  String()
  {
    cout<<"Default:"<<endl;
    name=nullptr;
    size =0;
  }
  String( const char* other)
  {
     cout<<"parameters:"<<endl;
     this->size = strlen(other); 
     this->name = new char[size+1];
     strcpy(this->name,other);
    
      
  }

  //copy constr

  String(const String &other)
  {
     cout<<"copy:"<<endl;
     size = other.size;
     name = new char[other.size+1];
     strcpy(name, other.name); 
     
  }
// // assignment op

//   String& operator=(const String &other)
//   {
// //    cout<<"assignment:"<<endl;
// //    if( this != &other)
// //    {
// //        delete [] name;
// //        size = other.size;
// //        name = new char[other.size+1];
// //        strcpy(name, other.name); 
     
// //    }
// //    else
// //      cout<<"self assign.."<<endl;
// //    return *this;  
    

//     //Better version in case new allocation fails

//     cout<<"assignment:"<<endl;
//    if( this != &other)
//    {
//        char * temp = name;
//        size = other.size;
//        name = new char[other.size+1];
       
//        if(name == NULL)
//        {
//         cout<<"Inside NULL.."<<endl;
//          name = temp;
//          return *this;
//        }
//         cout<<"Memory allocation passed.."<<endl;
//        strcpy(name, other.name); 
//        delete[] temp;
     
//    }
//    else
//      cout<<"self assign.."<<endl;
//    return *this;  
//   }




//CAS................

// assignment op

  void Swap(String &dest, String &src)
  {
         swap(dest.size, src.size);
         swap(dest.name , src.name);
  }
  String& operator=( String other)
  {
//    cout<<"assignment:"<<endl;
        Swap(*this,other);
        cout<<"sad ";
        //Here for argument , destr.. is called as this was craeted with new
        return *this;  
  }
  
  String( String &&other)
  {
     cout<<"Move constr:"<<endl;
     //before moving delete the current resource
    // delete[] name;

     size = other.size;
     name = other.name; //just move
      cout<<"vf.."<<size<<" "<<other.name;
     //invalidate source
     other.size =0;
     other.name = nullptr;

    
     
  }

  void print()
  {
    cout<<"name ="<<name<<endl;
    cout<<"size = "<<size<<endl;

    cout<<endl;   
  }
 
   friend ostream& operator<<(ostream& out,const String& other);
   friend istream& operator>>(istream& in, String& other);
  ~String()
  {
    cout<<"Destr.."<<endl;
    delete []name;
  }
  
};
//global fn
ostream& operator<<(ostream& out,const String& other)
   {
       cout<<"Cout Overloadded.."<<endl;
         out<<other.name;
       cout<<endl;  
        return out; 
   }



int main()
{
    String s1;
    String s2("dilip");
    s2.print();
    String s3= "kumarg";
    s3.print();

    cout<<"Assignment..";
   // s2 = String(s3);
    //s2.print();

   // cout<<s2<<s3;
    //String s3;
    //cin>>s3;

    //cout<<s3;
     s2 = move(s3);
     s2.print(); 
   //  s3.print();
   return 0;
}