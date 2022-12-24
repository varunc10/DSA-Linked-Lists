//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findPivotElem(int arr[],int i,int j){
       if(j<i){
           return -1;
       }   
       if(j==i){
           return i;
       }
       int m=(i+j)/2;
       if(m<j&&arr[m]>arr[m+1]){
           return m;
       }
       if(m>i&&arr[m]<arr[m-1]){
           return m-1;
       }
       if(arr[i]>=arr[m]){
           return findPivotElem(arr,i,m-1);
       } 
       else{
           return findPivotElem(arr,m+1,j);
       }
    }
    int findMin(int arr[], int n){
        //complete the function here
        return arr[findPivotElem(arr,0,n-1)+1];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends