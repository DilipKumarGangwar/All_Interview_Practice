
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    void f(int V, vector<int> adj[],int src,vector<int> &visited,vector<int> &ans,queue<int> &q) {
        
        q.push(src);
        visited[src] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            ans.push_back(node);
            
            //put all neighbours in stack
            for(auto it = adj[node].begin();it != adj[node].end();it++)
            {
                if(!visited[*it])
                {
                    q.push(*it);
                    visited[*it] = true;
                }
            }
           // cout<<"ss ";
        }
        
    }
   
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> bfSOfGraph(int V, vector<int> adj[]) {
        // Code here
       queue<int> q;
        vector<int> visited(V,false);
        vector<int> ans;
        f(V,adj,0,visited,ans,q);
        return ans;
    }
   
    
    void print(vector<int> adj[],int V)
    {
       for(int i=0;i<V;i++)
       {
           for(int j=0;j<adj[i].size();j++)
              cout<< adj[i][j]<<" ";
            cout<<endl;      
       }
    }
    
    void printfinal(vector<int> &ans,int V)
    {
        for(int i=0;i<V;i++)
           cout<<ans[i]<<" ";
    }
};

 
    void addEdge(vector<int> adj[],int i,int j)
    {
        adj[i].push_back(j);
        adj[j].push_back(i);
    }

int main()
{
     Solution s;
     int V = 6;
     vector<int> adj[V];
     addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);
    s.print(adj,V);

     
     vector<int> ans =s.bfSOfGraph(V,adj);
    cout<<"After BFS Iterative Traversal : "; 
    s.printfinal(ans,V);
    return 0;
}