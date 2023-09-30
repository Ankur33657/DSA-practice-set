//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    int findMaxDiff(int A[], int n)
    {
     stack<int>st;
     vector<int>ls(n);
     vector<int>rs(n);
     for(int i=0;i<n;i++){
         while(!st.empty() && st.top()>=A[i])st.pop();
         if(st.empty())ls[i]=0;
         else
         ls[i]=st.top();
         
         st.push(A[i]);
     }
     while(!st.empty())st.pop();
     for(int i=n-1;i>=0;i--){
         while(!st.empty() && st.top()>=A[i])st.pop();
         if(st.empty())rs[i]=0;
         else
         rs[i]=st.top();
         
         st.push(A[i]);
     }
     int ans=INT_MIN;
     for(int i=0;i<n;i++){
         ans=max(ans,abs(ls[i]-rs[i]));
     }
     return ans;
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
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends