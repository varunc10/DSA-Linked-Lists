//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int mod=1e9+7;
    int memo[1001][801];
    int helper(int n,int r){
        if(n==0){
            return 0;
        }
        if(r==0||n==r){
            return 1;
        }
        if(memo[n][r]!=-1){
            return memo[n][r];
        }
        return memo[n][r]=((helper(n-1,r)%mod)+(helper(n-1,r-1))%mod)%mod;
    }
    int nCr(int n, int r){
        // code here
        memset(memo,-1,sizeof(memo));
        return helper(n,r);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends