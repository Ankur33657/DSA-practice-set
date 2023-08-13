//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
long long int dp[100007];
class Solution {
    long long int solve(long long int n){
        if(n==0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(dp[n]!=-1)return dp[n];
        dp[n]=(solve(n-1)+solve(n-2))%1000000007;
        return dp[n];
    }
  public:
    long long int nthFibonacci(long long int n){
       memset(dp,-1,sizeof(dp));
       return solve(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends