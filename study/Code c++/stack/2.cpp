#include <bits/stdc++.h>
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
    char pop(){
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
            cout << cur->data << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};
void solve(){
    string s; cin >> s;
    Stack st;
    for(char x : s){
        if(x == '('){
            st.push(x);
        }else{
            if(st.isEmpty()){
                cout << "INVALID\n";
                return;
            }else
                st.pop();
        }
    }
    if(st.isEmpty()){
        cout << "VALID\n";
    }else cout << "INVALID\n";
    
}
int main(){
    int t; cin >> t;
    Stack st;
    while(t--){
        solve();
    }
    //st.print();
}