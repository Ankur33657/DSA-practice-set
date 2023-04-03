class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mp;
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
          mp[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++){
          int tmp=target-nums[i];
            if(mp[tmp]){
                if(mp[tmp]!=i){
                 ans.push_back(i);
                 ans.push_back(mp[tmp]);
                 break; 
                }
             
            }
        }
        return ans;
    }
};