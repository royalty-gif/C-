/*
 *  问题：给定一个不含重复元素的数组arr，找到每一个位置i左边和右边离位置i最近且比arr[i]小的位置，返回所有位置的距离信息
 *  示例：int arr[] = {3, 4, 1, 5, 6, 2, 7}
 *  输出：{-1, 2}, {0, 2}, {-1, -1}, {2, 5}, {3, 5}, {2, -1}, {5, -1}
 *  要求：时间复杂度越低越好
 */

#include <iostream>
#include <stack>
#include <vector>
#include <memory>

struct Pos {
    int pos;
    int left;
    int right;

    explicit Pos(int pos = -1, int left = -1, int right = -1) {
        this->pos = pos;
        this->left = left;
        this->right = right;
    }
};

std::shared_ptr<Pos[]> findNearPos(const int arr[], int len) {
    std::shared_ptr<Pos[]> ret(new Pos[len]);
    std::stack<int> stack{};

    int i = 0;

    while(i < len) {

        if(!stack.empty() && arr[stack.top()] > arr[i]) {
            int top = stack.top();
            Pos p;

            stack.pop();

            p.left = !stack.empty() ? stack.top() : -1;
            p.right = i;
            p.pos = top;

            ret[p.pos] = p;

        } else {
            stack.push(i++);
        }
    }

    // 处理栈不为空的情况
    while( !stack.empty() ) {
        int top = stack.top();
        Pos p;

        stack.pop();

        p.left = !stack.empty() ? stack.top() : -1;
        p.right = -1;
        p.pos = top;

        ret[p.pos] = p;
    }

    return ret;
}

int main() {
    int arr[] = {3, 4, 1, 5, 6, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    std::shared_ptr<Pos[]> r = findNearPos(arr, len);

    for(int i = 0; i < len; i++) {
        std::cout << i << " : {" << r[i].left << ", " << r[i].right << "} " << std::endl;
    }

    return 0;
}