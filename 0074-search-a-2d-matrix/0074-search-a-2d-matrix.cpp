class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       for(int i=0;i<matrix.size();i++){
          if(matrix[i][0]>target){
          if(i==0)return false;
              for(int j=0;j<matrix[i].size();j++){
                if(matrix[i-1][j]==target)return true;
              }
              return false;
          }
       } 
        int n=matrix.size();
        for(int i=0;i<matrix[0].size();i++){
             if(matrix[n-1][i]==target)return true;
        }
        return false;
    }
};