#include <iostream>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

TreeNode* createNode(int data) {
    return new TreeNode(data);
}

TreeNode* insert(TreeNode* root, int data) {
    if (root == nullptr) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    
    return root;
}

void inorderTraversal(TreeNode* root) {
    if (root != nullptr) {
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
}

// Hàm tìm nút lá cần xóa và trả về con trỏ tới nút cha của nó
TreeNode* findParentOfLeaf(TreeNode* root, TreeNode* leaf) {
    if (root == nullptr || root == leaf)
        return nullptr;
    if (root->left == leaf || root->right == leaf)
        return root;
    if (leaf->data < root->data)
        return findParentOfLeaf(root->left, leaf);
    return findParentOfLeaf(root->right, leaf);
}

// Hàm xóa nút lá khỏi cây
void deleteLeaf(TreeNode* root, TreeNode* leaf) {
    if (root == nullptr || leaf == nullptr)
        return;

    TreeNode* parent = findParentOfLeaf(root, leaf);
    if (parent == nullptr)
        return;

    if (parent->left == leaf)
        parent->left = nullptr;
    else
        parent->right = nullptr;

    delete leaf;
}

// Hàm tìm nút có một con và trả về con trỏ tới nút cha của nó
TreeNode* findParentOfSingleChildNode(TreeNode* root, TreeNode* node) {
    if (root == nullptr || root == node)
        return nullptr;
    if ((root->left == node && root->right == nullptr) || (root->right == node && root->left == nullptr))
        return root;
    if (node->data < root->data)
        return findParentOfSingleChildNode(root->left, node);
    return findParentOfSingleChildNode(root->right, node);
}

// Hàm xóa nút có một con khỏi cây
void deleteSingleNode(TreeNode* root, TreeNode* node) {
    if (root == nullptr || node == nullptr)
        return;

    TreeNode* parent = findParentOfSingleChildNode(root, node);
    if (parent == nullptr)
        return;

    TreeNode* child = (node->left != nullptr) ? node->left : node->right;

    if (parent->left == node)
        parent->left = child;
    else
        parent->right = child;

    delete node;
}

// Hàm tìm nút kế tiếp lớn nhất trong cây con bên trái của nút cần xóa
TreeNode* findMaxLeftChild(TreeNode* root) {
    while (root->right != nullptr)
        root = root->right;
    return root;
}

// Hàm xóa nút có hai con khỏi cây
void deleteNodeWithTwoChildren(TreeNode* root, TreeNode* node) {
    if (root == nullptr || node == nullptr)
        return;

    TreeNode* maxLeftChild = findMaxLeftChild(node->left);

    // Đổi giá trị của nút cần xóa với giá trị của nút kế tiếp lớn nhất trong cây con bên trái
    node->data = maxLeftChild->data;

    // Sau đó, xóa nút kế tiếp lớn nhất trong cây con bên trái
    if (maxLeftChild->left == nullptr && maxLeftChild->right == nullptr)
        deleteLeaf(node->left, maxLeftChild);
    else
        deleteSingleNode(node->left, maxLeftChild);
}

int main() {
    TreeNode* root = nullptr;

    // Chèn các phần tử vào cây
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 12);
    root = insert(root, 17);

    cout << "cay truoc khi xoa: ";
    inorderTraversal(root);
    cout << endl;

    cout << "cay khi xoa 3: " ;
    // Xóa nút lá có giá trị là 3
    deleteLeaf(root, root->left->left);
    inorderTraversal(root);

    cout << "\ncay khi xoa 15: ";
    // Xóa nút có một con có giá trị là 15
    deleteSingleNode(root, root->right);
    inorderTraversal(root);

    cout << "\ncay sau khi xoa 10: ";
    // Xóa nút có hai con có giá trị là 10
    deleteNodeWithTwoChildren(root, root);
    inorderTraversal(root);
    
    cout << "\ncay sau khi xoa xong: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
