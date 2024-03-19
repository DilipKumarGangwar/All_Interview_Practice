
//memoization
#include <bits/stdc++.h>
using namespace std;



// Function to find all possible path in matrix from top
// left cell to bottom right cell
int findPaths(	int i, int j,  vector<vector<int>> &dp)
{
    

	// if the bottom right cell, print the path
	if(i==1 || j== 1)
	  return 1;
    if(dp[i][j] != 0)
       return dp[i][j];
    dp[i][j] = findPaths(i-1,j,dp) +  findPaths(i,j-1,dp);
   return dp[i][j];
    
}

// Driver code
int main()
{
    int M=4,N=4;

    vector<vector<int>> dp(M,vector<int>(N+1,0));
	cout<<"Total No of possible paths="<<findPaths( M,N,dp);
    
	return 0;
}





//DP
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// Function to print a 2D array
void print2DArray(const vector<vector<int>> &arr,int row,int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



// Function to find all possible path in matrix from top
// left cell to bottom right cell
void findPaths(	int row,int col,  vector<vector<int>> &dp)
{
    
    for(int i=0;i<row;i++)
       dp[i][0] = 1;
    for(int j=0;j<col;j++)
       dp[0][j] = 1;   
   
    for(int i=1;i<row;i++)
    {
        for(int j=1;j<col;j++)
        {
             dp[i][j] = dp[i-1][j] + dp[i][j-1]; 
        }
    }
    
  
}

// Driver code
int main()
{
    int M=4,N=4;

    vector<vector<int>> dp(M,vector<int>(N,0));
	findPaths(M,N,dp);
    cout<<"Total No of possible paths="<<dp[M-1][N-1];
	return 0;
}

//optimimise dp

//DP
#include <bits/stdc++.h>
using namespace std;

#include <iostream>
#include <vector>
using namespace std;

// Function to print a 2D array
void print2DArray(const vector<vector<int>> &arr,int row,int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}



// Function to find all possible path in matrix from top
// left cell to bottom right cell
void findPaths(	int row,int col,  vector<vector<int>> &dp)
{
    
  
    for(int j=0;j<row;j++)
       dp[0][j] = 1;   
    //print2DArray(dp,row,col);
   for (int i = 1; i < row; i++) {
    cout << i << " ";
    for (int j = 0; j <= col; j++) { 
        if (j == 0)
            dp[1][j] = 1;
        else  
            dp[1][j] = dp[0][j] + dp[1][j - 1]; 
    }
    // print2DArray(dp,row,col);
    //copy back
    for (int j = 0; j <= row; j++)
        dp[0][j] = dp[1][j];
    print2DArray(dp,row,col);
    cout<<"ss";
}

    
  
}

// Driver code
int main()
{
    int M=3,N=3;

    vector<vector<int>> dp(2,vector<int>(N,0));
	findPaths(M,N,dp);
    cout<<"Total No of possible paths="<<dp[1][N-1];
	return 0;
}
