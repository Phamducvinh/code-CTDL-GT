#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val):data(val),next(NULL){}
    
};
Node* Head = NULL;

void addHead(int val) {
    // Tạo một nút mới với giá trị được cung cấp
    Node* New = new Node(val);

    // Thiết lập con trỏ next của nút mới để trỏ đến nút đầu danh sách cũ
    New->next = Head;

    // Cập nhật con trỏ đầu danh sách để trỏ vào nút mới (nút đầu mới)
    Head = New;
}

void addTaild(int val) {
    // Tạo một nút mới với giá trị được cung cấp
    Node* New = new Node(val);

    // Khởi tạo con trỏ cur để duyệt qua danh sách từ đầu
    Node* cur = Head;

    // Duyệt đến nút cuối cùng của danh sách
    while (cur->next != NULL) {
        cur = cur->next;
    }

    // Nối nút mới vào cuối danh sách
    cur->next = New;

    // Đặt con trỏ next của nút mới thành NULL để chỉ ra là nó là nút cuối cùng
    New->next = NULL;
}

void addIndex(int index, int val) {
    // Tạo một nút mới với giá trị được cung cấp
    Node* New = new Node(val);

    // Kiểm tra xem vị trí chèn là đầu danh sách
    if (index == 0) {
        // Nối nút mới với đầu danh sách và làm cho nút mới trở thành đầu danh sách
        New->next = Head;
        Head = New;
    } else {
        // Nếu vị trí chèn không phải là đầu danh sách

        // Khởi tạo con trỏ cur để duyệt qua danh sách từ đầu
        Node* cur = Head;

        // Duyệt đến vị trí trước vị trí chèn hoặc cuối danh sách
        for (int i = 0; i < index - 1 && cur != NULL; i++) {
            cur = cur->next;
        }

        // Kiểm tra xem đã đến cuối danh sách chưa
        if (cur != NULL) {
            // Nối nút mới vào giữa danh sách
            New->next = cur->next;
            cur->next = New;
        }
    }
}


void deleteHead() {
    // Tạo một con trỏ tạm thời để giữ địa chỉ của nút đầu tiên
    Node* temp = Head;

    // Cập nhật con trỏ đầu danh sách để bỏ qua nút đầu tiên
    Head = Head->next;

    // Xóa nút đầu tiên
    delete temp;
}


void deleteTail() {
    // Kiểm tra xem danh sách liên kết có rỗng không
    if (Head == NULL) {
        cout << "Danh sách liên kết trống. Không có gì để xóa." << endl;
        return;
    }

    // Kiểm tra xem có một nút duy nhất trong danh sách không
    if (Head->next == NULL) {
        // Nếu chỉ có một nút, xóa nó
        delete Head;
        Head = NULL;
        return;
    }

    // Khởi tạo con trỏ cho việc duyệt qua danh sách
    Node* cur = Head;
    Node* prev = NULL;

    // Duyệt đến nút cuối cùng
    while (cur->next != NULL) {
        prev = cur;
        cur = cur->next;
    }

    // Xóa nút cuối cùng
    delete cur;

    // Cập nhật con trỏ next của nút trước đó thành NULL, chỉ ra rằng nút đó là đuôi mới
    prev->next = NULL;
}


void deleteAtIndex(int index) {
    // Kiểm tra xem index có hợp lệ không
    if (index < 0)
        return;

    // Trường hợp đặc biệt: xóa đầu danh sách
    if (index == 0) {
        Head = Head->next;  // Cập nhật đầu danh sách để bỏ qua nút đầu tiên
    }

    // Khởi tạo con trỏ cur để duyệt qua danh sách từ đầu
    Node* cur = Head;
    
    // Duyệt đến vị trí trước vị trí cần xóa hoặc cuối danh sách
    for (int i = 0; i < index - 1 && cur; i++) {
        cur = cur->next;
    }

    // Kiểm tra xem có nút cần xóa không
    if (!cur || !cur->next)
        return;

    // Xóa nút bằng cách cập nhật con trỏ next của nút trước nút cần xóa
    cur->next = cur->next->next;
}


void reverseList() {
    // Khởi tạo ba con trỏ: prev (trỏ đến nút trước), curr (trỏ đến nút hiện tại), next (trỏ đến nút kế tiếp)
    Node* prev = NULL;
    Node* curr = Head;
    Node* next = NULL;

    // Duyệt qua danh sách liên kết
    while (curr != NULL) {
        // Lưu trữ con trỏ tới nút kế tiếp để không mất mối liên kết khi đảo ngược
        next = curr->next;

        // Đảo ngược mối liên kết bằng cách trỏ con trỏ next của nút hiện tại về nút trước đó
        curr->next = prev;

        // Cập nhật con trỏ prev và curr để di chuyển đến nút tiếp theo trong danh sách
        prev = curr;
        curr = next;
    }

    // Cập nhật con trỏ Head để trỏ vào nút cuối cùng (nút đầu sau khi đảo ngược)
    Head = prev;
}



void print(){
    Node* current = Head;
    while(current != NULL){
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}


int main() {
    cout << "Nhap so luong phan tu: ";
    int n;
    cin >> n;

    cout << "Nhap chuoi list: ";
    for (int i = 0; i < n; ++i) {
        int val;
        cin >> val;
        addHead(val); 
    }

    cout << "Linked List add Head: ";
    print();

    cout << "Nhap so luong phan tu muon them vao cuoi: ";
    int m;
    cin >> m;

    cout << "Nhap chuoi list them vao cuoi: ";
    for (int i = 0; i < m; ++i) {
        int val;
        cin >> val;
        addTaild(val);
    }

    cout << "Linked List add Tail: ";
    print();

    cout << "them index bat ki: ";
    int l;cin >> l;
    for (int i = 0; i < l; ++i) {
        int index,val;
        cout << "VT index: ";
        cin >> index;
        cout << "Gia tri them: ";
        cin >> val;
        addIndex(index,val);
    }
    print();

    cout << "Deleting the head node..." << endl;
    deleteHead();
    cout << "Linked list after the head: ";
    print();

    cout << "Deleting the Tail node..." << endl;
    deleteTail();
    cout << "Linked List after deleting the Tail: ";
    print();

    cout << "Nhap vi tri muon xoa: ";
    int deleteIndex;
    cin >> deleteIndex;

    deleteAtIndex(deleteIndex);

    cout << "Linked List after deleting at index " << deleteIndex << ": ";
    print();

    cout << "reverseList: " ;
    reverseList();
    print();

    

    return 0;
}
