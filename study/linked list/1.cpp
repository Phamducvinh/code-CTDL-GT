/*
Remove các phần tử trùng lặp trong linked list đã được sắp xếp

Cho một linked list được sắp xếp theo thứ tự tăng dần, 
hãy viết một hàm loại bỏ bất kỳ nút trùng lặp nào khỏi danh sách bằng cách duyệt qua danh sách chỉ một lần

Cho ví dụ là:  {1, 2, 2, 2, 3, 4, 4, 5} 

sau khi thực hiện sẽ được kết quả là: {1, 2, 3, 4, 5}

Gợi ý: Vì danh sách được sắp xếp, chúng ta có thể tiến hành rút gọn danh sách và so sánh các nút liền kề. 
Khi các nút liền kề giống nhau, hãy loại bỏ nút thứ hai. Có một trường hợp phức tạp trong đó nút sau nút tiếp theo cần được lưu ý trước khi xóa.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int val):data(val),next(NULL){}
};

void removeDuplicates(Node* Head){
    if(Head == NULL)
        return;
    Node* cur = Head;
    while(cur->next != NULL){
        if(cur->data = cur->next->data){
            Node* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        }else{
            cur = cur->next;
        }
    }
}