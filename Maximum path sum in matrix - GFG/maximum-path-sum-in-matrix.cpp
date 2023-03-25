//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
int solve(int i,int j,int n,vector<vector<int>>&Matrix,vector<vector<int>>&dp){
    if(i>=n || j>=n)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int s1=Matrix[i][j]+solve(i+1,j,n,Matrix,dp);
    int s2=Matrix[i][j]+solve(i+1,j-1,n,Matrix,dp);
    int s3=Matrix[i][j]+solve(i+1,j+1,n,Matrix,dp);
    return dp[i][j]=max({s1,s2,s3});
}
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
       vector<vector<int>>dp(N,vector<int>(N,-1));
       int mx=INT_MIN;
       for(int i=0;i<N;i++){
           mx=max(mx,solve(0,i,N,Matrix,dp));
       }
       return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends