#include<bits/stdc++.h>
using namespace std;


int solve(int i,int j,string &s1,string &s2,vector<vector<int>>&dp){
    if(i>=s1.size())return s2.size()-j;
    if(j>=s2.size())return s1.size()-i;
    if(dp[i][j]!=-1)return dp[i][j];
    int take=1e9;
    int nottake=1e9;
    if(s1[i]==s2[j]){
        nottake=0+solve(i+1,j+1,s1,s2,dp);
    }
    else{
        int op1=1+solve(i,j+1,s1,s2,dp);
        int op2=1+solve(i+1,j,s1,s2,dp);
        int op3=1+solve(i+1,j+1,s1,s2,dp);
        take=min({op1,op2,op3});
    }

    return dp[i][j]=min(take,nottake);
}
int matching(string &s1,string &s2){
    // vector<vector<int>>dp(10010,vector<int>(10010,-1));
    // return solve(0,0,s1,s2,dp);
    int m=s1.size();
    int n=s2.size();
    vector<vector<int>>dp(m+1,vector<int>(n+1,1e9));
    for(int i=0;i<=m;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=j;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1];
            else{
                dp[i][j]=1+min({dp[i][j-1],dp[i-1][j],dp[i-1][j-1]});
            }
        }
    }
    return dp[m][n];

}
int main(){
    string s1;
    cin>>s1;
    string s2;
    cin>>s2;
    int ans=matching(s1,s2);
    cout<<ans<<endl;
}