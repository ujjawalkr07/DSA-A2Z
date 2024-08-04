#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    public: //constructor
    Node(int data1,Node* next1)
    {
        data=data1;
        next=next1;
    }
    Node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};
Node* head;
// converting array to linked list
Node* convert_arr_ll(vector<int>&arr){
    head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++)
    {
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
// calculating length of linked list
int length(Node* head)
{
    int cnt=0;
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
// check if present
int search(Node* head,int key)
{
    Node* temp=head;
    while(temp)
    {
        if(temp->data == key)
        {
            cout<<"yes it is present"<<endl;
            break;
        }
        temp=temp->next;
    }
    cout<<"it is not present"<<endl;
}
// for printing list
void printlist(Node* head)
{
    Node* temp=head;
    while(temp)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


// deleting first node or head;
Node* delete_first(Node* head)
{
    Node* temp=head;
    head=head->next;
    delete(temp);
    return head;
}
// deleting last element
Node* delete_last(Node* head)
{
    if(head == NULL)    // if list is empty
        return NULL;
    if(head->next == NULL)  // when only one element
    {
        free(head->next);
        return head;
    }
    Node* temp=head;
    while(temp->next->next != NULL)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=nullptr;
    return head;
}
// delete kth element 
Node* delete_kth(Node* head, int k)
{
    if(head == nullptr)
        return head;
    if(k==1)
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    int count=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        count++;
        if(count==k)
        {
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

// delete node which is after a particular element
Node* delete_ele(Node* head, int el)
{
    if(head == nullptr)
        return head;
    if(head->data==el)
    {
        Node* temp=head;
        head=head->next;
        delete(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL)
    {
        if(temp->data==el)
        {
            prev->next=prev->next->next;
            delete(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

// insert head
Node* insertFirst(Node* head,int val)
{
    return new Node(val,head);
}

//insert node at end
Node* insertLast(Node* head,int val)
{
    if(head == NULL)
        return new Node(val);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}

//insert node at kth position
Node* insert_kth(Node* head,int el,int k)
{
    if(head == NULL)
    {
        if(k==1)
            return new Node(el);
        else 
            return NULL; 
    }
    if(k==1)
    {
        return new Node(el,head);;
    }
    int count=0;
    Node* temp=head;
    while(temp != NULL)
    {
        count++;
        if(count == k-1)
        {
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}

// insert node before a particular element
Node* insertBeforeValue(Node* head,int el,int val)
{
    if(head == NULL)
    {
        return NULL; 
    }
    if(head->data == val)
    {
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp->next != NULL)
    {
        if(temp->next->data == val)
        {
            Node* newNode=new Node(el,temp->next);
            temp->next=newNode;
            break;
        }
        temp=temp->next;
    }
    return head;
}
//main function
int main()
{
    int choice;
    vector<int >arr;
    do
    {
        cout<<"menu:-"<<endl;
        cout<<"1. to convert array into linked list."<<endl;
        cout<<"2. to search element in list."<<endl;
        cout<<"3. display list"<<endl;
        cout<<"4. insert at begin of list"<<endl;
        cout<<"5. insert at last of list"<<endl;
        cout<<"6. insert at k th position"<<endl;
        cout<<"7. insert before particular value in list"<<endl;    
        cout<<"8. delete head"<<endl;
        cout<<"9. delelte tail or last node."<<endl;
        cout<<"10. delete element at particular position"<<endl;
        cout<<"11. delete node with particular value"<<endl;
        cout<<"12. to find length of array"<<endl;
        cout<<"13. to exit"<<endl;
        cout<<"enter your choice:-"<<endl;
        cin>>choice;
        
            switch(choice)
            {
                case 1:
                    int n;
                    cout<<"enter limit for array:- "<<endl;
                    cin>>n;
                    cout<<"enter array element"<<endl;
                    for(int i=0;i<n;i++)
                    {
                        int x;
                        cin>>x;
                        arr.push_back(x);
                    }
                    head=convert_arr_ll(arr);
                    break;
                case 2:
                    int val;
                    cout<<"enter value to search:- "<<endl;
                    cin>>val;
                    search(head,val);
                    break;
                case 3:
                    printlist(head);
                    break;
                case 4:
                    int val1;
                    cout<<"enter value to insert at begin:-"<<endl;
                    cin>>val1;
                    head=insertFirst(head,val1);
                    break;
                case 5:
                    int val2;
                    cout<<"enter value to insert at end:-"<<endl;
                    cin>>val2;
                    head=insertLast(head,val2);
                    break;
                case 6:
                    int pos;
                    int val5;
                    cout<<"enter position to insert:- "<<endl;
                    cin>>pos;
                    cout<<"enter value to insert:- "<<endl;
                    cin>>val5;
                    head=insert_kth(head,val5,pos);
                    break;
                case 7:
                    int val3;
                    cout<<"enter value to insert:- "<<endl;
                    cin>>val3;
                    int el;
                    cout<<"enter elemet before which node is to be inserted"<<endl;
                    cin>>el;
                    head=insertBeforeValue(head,val3,el);
                    break;
                case 8:
                    head=delete_first(head);
                    break;
                case 9:
                    head=delete_last(head);
                    break;
                case 10:
                    int pos1;
                    cout<<"enter position to delete:- "<<endl;
                    cin>>pos1;
                    head=delete_kth(head,pos1);
                    break;
                case 11:
                    int el1;
                    cout<<"enter element which is to be deleted"<<endl;
                    cin>>el1;
                    head=delete_ele(head,el1);
                    break;
                case 12:
                    cout<<"length of list is "<<length(head);
                    break;
                case 13:
                    exit(0);
                default:
                    cout<<"invalid choice"<<endl;
                    break;

            }
    }while(choice!=13); 
}
