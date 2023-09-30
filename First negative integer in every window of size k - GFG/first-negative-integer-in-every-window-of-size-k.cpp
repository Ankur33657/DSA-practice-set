//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[],
                                             long long int N, long long int K) {
    vector<long long>vec;
    queue<long long>q;
    // long long i=0;
    long long j=0;
    while(j<K){
        q.push(A[j++]);
    }
    j--;
    while(j<N){
        while(!q.empty() && q.front()>=0)q.pop();
        if(q.empty())vec.push_back(0);
        else
        vec.push_back(q.front());
        j++;
        if(j<N)
        q.push(A[j]);
        while(q.size()>K)q.pop();
    }
    return vec;
                                                 
 }