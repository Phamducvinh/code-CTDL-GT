#include <iostream>

using namespace std;

// Khai báo cấu trúc của nút trong cây
template <typename T>
struct TreeNode {
    T data;
    TreeNode* parent;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(T val) : data(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

// Khai báo cấu trúc của cây nhị phân
template <typename T>
class BinaryTree {
private:
    TreeNode<T>* root; // Nút gốc của cây
    int size; // Kích thước của cây

public:
    // Khởi tạo một cây rỗng
    BinaryTree() : root(nullptr), size(0) {}

    // Bổ sung phần tử x trở thành nút cha của nút P trong cây
    void InsertParent(T x, TreeNode<T>* P) {
        TreeNode<T>* newNode = new TreeNode<T>(x);
        newNode->left = P;
        if (P != nullptr) {
            newNode->parent = P->parent;
            if (P->parent != nullptr) {
                if (P->parent->left == P)
                    P->parent->left = newNode;
                else
                    P->parent->right = newNode;
            }
            P->parent = newNode;
        }
        if (P == root) // Nếu P là gốc, thì gán nút mới làm gốc mới
            root = newNode;
        size++;
    }

    // Bổ sung phần tử x trở thành nút con trái của nút P trong cây
    void InsertLeftChild(T x, TreeNode<T>* P) {
        TreeNode<T>* newNode = new TreeNode<T>(x);
        P->left = newNode;
        newNode->parent = P;
        size++;
    }

    // Bổ sung phần tử x trở thành nút con phải của nút P trong cây
    void InsertRightChild(T x, TreeNode<T>* P) {
        TreeNode<T>* newNode = new TreeNode<T>(x);
        P->right = newNode;
        newNode->parent = P;
        size++;
    }

    // Tìm một nút có giá trị bằng x trong cây
    TreeNode<T>* FindNode(T x) {
        return FindNodeHelper(x, root);
    }

    // Hàm trợ giúp để tìm nút có giá trị x
    TreeNode<T>* FindNodeHelper(T x, TreeNode<T>* node) {
        if (node == nullptr || node->data == x)
            return node;
        TreeNode<T>* leftResult = FindNodeHelper(x, node->left);
        if (leftResult != nullptr)
            return leftResult;
        return FindNodeHelper(x, node->right);
    }

    // Xóa nút hiện trỏ bởi P trong cây
    void DeleteCurrentNode(TreeNode<T>* P) {
        if (P == nullptr)
            return;

        if (P->parent != nullptr) {
            if (P->parent->left == P)
                P->parent->left = nullptr;
            else
                P->parent->right = nullptr;
        }

        delete P;
        size--;
    }

    // Xóa nút con trái của P
    void DeleteLeftChild(TreeNode<T>* P) {
        if (P != nullptr && P->left != nullptr) {
            DeleteCurrentNode(P->left);
            P->left = nullptr;
        }
    }

    // Xóa nút con phải của P
    void DeleteRightChild(TreeNode<T>* P) {
        if (P != nullptr && P->right != nullptr) {
            DeleteCurrentNode(P->right);
            P->right = nullptr;
        }
    }

    // Trả về kích thước của cây
    int GetSize() const {
        return size;
    }
};

int main() {
    // Khởi tạo một cây nhị phân
    BinaryTree<int> tree;

    // Thêm các nút vào cây
    TreeNode<int>* root = new TreeNode<int>(10);
    tree.InsertParent(20, root);
    tree.InsertLeftChild(15, root);
    tree.InsertRightChild(25, root->parent);

    // Tìm nút có giá trị là 15
    TreeNode<int>* node = tree.FindNode(15);
    if (node != nullptr)
        cout << "Found node: " << node->data << endl;
    else
        cout << "Node not found!" << endl;

    // Xóa nút con trái của nút gốc
    tree.DeleteLeftChild(root);

    // In ra kích thước của cây sau khi thực hiện xóa
    cout << "Size of tree: " << tree.GetSize() << endl;

    return 0;
}
