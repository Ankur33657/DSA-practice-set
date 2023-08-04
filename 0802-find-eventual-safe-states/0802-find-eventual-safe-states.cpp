class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>vec;
        int n=graph.size();
        
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
               adj[it].push_back(i);
            }
        }
        queue<int>q;
        vector<int>degree;
        vector<int>adjdeg[n];
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
               adjdeg[i].push_back(it);
            }
        }
        for(int i=0;i<n;i++){
            degree.push_back(adjdeg[i].size());
            if(adjdeg[i].size()==0)q.push(i);
            cout<<i<<"-->"<<adjdeg[i].size()<<endl;
        }
        while(!q.empty()){
            int val=q.front();
            q.pop();
            vec.push_back(val);
            for(auto it:adj[val]){
                degree[it]--;
                if(degree[it]==0)q.push(it);
            }
        }
        sort(vec.begin(),vec.end());
        return vec;

    }
};