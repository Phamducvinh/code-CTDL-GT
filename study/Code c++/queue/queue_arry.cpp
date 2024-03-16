#include <bits/stdc++.h>
using namespace std;

class Queue{
public:
    int a[3];
    int left,right,size;

    Queue():left(0),right(-1),size(0){
        for(int i=0;i<3;i++){
            a[i] = 0;
        }
        bool isEmpty(){
            if(size == 0)
                return true;
            else
                return false;
        }

        bool isFull(){
            if(size == 3)
                return true;
            else
                return false;
        }

        void push(int val){
            if(isFull()){
                cout << "Full" << endl;
            }else{
                if(right == 2){
                    right = 0;
                }else{
                    right++;
                    size++;
                    a[right] = val;
                }
            }
        }

        int pop(){
            if(isEmpty()){
                cout << "empty " << endl;
                return -1;
            }else{
                int u = [left];
                if(left == 2){
                    left = 0;
                }else{
                    left++;
                    size--;
                    return u;
                }
            }
        }
    }

};
