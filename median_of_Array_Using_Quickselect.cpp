// CPP program to find mean and median of
// an array
//using quick sort
#include <bits/stdc++.h>
using namespace std;


int partition(int a[],int low ,int high)
{
    int j=-1;
    int i=low;
    int pivot= a[high];
    
    while(i <= high)
    {
        if(a[i] < pivot)
        {
            j++;
            swap(a[i],a[j]);
        }
        
        i++;
    }
    j++;
    swap(a[j],a[high]);
    cout<<j<<endl;
    return j;
}

void  qs(int arr[],int low ,int high,int k,int &a,int &b)
{
   // cout<<"dsd";
    if(low >high)
      return ;
    int index= partition(arr,0,high);
    cout<<"index= "<<index<<endl;
    if(index==k)
    {
        b= arr[index];
        if(a!=-1)
          return ;
    }
    else if(index==k-1)
    {
        a= arr[index];
        if(b!=-1)
          return ;
    }
    
    if(index >=k)
    {
       // <------
        qs(arr,low,index-1,k,a,b);
    }
    else //-------->
       qs(arr,index+1,high,k,a,b);
}


// Function for calculating median
double findMedian(int arr[], int n)
{


	// check for even case
  int a=-1,b=-1,k=n/2;	
  qs(arr,0,n-1,k,a,b);
  cout<<"a="<<a<<" "<<b<<endl;
  if(n%2==0)
  {
      return (a+b)/2;
      
  }
  else
    return b/2;
    
  
}

// Driver code
int main()
{
	int a[] = {1, 3, 4, 2, 7, 5, 8, 6 };
	int N = sizeof(a) / sizeof(a[0]);

	// Function call
	//cout << "Mean = " << findMean(a, N) << endl;
	cout << "Median = " << findMedian(a, N) << endl;
	return 0;
}
