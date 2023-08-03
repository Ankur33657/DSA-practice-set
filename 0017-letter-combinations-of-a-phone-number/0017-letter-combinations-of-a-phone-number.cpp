class Solution {
public:
     string mp[10]={" "," ","abc","def","ghi","jkl","mno","pqrs",
                         "tuv","wxyz"};
    void solve(int i,string digits,string output,vector<string>&vec){
         if(i>=digits.size()){
           vec.push_back(output);
             return;
         }
        int j=digits[i]-'0';
        for(int k=0;k<mp[j].size();k++){
         output.push_back(mp[j][k]);
            solve(i+1,digits,output,vec);
            output.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>vec;
        if(digits.size()==0)return vec;
        string output="";
        solve(0,digits,output,vec);
        return vec;
    
    }
};