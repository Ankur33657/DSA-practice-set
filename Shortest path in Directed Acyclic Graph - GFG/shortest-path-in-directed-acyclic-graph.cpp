//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<int>vec(N,INT_MAX);
        // int vis[N];
        //create adj list
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        // vis[0]=1;
        while(!q.empty()){
            pair<int,int>p1=q.front();
            q.pop();
            vec[p1.first]=min(vec[p1.first],p1.second);
            for(auto val:adj[p1.first]){
                // if(!vis[val.first]){
                    q.push({val.first,p1.second+val.second});
                    // vis[val.first]=1;
                // }
            }
        }
        for(int i=0;i<N;i++){
            if(vec[i]==INT_MAX)vec[i]=-1;
        }
        return vec;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends