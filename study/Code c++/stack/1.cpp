//Chuyển đổi số nhị phân dùng ngăn xếp

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val),next(NULL){}
};

Node *top = NULL;

class Stack{
public:
    void push(int val){
        Node* New = new Node(val);
        New->next = top;
        top = New;
    }
    bool isEmpty(){
        return top == NULL;
    }
    int pop(){
        if(isEmpty()){
            cout << "Stack is empty";
            return -1;
        }else{
            int val = top->data;
            top = top->next;
            return val;
        }
    }
    void print(){
        Node* cur = top;
        while(cur != NULL){
            cout << cur->data << "  ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(){
    Stack st;
    int n;cin>>n;
    while(n != 0){
        st.push(n % 2);
        n /= 2;
    }
    while(!st.isEmpty()){
        cout << st.pop();
        
    }
    st.print();
}