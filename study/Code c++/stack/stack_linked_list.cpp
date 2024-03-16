#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val),next(NULL){}
};

Node* top = NULL;

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
    st.push(3);
    st.push(5);
    st.push(7);
    st.print();
    st.pop();
    st.print();
}