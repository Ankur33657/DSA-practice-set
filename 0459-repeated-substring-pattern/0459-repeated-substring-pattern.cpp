class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t=s;
        int n=s.size();
        for(int i=0;i<n-1;i++){
         char ch=t[0];
            t.erase(0,1);
            t.push_back(ch);
            if(s==t)return true;
        }
        return false;
        
    }
};