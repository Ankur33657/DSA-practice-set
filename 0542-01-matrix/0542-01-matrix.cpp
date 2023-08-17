class Solution {
public:
int delx[4]={-1,0,+1,0};
int dely[4]={0,+1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>>vis(m,vector<int>(n,0));
        vector<vector<int>>ans(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                  q.push({{i,j},1});
                }
            }
        }
        while(!q.empty()){
            int i=q.front().first.first;
            int j=q.front().first.second;
            int cost=q.front().second;
            q.pop();
            for(int k=0;k<4;k++){
                int row=i+delx[k];
                int col=j+dely[k];
                if(row>=0 && row<m && col>=0 && col<n && mat[row][col]==1 && !vis[row][col]){
                    vis[row][col]=1;
                    ans[row][col]=cost;
                    q.push({{row,col},cost+1});
                }
            }
        }
       
        return ans;
    }
};