class Solution {
public:
    string convertToTitle(int columnNumber) {
        string str="";
        while(columnNumber>0){
            columnNumber--;
          int num='A'+(columnNumber%26);
            str+=char(num);
            columnNumber=columnNumber/26;
        }
        int i=0;
        int j=str.size()-1;
        while(i<j){
         swap(str[i++],str[j--]);
        }
        return str;
    }
};