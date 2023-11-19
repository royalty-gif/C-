/*
 *  问题：求一颗二叉树的最小高度，即离根节点最近的叶节点的距离
 *  思维起点：链表是特殊的二叉树，二叉树是特殊的树，树是特殊的图
 *  结论：二叉树是特殊的图
 *  转换：求二叉树的最小高度 --> 求图中离根节点最近的叶节点的距离
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

// 递归版本
int minHeightRec(TreeNode<int>* root) {
    int ret = 0;

    if( root != nullptr ) {
        int lmh = minHeightRec(root->left);
        int rmh = minHeightRec(root->right);

        ret = std::min(lmh, rmh) + 1;
    }

    return ret;
}

// 广度优先（BFS）
int minHeight(TreeNode<int>* root) {
    int ret = 0;

    if( root != nullptr ) {
        std::queue<TreeNode<int>*> queue;

        queue.emplace(root);
        ret = 1;

        while( !queue.empty() ) {
            size_t len = queue.size();

            for(int i = 0; i < len; i++) {
                auto* node = queue.front();
                queue.pop();

                if( node == nullptr ) continue;

                // 叶子结点
                if( (node->left == nullptr) && (node->right == nullptr) ) {
                    return ret;
                }

                queue.emplace(node->left);
                queue.emplace(node->right);
            }

            ret++;
        }
    }

    return ret;
}

void minHeight() {
    auto* node = new TreeNode<int>(0);

    node->left = new TreeNode<int>(1);
    node->left->left = new TreeNode<int>(2);
    node->right = new TreeNode<int>(3);

    std::cout << "min height: " << minHeight(node) << std::endl;
}

int main() {
    minHeight();
}