class Solution {
public:
    bool solve(int i,int j,string s,map<string,int>&mp,vector<vector<int>>&dp){
        if(j>=s.size()){
            string str=s.substr(i,j-i+1);
            if(mp[str])return true;
            return false;
        }
        if(dp[i][j]!=-1)return dp[i][j];
        bool nottake=false;
        bool take=false;
      nottake= solve(i,j+1,s,mp,dp);
        string st=s.substr(i,j-i+1);
        if(mp[st]){
            i=j+1;
            j++;
            take=solve(i,j,s,mp,dp);
        }
        return dp[i][j]=take||nottake;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       map<string,int>mp;
        for(auto it:wordDict){
          mp[it]++;
        }
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(0,0,s,mp,dp);

    }
};