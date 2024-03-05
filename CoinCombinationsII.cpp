#include<bits/stdc++.h>
using namespace std;
 #define MOD 1000000007;

 int  solve(int i,int j,vector<int>&coins,vector<vector<int>>&dp){
    if(j==0)return 1;
    if(coins[i]>j)return 0;
    if(i>=coins.size())return 0 ;
    if(dp[i][j]!=-1)return dp[i][j];
    int take=solve(i,j-coins[i],coins,dp);
    int nottake=solve(i+1,j,coins,dp);

    return dp[i][j]=(take+nottake)%MOD;
 }
 int main(){
    int n,x;
    cin>>n>>x;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
      cin>>coins[i];
    }
   //  sort(coins.begin(),coins.end());
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    for(int i=0;i<=x;i++){
      dp[0][i]=(i%coins[0]==0);
    }
    for(int i=1;i<n;i++){
      for(int j=0;j<=x;j++){
         long nottake=dp[i-1][j];
         long take=0;
         if(j>=coins[i])take=dp[i][j-coins[i]];
         dp[i][j]=(take+nottake)%MOD;
      }
    }
    cout<<dp[n-1][x]<<endl;
   //  cout<<solve(0,x,coins,dp)<<endl;
 }