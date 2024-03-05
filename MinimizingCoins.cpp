#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int main(){
    int n,sm;
    cin>>n>>sm;
    vector<int>coins(n);
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }
    vector<int>dp(sm+1,1e9);
    dp[0]=0;
    for(int i=1;i<=sm;i++){
        for(int j=0;j<n;j++){
            if(i>=coins[j]){
                dp[i]=min(dp[i],dp[i-coins[j]]+1)%MOD;
            }
        }
    }
    if(dp[sm]==1e9)cout<<"-1"<<endl;
    else
    cout<<dp[sm]<<endl;
}