//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    public:
    void dfscheck(int node,vector<int>adj[],vector<int>&v,int &cnt){
        cnt++;
        v[node]=1;
        for(auto it:adj[node]){
            if(!v[it])
            dfscheck(it,adj,v,cnt);
        }
    }
    void dfs(int node,vector<int>adj[],vector<int>&vis,stack<int>&st){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it])
            dfs(it,adj,vis,st);
        }
        st.push(node);
    }
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    vector<int>vis(V,0);
	    stack<int>st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(i,adj,vis,st);
	        }
	    }
	    int tp=st.top();
	    int cnt=0;
	    vector<int>v(V,0);
	    dfscheck(tp,adj,v,cnt);
	    if(cnt==V)return tp;
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends