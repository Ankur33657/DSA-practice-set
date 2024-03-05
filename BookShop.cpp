#include<bits/stdc++.h>
using namespace std;

int solve(int i,int j,vector<int>&price,vector<int>&pages,vector<vector<int>>&dp){
    if(i==0){
        if(j>=price[i])return pages[i];
        return 0;
    }
    if(dp[i][j]!=-1)return dp[i][j];
    int notbuy=solve(i-1,j,price,pages,dp);
    int buy=0;
    if(j>=price[i]){
        buy=pages[i]+solve(i-1,j-price[i],price,pages,dp);
    }

    return dp[i][j]=max(buy,notbuy);
}
int main(){
    int n,x;
    cin>>n>>x;
    vector<int>price(n);
    vector<int>pages(n);
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>pages[i];
    }
    vector<vector<int>>dp(n+1,vector<int>(x+1,-1));
    // cout<<solve(n-1,x,price,pages,dp)<<endl;
    for(int i=0;i<=x;i++){
        if(i>=price[0]){
          dp[0][i]=pages[0];
        }
        else
        dp[0][i]=0;
    }

    for(int i=1;i<n;i++){
        for(int j=0;j<=x;j++){
            int nottake=dp[i-1][j];
            int take=0;
            if(j>=price[i])take=pages[i]+dp[i-1][j-price[i]];
            dp[i][j]=max(take,nottake);
        }
    }
    cout<<dp[n-1][x]<<endl;

}