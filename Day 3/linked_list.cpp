#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* push(int value)
{
    Node* node=new Node();
    node->next=NULL;
    node->data=value;
    return node;
}
void print(Node *head)
{
    while(head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
}
void insert_after(Node *node,int after_val,int val)
{
    while(1)
    {
        if(node==NULL)
        {
            cout<<"Value Not Found";
            break;
        }
        if(node->data==after_val)
        {
            if(node->next==NULL)
            {
                node->next=push(val);
                break;
            }
            else
            {
                Node *temp=push(val);
                temp->next=node->next;
                node->next=temp;
                break;
            }
        }
        node=node->next;
    }
}
void search_node(Node* node,int val)
{
    while(1)
    {
        if(node==NULL)
        {
            cout<<"\nValue not present!";
            break;
        }
        if(node->data==val)
        {
            cout<<"\nGiven value is present!";
            break;
        }
        node=node->next;
    }
}
void delete_node(Node* node,int val)
{
    Node *prev=NULL,*start=node;
    cout<<"\nList before deletion:";
    print(start);
    while(1)
    {
        if(node==NULL)
        {
            cout<<"\nCannot be delete as it is not present!";
            break;
        }
        if(node->data==val)
        {
            if(prev!=NULL)
            {
                prev->next=node->next;
                delete node;
                cout<<"\nList after deletion:";
                print(start);
                break;
            }
            else
            {
                prev=node->next;
                delete node;
                cout<<"\nList after deletion:";
                print(prev);
                break;
            }
        }

        prev=node;
        node=node->next;
    }
}
int main()
{
  Node *head;
  head=push(2);
  head->next=push(3);
  head->next->next=push(4);
  head->next->next->next=push(5);
  insert_after(head,4,6);
  insert_after(head,5,7);
  print(head);
  search_node(head,4);
  search_node(head,9);
  delete_node(head,4);
}
