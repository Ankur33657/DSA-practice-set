//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    void solve(int i,string s,vector<string>&vec){
        if(i==s.size()){
            vec.push_back(s);
            return;
        }
        for(int j=i;j<s.size();j++){
            swap(s[i],s[j]);
            solve(i+1,s,vec);
            swap(s[i],s[j]);
        }
        return;
    }
    vector<string> permutation(string S)
    {
        vector<string>vec;
       
        solve(0,S,vec);
        sort(vec.begin(),vec.end());
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		Solution ob;
		vector<string> vec = ob.permutation(S);
		for(string s : vec){
		    cout<<s<<" ";
		}
		cout<<endl;
	
	}
	return 0;
}
// } Driver Code Ends