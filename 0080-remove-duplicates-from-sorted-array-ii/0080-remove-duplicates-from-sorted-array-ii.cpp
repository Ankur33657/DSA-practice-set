class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=0;
        map<int,int>mp;
        for(int i=0;i<nums.size();i++){
          if(mp[nums[i]]>=2)nums[i]=1e9;
            else
                cnt++;
            mp[nums[i]]++;
        }
        sort(nums.begin(),nums.end());
        return cnt;
    }
};