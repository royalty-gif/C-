/*
 *  问题：翻转二叉树
 *  二叉树翻转本质为：交换每个结点的左右子树
 */

#include <iostream>
#include <queue>

template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(nullptr), right(nullptr) {}
    explicit TreeNode(T data) : data(data), left(nullptr), right(nullptr) {}
};

void reverse(TreeNode<int>* root) {

    if( root != nullptr ) {
        std::queue<TreeNode<int>*> queue;

        queue.emplace(root);

        while(!queue.empty()) {

            size_t len = queue.size();

            for(int i = 0; i < len; i++) {
                auto* node = queue.front();

                queue.pop();

                if( node == nullptr ) continue;

                queue.emplace(node->left);
                queue.emplace(node->right);

                std::swap(node->left, node->right);
            }
        }
    }
}

#define NODE_VAL(pVal) ((pVal != nullptr) ? (pVal->data) : 0)

int main() {
    auto* root = new TreeNode<int>(1);

    root->left = new TreeNode<int>(2);
    root->left->left = new TreeNode<int>(3);
    root->right = new TreeNode<int>(4);

    reverse(root);

    std::cout << root->data <<std::endl;
    std::cout << "left: " << NODE_VAL(root->left) <<std::endl;
    std::cout << "right: " << NODE_VAL(root->right) <<std::endl;

    std::cout << root->right->data <<std::endl;
    std::cout << "left: " << NODE_VAL(root->right->left) <<std::endl;
    std::cout << "right: " << NODE_VAL(root->right->right) <<std::endl;

    return 0;
}