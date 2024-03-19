/*
Print all possible paths from top left (0,0) to bottom right in matrix
Given a 2D matrix of dimension m✕n, the task is to print all the possible paths 
from the top left corner to the bottom right corner in a 2D matrix with the constraints that 
from each cell you can either move to right or down only.
*/
#include <bits/stdc++.h>
using namespace std;



// Function to print the path taken to reach destination
void printPath(vector<int>& path)
{
	for (int i : path) {
		cout << i << ", ";
	}
	cout << endl;
}

bool isValid(vector<vector<int> >& arr,	int i, int j,int row,int col)
{
    if(i>=row || j>=col)
       return false;
    return true;  
    
}
// Function to find all possible path in matrix from top
// left cell to bottom right cell
void findPaths(vector<vector<int> >& arr, vector<int>& path,
			int i, int j,int row,int col,vector<int> rowNbr,vector<int> colNbr,int &c)
{
    if(!isValid(arr,i,j,row,col))
        return;
        
   //if isValid, add cell
   path.push_back(arr[i][j]);
  // cout<<"arr="<<arr[i][j]<<endl;
        
	// if the bottom right cell, print the path
	if(i==row-1 && j== col-1)
	{
        c++;
	    printPath(path);
	    path.pop_back();
	    return;
	}
	
	for(int x=0;x<2;x++)
	{
	   findPaths(arr,path,i+rowNbr[x],j+colNbr[x],row,col,rowNbr,colNbr,c); 
	}
   // Backtrack: Remove the current cell from the current path
	path.pop_back();
    
}

// Driver code
int main()
{
// Input matrix
    vector<vector<int> > arr
        = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };

	// To store the path
	vector<int> path;

	// Starting cell `(0, 0)` cell
	int i = 0, j = 0;

	int M = arr.size();
	int N = arr[0].size();

   vector<int> rowNbr = {0,1};
    vector<int> colNbr = {1,0};
    int count=0;
	// Function call
	findPaths(arr, path, i, j,M,N,rowNbr,colNbr,count);
    cout<<"Total No of possible paths="<<count;
	return 0;
}
