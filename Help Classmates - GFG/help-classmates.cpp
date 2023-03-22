//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        vector<int>vec(n);
        stack<int>st;
        stack<int>helper;
        for(int i=n-1;i>=0;i--){
     
            while(!st.empty() && st.top()>=arr[i]){
                int tp=st.top();
                helper.push(tp);
                st.pop();
            }
            if(st.empty())vec[i]=-1;
            else vec[i]=st.top();
            // while(!helper.empty()){
            //     st.push(helper.top());
            //     helper.pop();
            // }
            st.push(arr[i]);
        }
        return vec;
    } 
};

//{ Driver Code Starts.

int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int> array(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>array[i];
		}
		Solution obj;
		vector<int> result = obj.help_classmate(array,n);
		for (int i = 0; i < n; ++i)
		{
			cout<<result[i]<<" ";
		}
		cout<<"\n";
	}
	return 0; 
}


// } Driver Code Ends