//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
void addans(vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    vector<int>tmp;
    for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            if(board[j][i]==1){
                tmp.push_back(i+1);
            }
        }
    }
    ans.push_back(tmp);
}
bool issafe(int row,int col,vector<vector<int>>&board,int n){
    int x=row;
    int y=col;
    while(y>=0){
        if(board[x][y]==1)return false;
        y--;
    }
    x=row;
    y=col;
    while(x>=0 && y>=0){
        if(board[x][y]==1)return false;
        x--;
        y--;
    }
     x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1)return false;
        x++;
        y--;
    }
    return true;
}
void solve(int col,vector<vector<int>>&board,vector<vector<int>>&ans,int n){
    if(col==n){
        addans(board,ans,n);
        return;
    }
    for(int row=0;row<n;row++){
        if(issafe(row,col,board,n)){
            board[row][col]=1;
            solve(col+1,board,ans,n);
            board[row][col]=0;
        }
    }
}
    vector<vector<int>> nQueen(int n) {
       vector<vector<int>>ans;
       vector<vector<int>>board(n,vector<int>(n,0));
       solve(0,board,ans,n);
       sort(ans.begin(),ans.end());
       return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends