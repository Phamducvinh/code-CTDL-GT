#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int val):data(val),next(NULL),prev(NULL){}
};
 
void addHead(Node*& head,int val){
    Node* New = new Node(val);

    New->next = head;

    if(head!=NULL){
        head->prev = New;
    }

    head = New;
}

void addTails(Node*& head, int val){
    Node* New = new Node(val);
    if(head == NULL){
        head=New;
        return;
    }
    Node* cur = head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=New;
    New->prev=cur;
}