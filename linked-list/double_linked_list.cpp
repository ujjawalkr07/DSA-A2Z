#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node* next;
    Node* back;
public:
    Node(int data1,Node* next1,Node* back1)
    {
        data=data1;
        next=next1;
        back=back1;
    }
public:
    Node(int data1)
    {
        data=data1;
        next=nullptr;
        back=nullptr;
    }
};
Node* head;
// converting array to linked list
Node* convertArr2DLL(vector<int>&arr)
{
    head=new Node(arr[0]);
    Node* prev=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}
// function to print list
void print(Node* head)
{
    while(head != NULL)
    {
        cout<<head->data<<" ";
        head=head->next; 
    }
}
//deleting head
Node* deletehead(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* prev=head;
    head=head->next;

    head->back=nullptr;
    prev->next=nullptr;

    delete prev;
    return head;
}
//deleting tail
Node* deletetail(Node* head)
{
    if(head==NULL || head->next == NULL)
    {
        return NULL;
    }
    Node* temp=head;
    while(temp->next != NULL)
    {
        temp=temp->next;
    }
    Node* newtail=temp->back;
    newtail->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}
//delting kth element at kth position.
Node* removeKthelement(Node* head,int k)
{
    if(head==NULL || k==0)
    {
        return NULL;
    }
    int count=0;
    Node* temp=head;
    while(temp!=NULL)
    {
        count++;
        if(count==k)
            break;
        temp=temp->next;
    }
    Node* prev=temp->back;
    Node* front=temp->next;

    if(prev == NULL && front == NULL)   // single element
    {
        return NULL;
    }
    else if(prev == NULL)    // k is first element
    {
        return deletehead(head);
    }
    else if(front== NULL)   // if k i tail element 
    {
        return deletetail(head);
    }
    // if k is in somehere between
    prev->next=front;
    front->back=prev;

    temp->next=nullptr;
    temp->back=nullptr;
    delete temp;
    return head;
}

// delete node having certain value
void deleteNode(Node* temp){
    // here temp can never be head
    Node* prev=temp->back;
    Node* front=temp->next;
    
    if(front==NULL)     //last element
    {
        prev->next=nullptr;
        temp->back=nullptr;
        free(temp);
        return;
    }
    //for element in between
    prev->next=front;
    front->back=prev;

    temp->next=temp->back=nullptr;
    free(temp);
}

//function to insert node before head
Node* insertbeforehead(Node* head,int val)
{
    Node* newhead= new Node(val,head,nullptr);
    head->back=newhead;
    return newhead;
}

//function to insert node before tail
Node* insertbeforetail(Node* head,int val)
{
    if(head->next == NULL)  // single element
    {
        return insertbeforehead(head,val);
    }
    Node* tail=head;
    while(tail->next!=NULL)     // traversing the array
    {
        tail=tail->next;
    }
    Node* prev=tail->back;  // handling other cases
    Node* newnode=new Node(val,tail,prev);
    prev->next=newnode;
    tail->back=newnode;
    return head;
}

//inserting  element before kth element
Node* insertbeforekth(Node* head,int val,int k)
{
    if(k==1)    // inserting at head
    {
        return insertbeforehead(head,val);
    }
    Node* temp=head;
    int cnt=0;
    while(temp != NULL)     //traversing
    {
        cnt++;
        if(cnt==k)
            break;
        temp=temp->next;
    }
    Node* prev=temp->back;      // handling rest case 
    Node* newnode=new Node(val,temp,prev);
    prev->next=newnode;
    temp->back=newnode;
    return head;
}

//insert before node
void insertbeforenode(Node* node,int val)
{
    Node* prev=node->back; 
    Node* newnode=new Node(val,node,prev);
    prev->next=newnode;
    node->back=newnode;
}
// main function
int main()
{
    vector<int>arr;
    int choice;
    do
    {
        cout<<"\n press \n1.convert arr to DLL\n2.print list\n3.exit.\n4.delete head of list.\n5.delete tail of list.\n6.delete kth element of list.\n7.delete particular element of list.\n8.insert node before head \n9.insert node before head \n10.insert node before kth element\n11.insert before node\nenter your choice:- ";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int n;
                cout<<"enter size for array\n";
                cin>>n;
                cout<<"enter element :-\n";
                for(int i=0;i<n;i++)
                {
                    int x;
                    cin>>x;
                    arr.push_back(x);
                }
                head=convertArr2DLL(arr);
                break;
            case 2:
                print(head);
                break;
            case 3:
                exit(0);
                break;
            case 4:
                head=deletehead(head);
                break;
            case 5:
                head=deletetail(head);
                break;
            case 6:
                int k;
                cout<<"enter position to be deleted\n";
                cin>>k;
                head=removeKthelement(head,k);
                break;
            case 7:
                deleteNode(head->next->next);
                break;
            case 8:
                int val1;
                cout<<"enter value to be inserted\n";
                cin>>val1;
                head= insertbeforehead(head,val1);
                break;
            case 9:
                int val;
                cout<<"enter value to be inserted\n";
                cin>>val;
                head= insertbeforetail(head,val);
                break;
            case 10:
                int val2,pos;
                cout<<"enter value to be inserted\n";
                cin>>val2;
                cout<<"enter position before which element to be inserted\n";
                cin>>pos;
                head= insertbeforekth(head,val2,pos);
                break;
            case 11:
                int val3;
                cout<<"enter value to be inserted\n";
                cin>>val3;
                insertbeforenode(head->next->next,val3);
                break;
            default:
                cout<<"invalid choice\n";
                break;
        }
    } while (choice != 3);
}


