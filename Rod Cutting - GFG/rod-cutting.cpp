//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int solve(int i,int j,int price[],int n,vector<vector<int>>&dp){
        if(j==0)return 0;
        if(i==n)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int nottake=0+solve(i+1,j,price,n,dp);
        int take=-1e9;
        if(j>=(i+1)){
            take=price[i]+solve(i,j-(i+1),price,n,dp);
        }
        
        return dp[i][j]=max(take,nottake);
        
        
    }
    int cutRod(int price[], int n) {
        
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return solve(0,n,price,n,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends