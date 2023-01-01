//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int mx=0;
    void maxVal(Node* root){
        if(!root){
            return;
        }
        mx=max(mx,root->data);
        maxVal(root->left);
        maxVal(root->right);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        maxVal(root);
        if(!root){
            return 0;
        }
        int ans=0;
        vector<vector<int>> v(mx+1);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();
            q.pop();
            if(curr->left){
                q.push(curr->left);
                v[curr->data].push_back(curr->left->data);
                v[curr->left->data].push_back(curr->data);
            }
            if(curr->right){
                q.push(curr->right);
                v[curr->data].push_back(curr->right->data);
                v[curr->right->data].push_back(curr->data);
            }
        }
        queue<pair<int,int>> q1;
        vector<bool> vis(mx+1,false);
        vis[target]=true;
        q1.push({target,0});
        while(!q1.empty()){
            int i=q1.front().first;
            int j=q1.front().second;
            q1.pop();
            ans=max(ans,j);
            for(auto k:v[i]){
                if(!vis[k]){
                    q1.push({k,j+1});
                    vis[k]=true;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends