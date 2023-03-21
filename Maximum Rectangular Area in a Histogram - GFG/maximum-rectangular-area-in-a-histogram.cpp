//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    long long getMaxArea(long long arr[], int n)
    {
        long long ans=INT_MIN;
       stack<int>st;
       vector<int>nxtsm(n);
       for(int i=n-1;i>=0;i--){
           while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
           if(st.empty())nxtsm[i]=n;
           else nxtsm[i]=st.top();
           st.push(i);
       }
       while(!st.empty())st.pop();
       vector<int>presm(n);
       for(int i=0;i<n;i++){
           while(!st.empty() && arr[i]<=arr[st.top()])st.pop();
           if(st.empty())presm[i]=-1;
           else presm[i]=st.top();
           st.push(i);
       }
       for(int i=0;i<n;i++){
           long long area=((nxtsm[i]-presm[i])-1)*arr[i];
           ans=max(ans,area);
       }
       return ans;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends