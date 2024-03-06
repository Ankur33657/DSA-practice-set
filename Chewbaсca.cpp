#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    cin>>str;
    for(int i=0;i<str.size();i++){
        int num=str[i]-'0';
        str[i]=min(num,9-num);
    }
    cout<<str<<endl;
    return 0;
}