//https://www.codingninjas.com/studio/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;



// void frogJumpUtil(int n, vector<int> &heights,int i,int temp,int &InitialMinEnergy)
// {
//    if(i>=n)
//       return ;
//    if(i== n-1)
//    {
//      // temp += abs(heights[i]- heights[i-1]);
//       InitialMinEnergy = min(InitialMinEnergy,temp);
//       return ;
//    }
   
//    frogJumpUtil(n,heights,i+1,temp+abs(heights[i]-heights[i+1]),InitialMinEnergy);
//    if(i+2 < n)
//    frogJumpUtil(n,heights,i+2,temp+abs(heights[i]-heights[i+2]),InitialMinEnergy);

// }

// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     if(n==1)
//       return 0;
//     int InitialMinEnergy = INT_MAX;
//     frogJumpUtil(n,heights,0,0,InitialMinEnergy);
//     return InitialMinEnergy;
// }


//dp

void frogJumpUtil(int n, vector<int>& heights, vector<int>& dp) {
    dp[1] = abs(heights[1] - heights[0]);
    for (int i = 2; i < n; i++) {
        dp[i] = min(abs(heights[i] - heights[i - 1]) + dp[i - 1], abs(heights[i] - heights[i - 2]) + dp[i - 2]);
    }
}

int frogJump(int n, vector<int>& heights) {
    if (n == 1)
        return 0;
    vector<int> dp(n, 0);
    frogJumpUtil(n, heights, dp);
    return dp[n - 1];
}

int main() {
    // Example usage
    vector<int> heights = {10, 30, 40, 20};
    int n = heights.size();
    
    cout << "Minimum energy required: " << frogJump(n, heights) << endl;
    
    return 0;
}


//Much better code

// #include <bits/stdc++.h> 

// int fun(int i,int n,vector<int> &heights )
// {
//     if(i == n-1)
//       return 0;
//     int x = INT_MAX;
//     int y= INT_MAX;
//     x = fun(i+1,n,heights) + abs(heights[i] - heights[i+1]);
//     if(i+2 <n)
//       y = fun(i+2,n,heights) + abs(heights[i] - heights[i+2]);

//     return min(x,y);

// }

// int frogJump(int n, vector<int> &heights)
// {
//     // Write your code here.
//     return fun(0,n,heights);
// }


//Tabulation

#include <bits/stdc++.h> 

int fun(int i,int n,vector<int> &heights,vector<int> energy )
{  
   int x=INT_MAX;
   int y= INT_MAX;
   for(int i=n-2;i>=0;i--)
   {
      x = energy[i+1] + abs(heights[i] - heights[i+1]);
     if(i+2<n)
      y = energy[i+2] + abs(heights[i] - heights[i+2]);
      energy[i] = min(x,y);
   }
   return energy[0];
    

}

int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> energy(n,0);
    return fun(0,n,heights,energy);
}