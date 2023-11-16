/*
 *  问题：有一个整型数组a[n]和一个大小为w的窗口，窗口每次向右滑动一个位置，求窗口最大值数组
 *  示例：int arr[] = {4, 3, 5, 4, 3, 3, 6, 7}, 窗口w = 3
 *  输出：[5, 5, 5, 4, 6, 7]
 */

#include <iostream>
#include <deque>
#include <memory>

std::shared_ptr<int[]> getWinMax(const int arr[], int len, int w) {
    std::shared_ptr<int[]> ret(new int[len - w + 1]);
    std::deque<int> dq{};
    int index = 0;

    for(int i = 0; i < len; i++) {
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        dq.emplace_back(i);

        if( i >= (w - 1) ) {
            ret[index++] = arr[dq.front()];

            if( (i - w + 1) >= dq.front() ) {
                dq.pop_front();
            }
        }
    }

    return ret;
}

int main() {
    int arr[] = {4, 3, 5, 4, 3, 3, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int w = 3;

    std::shared_ptr<int[]> r = getWinMax(arr, len, w);

    for(int i = 0; i < len - w + 1; i++) {
        std::cout << i << " : " << r[i] << std::endl;
    }

    return 0;
}