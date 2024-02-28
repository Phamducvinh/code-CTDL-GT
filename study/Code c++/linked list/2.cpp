/*
Đảo ngược mọi nhóm k nút trong danh sách liên kết đã cho

Cho một danh sách liên kết, đảo ngược mọi nhóm k nút liền kề trong đó với k là số nguyên dương.

Ví dụ:

Input: 1>2>3>4>5>6>7>8>null

k = 3

Output: 3>2>1>6>5>4>8>7>null

k=2

Output: 2>1>4>3>6>5>8>7>null

k = 8

Output: 8>7>6>5>4>3>2>1>null

Gợi ý:

Ý tưởng là xem xét mọi nhóm k nút và đảo ngược đệ quy từng nút một. Cần phải đặc biệt chú ý khi liên kết các nhóm đảo ngược với nhau.
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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
}

Node* reverseList(Node* head,int k) {
        Node* prev = NULL,* curr = head,* next = NULL;

        int count = 0;

        Node* temp = head;
        while(temp != NULL && count < k){
            temp = temp->next;
            count++;
        }

        if(count<k){
            return head;
        }

        while (curr != NULL && count > 0) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count--;
        }

        if(next != NULL){
            head->next = reverseList(next, k);
        }
        return prev;
}
int main() {
    // Populate the linked list
    for (int i = 1; i <= 8; i++) {
        Node* newNode = new Node(i);
        newNode->next = head;
        head = newNode;
    }

    // Print original list
    cout << "Original List: ";
    printList();

    // Reverse groups of k nodes
    int k = 3;
    head = reverseList(head, k);

    // Print reversed list
    cout << "Reversed List with k = " << k << ": ";
    printList();

    return 0;
}