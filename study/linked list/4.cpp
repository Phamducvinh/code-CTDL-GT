/*
Xóa mọi N nút trong danh sách được liên kết sau khi bỏ qua M nút

Cho một danh sách được liên kết và hai số nguyên dương M và N, 
xóa mọi N nút trong đó sau khi bỏ qua M nút.

Ví dụ:

1>2>3>4>5>6>7>8>9>10>null

if M = 1, N = 3

Output: 1>5>9>null

if M=2, N=2

Output: 1>2>5>6>9>10>null

Gợ ý: Ý tưởng rất đơn giản. Chúng tôi duyệt qua danh sách đã cho và 
bỏ qua m nút đầu tiên và xóa n nút tiếp theo trong đó và lặp lại cho các nút còn lại. 
Giải pháp rất đơn giản nhưng chúng ta cần đảm bảo rằng 
tất cả các điều kiện biên được xử lý đúng cách trong code.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val),next(NULL){}
};
Node* head = NULL;
void printList(){
    Node* cur = head;
    while(cur->next!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }
    cout << endl;
}
Node* deleteMAfterN(int M, int N){
    if(head==NULL || N <= 0 || M < 0){
        return head;
    }
    Node* cur = head;
    Node* temp = NULL;

    for(int i=0;i<M-1 && cur != NULL;i++){
        cur=cur->next;
    }

    if(cur == NULL)
        return head;

    for(int i=0;i<N && cur!=NULL && cur->next!=NULL;i++){
        temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
    return head;
}

void linkdelete(int M, int N)
{
    if(!head)
        return;
    Node* cur = head;
    Node* temp = NULL;
            
    for(int i=0;i<M-1 && cur!=NULL;i++){
       cur=cur->next;
    }
            
    if(!cur || !cur->next)
        return;
                
    for(int i=0;i<N && cur!=NULL && cur->next!=NULL;i++){
        temp = cur->next;
        cur->next = temp->next;
        delete temp;
    }
    temp=cur->next;
    linkdelete(temp,M,N);
}
