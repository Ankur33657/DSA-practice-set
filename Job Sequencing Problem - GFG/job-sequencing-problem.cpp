//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    static bool comp(pair<int,int>v1,pair<int,int>v2){
        return v1.first>v2.first;
    }
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
     vector<pair<int,int>>vec(n);
     for(int i=0;i<n;i++){
         vec[i].first=arr[i].profit;
         vec[i].second=arr[i].dead;
     }
     sort(vec.begin(),vec.end(),comp);
     int profit=0;
     int cnt=0;
     int check[n]={0};
     for(int i=0;i<n;i++){
         for(int j=min(n,vec[i].second-1);j>=0;j--){
             if(check[j]==0){
                 profit+=vec[i].first;
                 cnt++;
                 check[j]=1;
                 break;
             }
         }
     }
     
     return {cnt,profit};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends