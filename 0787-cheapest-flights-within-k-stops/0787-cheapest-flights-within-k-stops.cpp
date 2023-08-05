class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n+1];
        for(int i=0;i<flights.size();i++){
            int u=flights[i][0];
            int v=flights[i][1];
            int cost=flights[i][2];
            adj[u].push_back({v,cost});
        }
        vector<int>ans(n+1,INT_MAX);
        ans[src]=0;
       
        set<pair<int,pair<int,int>>>st;
        st.insert({0,{src,0}});
        while(!st.empty()){
            auto it=*(st.begin());
            int times=it.first;
            int node=it.second.first;
            int cost=it.second.second;
            st.erase(it);
            if(times<=k){
            for(auto val:adj[node]){
               int adjnode=val.first;
               int adjcost=val.second;
               if(times<=k && cost+adjcost<ans[adjnode] ){
                // if(ans[adjnode]!=INT_MAX)st.erase({ans[adjnode],{adjnode,times}});
                ans[adjnode]=cost+adjcost;
                st.insert({times+1,{adjnode,ans[adjnode]}});
               }
            }
            }
         

        }
        // for(auto it:ans)cout<<it<<endl;
           if(ans[dst]==INT_MAX)return -1;
           return ans[dst];
    }
};