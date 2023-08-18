class Solution {
public:
    int  solve(int lb,int ub,vector<int>& nums, int target){
        if(ub<lb)return -1;
        int mid=(lb+ub)/2;
        if(nums[mid]==target)return mid;
        else if(target>nums[mid]){
             lb=mid+1;
        }
        else{
           ub=mid-1;
        }
        return solve(lb,ub,nums,target);
        
    }
    int search(vector<int>& nums, int target) {
        return solve(0,nums.size()-1,nums,target);
        
    }
};