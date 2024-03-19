#include <iostream>
#include <vector>

using namespace std;

// Function to add an edge to the graph
void addEdge(vector<int> adj[], int u, int v) {
  
    adj[u].push_back(v);
    adj[v].push_back(u); // Assuming the graph is undirected
}

// Function to print the adjacency list representation of the graph
void printGraph(vector<int> adj[], int V) {
  
    for (int v = 0; v < V; ++v) {
        cout << "Adjacency list of vertex " << v << "\nhead ";
        for (auto x : adj[v])
            cout << "-> " << x;
        cout << endl;
    }
}

void countPath(vector<int> adj[],int n, int &count, vector<int> &visited,int src,int dest)
{
   
        visited[src]=true;
        if(src == dest)
        {
            count++;
            visited[src] = false;
            return;
        }
    
        
        for(auto it= adj[src].begin();it != adj[src].end();it++ )
        {
            if(!visited[*it])
            {
                countPath(adj,n,count,visited,*it,dest);
            }
        }
        visited[src]=false;
    
}

int main() {
    // Number of vertices
    int V = 6;
    vector<int> adj[V];
    // // Adding edges to the graph
      addEdge(adj, 0, 1);
    addEdge(adj, 1, 2);
    
    addEdge(adj, 1, 5);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 3, 5);
    addEdge(adj, 4, 5);

    // Printing the adjacency list
  // printGraph(adj, V);
    vector<int> visited(V,false);
    int count=0;
   countPath(adj,V,count,visited,0,5);
   cout<<"Total no of path="<<count;
    return 0;
}
