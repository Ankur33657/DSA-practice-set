class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
       map<int,int>mp;
        for(int i=0;i<nums.size();i++){
          if(!mp[nums[i]]){
           mp[nums[i]]++;
          }
            else
                return true;
        }
        return false;
    }
};