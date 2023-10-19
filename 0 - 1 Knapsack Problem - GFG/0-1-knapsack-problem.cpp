//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int solve(int i,int wt[],int val[],int w,vector<vector<int>>&dp){
        if(i==0){
            if(w>=wt[0])return val[0];
            else
            return 0;
        }
        
        if(dp[i][w]!=-1)return dp[i][w];
        int notpick=0+solve(i-1,wt,val,w,dp);
        int pick=-1e9;
        if(w>=wt[i]){
            pick=val[i]+solve(i-1,wt,val,w-wt[i],dp);
            
        }
        return dp[i][w]=max(pick,notpick);
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return solve(n-1,wt,val,W,dp);
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends