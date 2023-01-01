// @Func: MaxInArray 用于查找数组a中的最大值

#include <iostream>

using namespace std;

int MaxInArray(int a[], int begin, int end) {
    int ret = 0;

    if( begin == end ) {
        ret = a[begin];
    } else {
        // 折中法
        int mid = (begin >> 1) + (end >> 1) + (begin & end & 1);
        int lmax = MaxInArray(a, begin, mid);
        int rmax = MaxInArray(a, mid+1, end);

        return (lmax > rmax) ? lmax : rmax;
    }

    return ret;
}

int MaxInArray(int a[], int n) {
    return MaxInArray(a, 0, n-1);
}

int main() {
    int a[] = {1,2,3,4,10,6,7,8};
    int len = sizeof(a) / sizeof(*a);

    cout << MaxInArray(a, len);
}