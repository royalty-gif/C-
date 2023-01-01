// @Func: IsContained 用于判断数组a是否包含数值x

#include <iostream>

using namespace std;


bool IsContained(int a[], int begin, int end, int x) {
    bool ret = false;

    if( begin == end ) {
        // 递归出口
        ret = (a[begin] == x);
    } else {
        // 以下两种方式都可以，向前递归或向后递归
        // ret = (a[begin] == x) || IsContained(a, begin+1, end, x);
        ret = (a[end] == x) || IsContained(a, begin, end-1, x);
    }

    return ret;
}

bool IsContained(int a[], int n, int x) {
    return IsContained(a, 0, n-1, x);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8};
    int len = sizeof(a) / sizeof(*a);

    cout << IsContained(a, len, 4) << endl;
}