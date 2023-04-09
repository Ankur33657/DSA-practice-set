//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool cyclic(int node,vector<int>adj[],int vis[],int dfsvis[]){
      vis[node]=1;
      dfsvis[node]=1;
      for(auto val:adj[node]){
          if(!vis[val]){
              if(cyclic(val,adj,vis,dfsvis))return true;
          }
          else if(dfsvis[val])return true;
      }
      dfsvis[node]=0;
      return false;
  }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        int vis[V],dfsvis[V];
        for(int i=0;i<V;i++){
            vis[i]=0;
            dfsvis[i]=0;
        }
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(cyclic(i,adj,vis,dfsvis))return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends