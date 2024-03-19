/*
COUNT all possible paths from top left (0,0) to bottom right in matrix
Given a 2D matrix of dimension m✕n, the task is to COUNT all the possible paths 
from the top left corner to the bottom right corner in a 2D matrix with the constraints that 
from each cell you can either move to right or down only.
*/

// //Recusrive  1- exponential
// #include <bits/stdc++.h>
// using namespace std;



// // Function to print the path taken to reach destination
// void printPath(vector<int>& path)
// {
// 	for (int i : path) {
// 		cout << i << ", ";
// 	}
// 	cout << endl;
// }

// bool isValid(vector<vector<int> >& arr,	int i, int j,int row,int col)
// {
//     if(i>=row || j>=col)
//        return false;
//     return true;  
    
// }
// // Function to find all possible path in matrix from top
// // left cell to bottom right cell
// int findPaths(vector<vector<int> >& arr,vector<int> &path,
// 			int i, int j,int row,int col,vector<int> rowNbr,vector<int> colNbr)
// {
//     if(!isValid(arr,i,j,row,col))
//         return 0;
        
  
        
// 	// if the bottom right cell, print the path
// 	if(i==row-1 && j== col-1)
// 	  return 1;
// 	int ans =0;
// 	for(int x=0;x<2;x++)
// 	{
// 	  ans += findPaths(arr,path,i+rowNbr[x],j+colNbr[x],row,col,rowNbr,colNbr); 
// 	}
//    // Backtrack:
//    return ans;
    
// }

// // Driver code
// int main()
// {
// // Input matrix
//     vector<vector<int> > arr
//         = { { 1, 2, 3,6 }, { 4, 5, 6 ,9}, { 7, 8, 9 ,4},{ 7, 8, 9 ,4}  };

// 	// To store the path
// 	vector<int> path;

// 	// Starting cell `(0, 0)` cell
// 	int i = 0, j = 0;

// 	int M = arr.size();
// 	int N = arr[0].size();

//    vector<int> rowNbr = {0,1};
//     vector<int> colNbr = {1,0};
//     int count=0;
// 	// Function call
// 	cout<<"Total No of possible paths="<<findPaths(arr, path, i, j,M,N,rowNbr,colNbr);
    
// 	return 0;
// }




//Recusrive  2- exponential
#include <bits/stdc++.h>
using namespace std;
bool isValid(vector<vector<int> >& arr,	int i, int j,int row,int col)
{
    if(i<0 || j<0)
       return false;
    return true;  
    
}
// Function to find all possible path in matrix from top
// left cell to bottom right cell
int findPaths(vector<vector<int> >& arr,vector<int> &path,
			int i, int j,int row,int col,vector<int> rowNbr,vector<int> colNbr)
{
    if(!isValid(arr,i,j,row,col))
        return 0;

        
	// if the bottom right cell, print the path
	if(i==0 && j== 0)
	  return 1;
	int ans =0;
	for(int x=0;x<2;x++)
	{
	  ans += findPaths(arr,path,i+rowNbr[x],j+colNbr[x],row,col,rowNbr,colNbr); 
	}
   // Backtrack:
   return ans;
    
}

// Driver code
int main()
{
// Input matrix
    vector<vector<int> > arr
        = { { 1, 2, 3,6 }, { 4, 5, 6 ,9}, { 7, 8, 9 ,4},{ 7, 8, 9 ,4}  };

	// To store the path
	vector<int> path;
    int M = arr.size();
	int N = arr[0].size();
    
    // Starting cell `(M-1,N-1, 0)` cell
	int i = M-1, j = N-1;
   vector<int> rowNbr = {-1,0};
    vector<int> colNbr = {0,-1};
   // int count=0;
	// Function call
	cout<<"Total No of possible paths="<<findPaths(arr, path, i, j,M,N,rowNbr,colNbr);
    
	return 0;
}



//Recusrive  3- exponential
//given matrix dimensions, count total paths
#include <bits/stdc++.h>
using namespace std;



vector<int> rowNbr = {-1,0};
    vector<int> colNbr = {0,-1};

bool isValid(int i, int j)
{
    if(i<0 || j<0)
       return false;
    return true;  
    
}
// Function to find all possible path in matrix from top
// left cell to bottom right cell
int findPaths(	int i, int j)
{
    if(!isValid(i,j))
        return 0;
    
	// count
	if(i==1 && j== 1)
	  return 1;
//Now isValid() not needed
//    if(i==1 || j== 1)
// 	  return 1;   
// 	int ans =0;
// 	for(int x=0;x<2;x++)
// 	{
// 	  ans += findPaths(i+rowNbr[x],j+colNbr[x]); 
// 	}
   return findPaths(i-1,j)+ findPaths(i,j-1);
   // Backtrack:
   //return ans;
    
}

// Driver code
int main()
{
    int M=4,N=4;
	cout<<"Total No of possible paths="<<findPaths( M,N);
    
	return 0;
}
