//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
  Node* reverse(Node* head){
      if(!head)return head;
      Node* prev=NULL;
      Node* curr=head;
      Node* nextptr;
      while(curr!=NULL){
          nextptr=curr->next;
          curr->next=prev;
          prev=curr;
          curr=nextptr;
          
      }
      return prev;
  }
  int length(Node* head){
      Node* temp=head;
      int cnt=0;
      while(temp!=NULL){
          cnt++;
          temp=temp->next;
      }
      return cnt;
  }
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head)
    {
        //Your code here
        Node* s=head;
        Node* f=head;
        int len=length(head);
        while(f!=NULL and f->next!=NULL){
            s=s->next;
            f=f->next->next;
        }
        Node* r;
        if(len%2==0){
            r=reverse(s); 
        }else{
            s=s->next;
            r=reverse(s);
        }
        Node* temp=head;
        while(r!=NULL){
            if(temp->data != r->data){
                return false;
            }
            r=r->next;
            temp=temp->next;
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends