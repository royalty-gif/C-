// @Func: IsOrdered 用于判断数组a是否已经有序

#include <iostream>

using namespace std;

bool IsOrdered(int a[], int begin, int end, bool min2max) {
    bool ret = false;

    if( begin == end ) {
        ret = true;
    } else {
        // 存在剪枝，不符合的直接不需要递归
        if(min2max) {
            ret = ( a[begin] <= a[begin+1] ) && IsOrdered(a, begin+1, end, min2max);
        } else {
            ret = ( a[begin] >= a[begin+1] ) && IsOrdered(a, begin+1, end, min2max);
        }
    }

    return ret;
}

bool IsOrdered(int a[], int n, bool min2max = true) {
    return IsOrdered(a, 0, n-1, min2max);
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8};
    int b[] = {8,7,6,5,4,3,2,1};
    int len = sizeof(a) / sizeof(*a);

    cout << IsOrdered(a, len, false) << endl;
}