//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  int memo[101][101];
  int helper(string s,string t,int n,int m){
      if(n==0&&m==0){
          return 0;
      }
      if(n==0){
          return m;
      }
      if(m==0){
          return n;
      }
      if(memo[n][m]!=-1){
          return memo[n][m];
      }
      if(s[n-1]==t[m-1]){
          return helper(s,t,n-1,m-1);
      }
      else{
          return memo[n][m]=1+min(helper(s,t,n-1,m-1),min(helper(s,t,n-1,m),helper(s,t,n,m-1)));
      }
  }
    int editDistance(string s, string t) {
        // Code here
        memset(memo,-1,sizeof(memo));
        return helper(s,t,s.size(),t.size());
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends