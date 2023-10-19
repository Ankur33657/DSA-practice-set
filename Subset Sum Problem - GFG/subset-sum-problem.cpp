//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
bool solve(int i,int sum,int n,vector<int>&arr,vector<vector<int>>&dp){
    if(sum==0)return true;
    if(i>=n)return false;
    if(dp[i][sum]!=-1)return dp[i][sum];
    bool notake=solve(i+1,sum,n,arr,dp);
    bool take=false;
    if(sum>=arr[i])
    take=solve(i+1,sum-arr[i],n,arr,dp);
    return dp[i][sum]=notake | take;
}
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
       vector<vector<int>>dp(n,vector<int>(sum+1,-1));
       return solve(0,sum,n,arr,dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends