/*
Bài 3: Di chuyển nút cuối cùng lên phía trước trong Danh sách được liên kết nhất định

Cho một danh sách được liên kết, hãy di chuyển nút cuối cùng của nó lên phía trước.

Ví dụ: Input: 1,2,3,4

Output: 4,1,2,3

Gợi ý: Ý tưởng là làm cho danh sách được liên kết có hình tròn và sau đó ngắt chuỗi 
trước nút cuối cùng sau khi làm cho danh sách này hướng đến nút cuối cùng.
*/
#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int val):data(val),next(NULL){}
};
Node* Head = NULL;
void printList(){
    Node* cur = Head;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur=cur->next;
    }
    cout << endl;
}
Node* moveLastToFront(){
    if(Head == NULL){
        return Head;
    }
    Node* last = NULL;
    Node* secondLast = NULL;
    Node* cur = Head;
    while(cur->next!=NULL){
        secondLast=cur;
        cur=cur->next;
    }
    secondLast->next = NULL;
    cur->next=Head;
    Head = cur;

    return Head;
}