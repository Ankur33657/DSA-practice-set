class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>pascal;
        if(numRows==1){
          pascal.push_back({1});
            return pascal;
        }
        else if(numRows==2){
         pascal.push_back({1});
        pascal.push_back({1,1});
            return pascal;
        }
        pascal.push_back({1});
        pascal.push_back({1,1});
        int j=3;
        while(j<=numRows){
         vector<int>vec;
            for(int i=0;i<j;i++){
           if(i==0 || i==j-1)vec.push_back(1);
                else{
                 int tmp=pascal[j-2][i-1]+pascal[j-2][i];
                    vec.push_back(tmp);
                }
            }
            pascal.push_back(vec);
            j++;
        }
        return pascal;
    }
};