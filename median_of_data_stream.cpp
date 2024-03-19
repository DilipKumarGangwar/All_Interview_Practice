// CPP program to find mean and median of
// an array
//using quick sort
#include <bits/stdc++.h>
using namespace std;



// Function for calculating median
void findMedian(int n,  priority_queue<int> &max_heap, priority_queue<int,vector<int>,greater<int>> &min_heap)
{

    int n1= max_heap.size();
    int n2= min_heap.size();
    
    if(n1==0 && n2==0)
      max_heap.push(n);
    else if(n1==n2) 
    {
        if(n>=min_heap.top())
          min_heap.push(n);
        else
          max_heap.push(n);
          
    }
    else 
    {
        if(n1  > n2)
        {
            //abje size wale se check karo
            if(n >= max_heap.top())
                min_heap.push(n);
            else
            {
                //pop
                int tp =max_heap.top();
                max_heap.pop();
                min_heap.push(tp);
                max_heap.push(n);
            }
        }
        else
        {
            if(n <= min_heap.top())
                max_heap.push(n);
            else
            {
                //pop
                int tp =min_heap.top();
                min_heap.pop();
                max_heap.push(tp);
                min_heap.push(n);
            }
            
        }
    }
    
   

}

// Driver code
int main()
{

	int n;
	 priority_queue<int> max_heap;
     priority_queue<int,vector<int>,greater<int>> min_heap;
   int c=0;
	while(1)
	{
	    cin>>n;
	    c++;
	    cout<<"count="<<c<<endl;
	    findMedian(n,max_heap,min_heap);
	    if(c%2==0)
	    {
	        cout<<"even=";
	        cout<<(max_heap.top()+min_heap.top())/2.0;
	    }
	    else
	    {
	        if(max_heap.size()>min_heap.size())
	        {
	            	cout<<"1st part se =";
	          cout<<max_heap.top();
	        }
	        else
	          cout<<min_heap.top();
	    } 
	}

	return 0;
}
