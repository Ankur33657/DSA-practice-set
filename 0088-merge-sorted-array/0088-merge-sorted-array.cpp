class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>ans;
        int i=0;
        int j=0;
       while(i<m && j<nums2.size()){
         if(nums1[i]<nums2[j]){
            ans.push_back(nums1[i]);
             i++;
         }
           else{
 ans.push_back(nums2[j]);
           j++;
           }
          
       }
        if(i>=m){
          while(j<nums2.size()){
            ans.push_back(nums2[j++]);
          }
        }
        else{
            while(i<m){
           ans.push_back(nums1[i++]);
            }
        }
        while(nums1.size()!=0)nums1.pop_back();
        for(auto it:ans){
          
            nums1.push_back(it);
        }
        return;
    }
};