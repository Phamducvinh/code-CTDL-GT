/*
Bài 1: Kiểm tra xem hai cây nhị phân có giống nhau hay không

Viết một thuật toán hiệu quả để kiểm tra xem hai cây nhị phân có giống nhau hay không. tức là nếu chúng có cấu trúc giống nhau thì nội dung của chúng cũng giống nhau

Gợi ý: Ý tưởng là duyệt qua cả hai cây và so sánh giá trị tại nút gốc của chúng. Nếu giá trị khớp, chúng tôi kiểm tra đệ quy xem cây con bên trái của cây thứ nhất có giống với cây con bên trái của cây thứ hai và cây con bên phải của cây thứ nhất có trùng với cây con bên phải của cây thứ hai hay không. Nếu giá trị tại nút gốc của chúng khác nhau, cây vi phạm thuộc tính dữ liệu. Nếu tại bất kỳ thời điểm nào trong đệ quy, cây đầu tiên rỗng cây thứ hai không trống hoặc cây thứ hai rỗng cây thứ nhất không rỗng, các cây vi phạm thuộc tính cấu trúc và chúng không thể giống nhau.

*/
#include <iostream>

// Định nghĩa một nút trong cây nhị phân
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int value): val(value), left(nullptr), right(nullptr) {}
};

// Hàm kiểm tra hai cây nhị phân có giống nhau hay không
bool isSameTree(TreeNode* p, TreeNode* q) {
    // Nếu cả hai cây đều rỗng, chúng giống nhau
    if (p == nullptr && q == nullptr)
        return true;
    
    // Nếu chỉ một trong hai cây rỗng, chúng không giống nhau
    if (p == nullptr || q == nullptr)
        return false;
    
    // So sánh giá trị tại nút gốc của hai cây
    if (p->val != q->val)
        return false;
    
    // Kiểm tra đệ quy cây con bên trái và cây con bên phải
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main(){
    
}