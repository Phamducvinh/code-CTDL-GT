#include<bits/stdc++.h>
using namespace std;

const int MaxN = 3;
class Stack{
public:
    int a[MaxN];
    int top;

    Stack():top(-1){
        for(int i=0;i<3;i++){
            a[i]=0;
        }
    }

    bool isFull(){
        if(top == MaxN - 1){
            return true;
        }else
            return false;
    }

    bool isEmpty(){
        if(top < 0) return true;
        else return false;
    }

    void push(int val){
        if(isFull()){
            cout << "FULL" << endl;
        }else{
            top++;
            a[top] = val;
        }
    }

    int pop() {
    // Kiểm tra xem ngăn xếp có rỗng không, sử dụng hàm isEmpty()
    if (isEmpty()) {
        cout << "stack is empty" << endl;
        return -1; // Nếu rỗng, trả về giá trị -1 để thể hiện lỗi hoặc ngăn xếp không có phần tử nào để lấy
    } else {
        // Nếu ngăn xếp không rỗng
        int u = a[top]; // Lấy giá trị ở đỉnh ngăn xếp
        top--; // Giảm chỉ số đỉnh ngăn xếp để "loại bỏ" phần tử vừa lấy
        return u; // Trả về giá trị vừa lấy từ đỉnh ngăn xếp
    }
}

};
int main(){
    Stack st;
    int a[MaxN];
    st.push(4);
    st.push(6);
    st.push(8);

    cout << st.pop() << endl ;
    cout << st.pop();
}