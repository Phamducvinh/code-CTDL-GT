#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* prev;
    int data;
    Node* next;

    Node(int val):prev(NULL),data(val),next(NULL){}
};

void printList(Node* head){
    while(head!=NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int size(Node* head){
    int cnt=0;
    while(head!=NULL){
        ++cnt;
        head = head->next;
    }
    cout << endl;
}

void addHead(Node*& head,int val){//tham chiếu
    Node* New = new Node(val);
    New->next=head;//liên kết nút mới với nút đầu tiên của danh sách

    if(head != NULL) // Liên kết nút đầu tiên của danh sách với nút mới
        head->prev=New;

    head=New;//đặt nút mới làm nút đầu của danh sách

}

void addTails(Node*& head, int val){
    Node* New = new Node(val);

    if(head == NULL){
        head=New;
        return;
    }
    Node* cur=head;
    while(cur->next!=NULL){
        cur=cur->next;
    }
    cur->next=New;// Liên kết nút mới với nút cuối cùng

    New->prev=cur;// Liên kết nút cuối cùng với nút mới
}

void addmiddle(Node*& head, int val, int k){
    int n = size(head);
    if(k < 1 || k > n + 1) return;
    if(k==1){
        addHead(head, val); 
        return;
    }
    Node* temp = head;
    for(int i=1;i<=k-1;i++){
        temp = temp->next;
    }   
    node* New = new Node(val);
    New->next = temp;
    temp->prev->next=New;
    New->prev = temp->prev;
    temp->prev = New;
}

void addIndex(Node*& head, int val, int index){
    if(index == 0 || head == NULL){
        addHead(head, val);
        return;
    }

    Node* New = new Node(val);

    //tìm nút tại vị trí index - 1
    Node* temp = head;
    for(int i=0;i<index-1 && temp!=NULL;i++){
        temp=temp->next;
    }
    // Nếu temp là nullptr, có thể index vượt quá độ dài của danh sách, không thêm
    if(temp == NULL){
        delete New;
        return;
    }
    New->next = temp->next;//liên kết nút mới với nút tiếp theo của temp

    temp->next = New; // Liên kết temp với nút mới

    New->prev = temp; // Liên kết nút mới với temp

    // Nếu nút mới không phải là nút cuối cùng, liên kết nút tiếp theo của nó với nút mới
    if(New->next!=NULL)
        New->next->prev = New;
}