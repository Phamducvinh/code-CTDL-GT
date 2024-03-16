#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(NULL), prev(NULL) {}
};

void addHead(Node*& head, int val) {
    Node* New = new Node(val);

    New->next = head;

    if (head != NULL) {
        head->prev = New;
    }

    head = New;
}

void addTails(Node*& head, int val) {
    Node* New = new Node(val);
    if (head == NULL) {
        head = New;
        return;
    }
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = New;
    New->prev = cur;
}

void addIndex(Node*& head, int val, int index) {
    if (index < 0)
        return;
    
    if (index == 0) {
        addHead(head, val);
        return;
    }

    Node* New = new Node(val);
    Node* cur = head;
    int i = 0;
    while (cur != NULL && i < index - 1) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL)
        return;
    
    New->next = cur->next;
    if (cur->next != NULL)
        cur->next->prev = New;
    
    cur->next = New;
    New->prev = cur;
}

void deleteHead(Node*& head) {
    if (head == NULL)
        return;
    
    Node* temp = head;
    head = head->next;
    if (head != NULL)
        head->prev = NULL;
    delete temp;
}

void deleteTails(Node*& head) {
    if (head == NULL)
        return;
    
    if (head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }

    Node* cur = head;
    while (cur->next->next != NULL) {
        cur = cur->next;
    }
    delete cur->next;
    cur->next = NULL;
}

void deleteIndex(Node*& head, int index) {
    if (head == NULL || index < 0)
        return;
    
    if (index == 0) {
        deleteHead(head);
        return;
    }

    Node* cur = head;
    int i = 0;
    while (cur != NULL && i < index) {
        cur = cur->next;
        i++;
    }
    if (cur == NULL || cur->next == NULL)
        return;
    
    cur->prev->next = cur->next;
    if (cur->next != NULL)
        cur->next->prev = cur->prev;
    
    delete cur;
}

int main() {
    Node* head = NULL;
    addHead(head, 3);
    addHead(head, 2);
    addHead(head, 1);
    addTails(head, 4);
    addTails(head, 5);
    addIndex(head, 6, 2);
    deleteHead(head);
    deleteTails(head);
    deleteIndex(head, 2);

    // Display the remaining elements in the list
    Node* cur = head;
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    return 0;
}
