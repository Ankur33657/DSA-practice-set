#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        string str;
        cin>>str;
        if(str[1]=='+')ans++;
        else
        ans--;
    }
    cout<<ans<<endl;
}