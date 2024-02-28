/*
Bài 5: Hợp nhất hai danh sách liên kết đã sắp xếp thành một

Viết một hàm nhận hai danh sách, mỗi danh sách được sắp xếp theo thứ tự tăng dần 
và hợp nhất hai danh sách với nhau thành một danh sách theo thứ tự tăng dần và trả về.

Ví dụ:

Input: 1>7>5>4 và 2>6>3>9

Output: 1>2>3>4>5>6>7>9

Gợi ý: Vấn đề có thể được giải quyết bằng vòng lặp hoặc đệ quy. 
Có nhiều trường hợp cần giải quyết: hoặc ‘a’ hoặc ‘b’ có thể để trống, 
trong quá trình xử lý, ‘a’ hoặc ‘b’ có thể hết đầu tiên và cuối cùng 
là vấn đề khởi động danh sách kết quả trống và xây dựng nó lên trong khi đi qua ‘a’ và ‘b’.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val),next(NULL){}
};
Node* head=NULL;
void printList(){
    Node* cur=head;
    while(cur->next!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }
    cout << endl;
}
Node* mergeTwoLists(Node* L1, Node*L2){
    if(L1==NULL)
        return L2;
    if(L2==NULL)
        return L1;
    if(L1->val <= L2->val){
        L1->next =mergeTwoLists(L1->next,L2);
        return L1;
    }else{
        L2->next = mergeTwoLists(L1,L2->next);
        return L2;
    }
}