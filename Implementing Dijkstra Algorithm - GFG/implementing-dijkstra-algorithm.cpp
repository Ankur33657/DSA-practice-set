//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int>dis(V);
        for(int i=0;i<V;i++){
            dis[i]=INT_MAX;
        }
        dis[S]=0;
        vector<pair<int,int>>adjlist[V];
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                adjlist[i].push_back({adj[i][j][0],adj[i][j][1]});
            }
        }
        set<pair<int,int>>st;
        st.insert({0,S});
        while(!st.empty()){
            auto t=*(st.begin());
            int cost=t.first;
            int node=t.second;
            st.erase(t);
            for(auto it:adjlist[node]){
                int adjnode=it.first;
                int adjcost=it.second;
                if(cost+adjcost<dis[adjnode]){
                    if(dis[adjnode]!=INT_MAX)st.erase({dis[adjnode],adjnode});
                    dis[adjnode]=cost+adjcost;
                    st.insert({dis[adjnode],adjnode});
                }
            }
        }
        return dis;
        
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends