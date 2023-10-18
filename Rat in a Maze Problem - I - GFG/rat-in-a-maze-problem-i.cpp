//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    int delx[4]={-1,0,+1,0};
    int dely[4]={0,+1,0,-1};
    void solve(int i,int j,vector<vector<int>>&mat,int n,string out,vector<string>&res,vector<vector<int>>&vis){
        if(i==n-1 && j==n-1){
            res.push_back(out);
            return;
        }
        vis[i][j]=1;
        for(int k=0;k<4;k++){
            int row=i+delx[k];
            int col=j+dely[k];
            if(row>=0 && row<n && col>=0 && col<n && mat[row][col]==1 && !vis[row][col]){
                if(k==0)out+='U';
                else if(k==1)out+='R';
                else if(k==2)out+='D';
                else out+='L';
                solve(row,col,mat,n,out,res,vis);
                out.pop_back();
            }
        }
        vis[i][j]=0;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string>res;
        string output="";
        if(m[0][0]==0 || m[n-1][n-1]==0){
           output+="-1";
           res.push_back(output);
           return res;
        }
        vector<vector<int>>vis(n,vector<int>(n,0));
        solve(0,0,m,n,output,res,vis);
        return res;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends