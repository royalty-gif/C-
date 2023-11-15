/*
 *  进阶版：
 *  问题：如果数组中arr含有重复元素，找到每一个位置i左边和右边离位置i最近且比arr[i]小的位置，返回所有位置的距离信息
 *  示例：int arr[] = {3, 4, 4, 2}
 *  输出：{-1, 3}, {0, 3}, {0, 3}, {-1, -1}
 *  要求：时间复杂度越低越好
 */

#include <iostream>
#include <stack>
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

std::shared_ptr<Pos[]> findNearPosEx(const int arr[], int len) {
    std::shared_ptr<Pos[]> ret(new Pos[len]);
    std::stack< std::stack<int> > stack{};

    int i = 0;

    while(i < len) {

        if(!stack.empty() && arr[stack.top().top()] > arr[i]) {
            std::stack<int> top = stack.top();
            Pos p;

            stack.pop();

            while( !top.empty() ) {
                int index = top.top();

                top.pop();

                p.left = !stack.empty() ? stack.top().top() : -1;
                p.right = i;
                p.pos = index;

                ret[p.pos] = p;
            }
        } else if(!stack.empty() && arr[stack.top().top()] == arr[i]) {
            stack.top().push(i);
            i++;
        } else {
            std::stack<int> val{};

            val.push(i);

            stack.push(val);

            i++;
        }
    }

    // 处理栈不为空的情况
    while( !stack.empty() ) {
        std::stack<int> top = stack.top();
        Pos p;

        stack.pop();

        while( !top.empty() ) {
            int index = top.top();

            top.pop();

            p.left = !stack.empty() ? stack.top().top() : -1;
            p.right = -1;
            p.pos = index;

            ret[p.pos] = p;
        }
    }

    return ret;
}

int main() {
    int arr[] = {3, 4, 4, 2};
    int len = sizeof(arr) / sizeof(arr[0]);

    std::shared_ptr<Pos[]> r = findNearPosEx(arr, len);

    for(int i = 0; i < len; i++) {
        std::cout << i << " : {" << r[i].left << ", " << r[i].right << "} " << std::endl;
    }

    return 0;
}