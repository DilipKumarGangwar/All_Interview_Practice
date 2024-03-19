
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
   
    void f(int V, vector<int> adj[],int src,vector<int> &visited,vector<int> &ans) {
        
        visited[src] = true;
        ans.push_back(src);
        for(auto it= adj[src].begin();it != adj[src].end();it++)
        {
            if(!visited[*it])
            {
                f(V,adj,*it,visited,ans);
            }
        }
        
    }
   
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        vector<int> visited(V,false);
        vector<int> ans;
        f(V,adj,0,visited,ans);
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
     
     vector<int> ans =s.dfsOfGraph(V,adj);
    cout<<"After DFS Recusrive Traversal : "; 
    s.printfinal(ans,V);
    return 0;
}