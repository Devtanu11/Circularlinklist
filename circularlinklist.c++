#include"bits/stdc++.h"
using namespace std;

class node{
    public:
    int data;
    node* next;
    
    node(int val){
        data = val;
        next = NULL;
        
    }
};

void insert_at_head(node*& head, int val){
    node* n = new node(val);
    node*temp = head;
    if(head==NULL){
        head = n;
        n->next = head;
        return;
    }
    
    while(temp->next!=head){
        temp=temp->next;
    }
    temp->next = n;
    n->next = head;
    head=n;

}

void insert_at_tail(node*&head,int val){
    if(head==NULL){
        insert_at_head(head,val);
        return;
    }
    
    node* temp;
    node* n = new node(val);
    temp = head;
    while(temp->next!=head){
        temp = temp->next;
    }
    temp->next = n;
    n->next = head;
    
}

void delete_at_head(node*& head){
    node* temp;
    temp = head;
    while(temp->next!= head){
        temp = temp->next;
    }
    node* todel;
    todel = head;
     temp->next = head->next;
     head = head->next;
     free(todel);
}


void delete_at_any_position(node*&head,int pos){
    if(pos==1){
        delete_at_head(head);
        return;
    } 
    node* temp;
    temp = head;
    int count = 1;
    while(count!= pos-1){
        temp  = temp->next;
        count++;
    }
    node* todel = temp->next;
    temp->next = temp->next->next;
    free(todel);

}


void display(node*head){
    node* temp; 
    temp = head;
    do{
        cout<<temp->data<<"->";
        temp = temp->next;
    }while(temp!=head);
    cout<<"NULL"<<endl;

}


int main(){
    node* head = NULL;
    insert_at_tail(head,1);
    insert_at_tail(head,2);
    insert_at_tail(head,3);
    display(head);
    insert_at_head(head,4);
    display(head);
    delete_at_any_position(head,1);
    display(head);
    delete_at_any_position(head,2);
    display(head);
    
    return 0;
}