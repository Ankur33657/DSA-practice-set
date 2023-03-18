//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
  public:
    vector<int> getDistinctDifference(int N, vector<int> &A) {
      vector<int>left(N);
      int cnt=0;
      map<int,int>mpL;
      for(int i=0;i<N;i++){
          if(!mpL[A[i]]){
              left[i]=cnt;
              cnt++;
          }
          else{
              left[i]=cnt;
          }
              mpL[A[i]]++;
      }
      vector<int>right(N);
      cnt=0;
      map<int,int>mpR;
      for(int i=A.size()-1;i>=0;i--){
          if(!mpR[A[i]]){
              right[i]=cnt;
              cnt++;
          }
          else{
              right[i]=cnt;
          }
          mpR[A[i]]++;
      }
      vector<int>ans;
      for(int i=0;i<N;i++){
          
          ans.push_back(left[i]-right[i]);
      }
      return ans;
      
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<int> A(N);
        Array::input(A,N);
        
        Solution obj;
        vector<int> res = obj.getDistinctDifference(N, A);
        
        Array::print(res);
        
    }
}

// } Driver Code Ends