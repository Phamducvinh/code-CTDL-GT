#include <iostream>
#include <vector>
class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

// Hàm in danh sách liên kết
void printList(Node* head) {
    while (head != nullptr) {
        std::cout << head->data;
        if (head->next != nullptr) {
            std::cout << " -> ";
        }
        head = head->next;
    }
    std::cout << std::endl;
}

// Hàm chèn một nút vào danh sách đã sắp xếp
void SortedInsert(Node** headRef, Node* newNode) {
    Node* current;
    if (*headRef == nullptr || (*headRef)->data >= newNode->data) {
        newNode->next = *headRef;
        *headRef = newNode;
    } else {
        current = *headRef;
        while (current->next != nullptr && current->next->data < newNode->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Hàm sắp xếp danh sách liên kết
void InsertionSort(Node** headRef) {
    Node* sortedList = nullptr;
    Node* current = *headRef;
    Node* next;

    while (current != nullptr) {
        next = current->next;
        SortedInsert(&sortedList, current);
        current = next;
    }

    *headRef = sortedList;
}

int main() {
    // Tạo danh sách liên kết từ mảng số liệu
    std::vector<int> data = {5, 2, 9, 1, 5, 6};
    Node* list = nullptr;

    // Tạo danh sách liên kết từ mảng số liệu
    for (int i = data.size() - 1; i >= 0; i--) {
        Node* newNode = new Node(data[i]);
        newNode->next = list;
        list = newNode;
    }

    std::cout << "Danh sách trước khi sắp xếp: ";
    printList(list);

    // Sắp xếp danh sách liên kết
    InsertionSort(&list);

    std::cout << "Danh sách sau khi sắp xếp: ";
    printList(list);

    // Giải phóng bộ nhớ
    while (list != nullptr) {
        Node* temp = list;
        list = list->next;
        delete temp;
    }

    return 0;
}
