#include <bits/stdc++.h>
using namespace std;

class node{
public:
    char data;
    node* next;

    node(char val):data(val),next(NULL){}
};

node* top = NULL;

class Stack{
public:
    void push(int val){
        node* New = new node(val);
        New->next = top;
        top = New;
    }

    bool isEmpty(){
        return top == NULL;
    }

    char pop(){
        if(isEmpty()){
            cout << "empty" << endl;
            return -1;
        }else{
            char val = top->data;
            top = top->next;
            return val;
        }
    }
};
void dao_nguoc(string s){
    Stack st;
    for(int i = 0; i < s.length(); i++){
        st.push(s[i]);
    }

    while (!st.isEmpty())
    {
        cout << st.pop();
       // st.pop();
    }
    

}

int chuyen_nhi_phan(int n){
    Stack st;
    while (n > 0)
    {
        st.push(n%2 + '0');
        n /= 2;
    }

    while(!st.isEmpty()){
        cout << st.pop();
    }
    
}

int main(){
    Stack st;
    string s;
    getline(cin,s);
    cout << "dao chuoi: ";
    dao_nguoc(s);

    cout << endl;

    int n;
    cin >> n;
    cout << "nhi phan: ";
    chuyen_nhi_phan(n);
    
    return 0;
}