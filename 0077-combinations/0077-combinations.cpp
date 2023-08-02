class Solution {
public:
    void solve(int i,int k,vector<vector<int>>&vec,vector<int>output,int n){
        if(k==0){
            vec.push_back(output);
            return;
        }
          if(k > (n-i+1))return;
         if(i>n)return;
        solve(i+1,k,vec,output,n);
        output.push_back(i);
        solve(i+1,k-1,vec,output,n);
        output.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>vec;
        vector<int>output;
        solve(1,k,vec,output,n);
        return vec;
        
    }
};