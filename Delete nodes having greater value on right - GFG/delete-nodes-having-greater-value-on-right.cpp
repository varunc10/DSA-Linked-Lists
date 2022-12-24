//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
    public:
    Node *compute(Node *head)
    {
        // your code goes here
        Node* dummy=new Node(0);
        dummy->next=head;
        for(Node* curr=head;curr;curr=curr->next){
            Node* post=curr->next;
            bool flag=false;
            while(post){
                if(curr->data<post->data){
                    flag=true;
                    break;
                }
                post=post->next;
            }
            if(flag){
                curr->data=-1;
            }
        }
        Node* curr=dummy;
        Node* newHead=dummy;
        while(curr->next){
            if(curr->next->data==-1){
                Node* temp=curr;
                while(curr->next&&curr->next->data==-1){
                    curr=curr->next;
                }
                temp->next=curr->next;
            }
            else{
                curr=curr->next;
            }
        }
        return newHead->next;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		struct Node *head = NULL;
        struct Node *temp = head;

		for(int i=0;i<K;i++){
		    int data;
		    cin>>data;
			if(head==NULL)
			    head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends