// @Func: 计算n个整型数的平均数
// @mainly: 考虑溢出问题和精度损失问题

#include <iostream>

using namespace std;

// 任何数都可以转换为形式：x = β*n+θ
int ToAverage(const int a[], int n) {
    int ret = 0;

    if(n > 0) {
        int m = 0;

        for(int i = 0; i < n; i++) {
            ret += a[i] / n; // 求得前面整除n的部分
            m += a[i] % n;   // 累加后边θ的部分

            // 动态获取修正部分
            ret += m / n;
            m = m % n;
        }
    }

    return ret;
}

// 经典解法
int ToAverageClassics(const int a[], int n) {
    int ret = 0;

    if(n > 0) {
        for(int i = 0; i < n; i++) {
            ret += a[i];
        }

        ret = ret / n;
    }

    return ret;
}

int main() {
    int a[] = {1,2,3,5,6,4,5,4,5,3,6, 2000};
    int len = sizeof(a) / sizeof(*a);

    cout << ToAverage(a, len) << endl;
    cout << ToAverageClassics(a, len) << endl;
}
