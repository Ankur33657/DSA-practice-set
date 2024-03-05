#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// int solve(int i,vector<int>&coins,vector<int>&dp){
//     if(i==0)return 1;
//     if(i<0)return 0;
//     if(dp[i]!=-1)return dp[i];
//     long long int take=0;
//    for(int k=0;k<coins.size();k++){

//        take=(take+solve(i-coins[k],coins,dp))%N;
//    }
   


//     return dp[i]=take;
// }
int main(){
    int n,t;
    cin>>n>>t;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    // sort(coins.begin(),coins.end());
    vector<int>dp(t+1,0);
    // cout<<solve(t,coins,dp);
    dp[0]=1;
    for(int i=1;i<=t;i++){
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                dp[i]=(dp[i]+dp[i-coins[j]])%MOD;
            }
        }
    }
    cout<<dp[t]<<endl;
}