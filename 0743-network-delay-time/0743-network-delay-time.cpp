class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<pair<int,int>>adj[n+1];
        for(int i=0;i<times.size();i++){
           int u=times[i][0];
            int v=times[i][1];
            int cost=times[i][2];
            adj[u].push_back({v,cost});
        }
        vector<int>ans(n+1,INT_MAX);
        ans[k]=0;
        set<pair<int,int>>st;
     
          st.insert({0,k});
        
        while(!st.empty()){
           auto it=*(st.begin());
            int cost=it.first;
            int node=it.second;
            st.erase(it);
            for(auto val:adj[node]){
                int adjnode=val.first;
                int adjcost=val.second;
                if(cost!=INT_MAX && cost+adjcost<ans[adjnode]){
                 if(ans[adjnode]!=INT_MAX)st.erase({ans[adjnode],adjnode});
                    ans[adjnode]=cost+adjcost;
                    st.insert({ans[adjnode],adjnode});
                }
            }
        }
       int res=INT_MIN;
       
       for(int i=1;i<=n;i++){
           if(ans[i]==INT_MAX)return -1;
           // cout<<i<<" "<<ans[i]<<endl;
         res=max(res,ans[i]);
       }
        return res;
    }
};