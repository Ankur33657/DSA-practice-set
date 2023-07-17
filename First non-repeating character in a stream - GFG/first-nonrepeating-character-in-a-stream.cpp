//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    int freq[26]={0};
		    queue<char>q;
		    string res;
		    for(auto it:A){
		        q.push(it);
		        freq[it-'a']++;
		        while(!q.empty() && freq[q.front()-'a']>1){
		            q.pop();
		        }
		        if(q.empty())res+='#';
		        else
		        res+=q.front();
		    }
		    return res;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends