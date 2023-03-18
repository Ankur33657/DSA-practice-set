//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    static bool comp(pair<double,int>p1,pair<double,int>p2){
        float r1=(float)(p1.first/p1.second);
        float r2=(float)(p2.first/p2.second);
        return r1>r2;
    }
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
       vector<pair<double,int>>vec(n);
       for(int i=0;i<n;i++){
           vec[i].first=arr[i].value*1.00;
           vec[i].second=arr[i].weight;
       }
       sort(vec.begin(),vec.end(),comp);
    //   for(int i=0;i<n;i++){
    //       cout<<vec[i].first<<" "<<vec[i].second<<endl;
    //   }
       double max=0;
       for(int i=0;i<n;i++){
           if(vec[i].second<W){
               W-=vec[i].second;
               max+=vec[i].first;
           }
           else {
               double tmp=(double)((vec[i].first/vec[i].second)*W);
               max+=tmp;
               return max;
           }
       }
       return max;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends