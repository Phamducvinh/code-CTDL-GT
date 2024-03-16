#include <bits/stdc++.h>
using namespace std;

class Queue{
    class node{
    public:
        int data;
        node* next;

        node(int val):data(val),next(NULL){}
    };
    node* left;
    node* right;
    int size;
public:
    Queue():left(NULL),right(NULL),size(0){}

    void push(int val){
        node* New = new node(val);
        if(size==0){
            left=right=New;
        }else{
            right->next = New;
            right = New;
        }
        size++;
    }

    int pop(){
        int val = left->data;
        left = left->next;
        size--;
        return val;
    }

    void print(){
        node* cur = left;
        while(cur != NULL){
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(){
    Queue q;
    q.push(3);
    q.push(5);
    q.push(7);
    q.print();
    q.pop();
    q.print();
}