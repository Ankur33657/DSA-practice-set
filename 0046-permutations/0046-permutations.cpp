
#include<bits/stdc++.h>
class Solution {
public:
    void solve(int i,vector<int>& nums,map<vector<int>,int>&ans){
      if(i>=nums.size()){
          return;
      } 
        for(int j=0;j<nums.size();j++){
            swap(nums[i],nums[j]);
            ans[nums]++;
            solve(i+1,nums,ans);
            swap(nums[i],nums[j]);
        }
       
    }
    vector<vector<int>> permute(vector<int>& nums) {
        map<vector<int>,int>ans;
     
        solve(0,nums,ans);
        vector<vector<int>>vec;
        for(auto it:ans){
           vec.push_back(it.first);
        }
        return vec;
    }
};