// @Func: 在不排序的情况下，求出数组元素的中位数
// @mainly: 转换为 ==> 求查找数组元素中第k位的元素

#include <iostream>

using namespace std;

// 采取快速排序的思想
int Divide(int a[], int begin, int end) {
    int v = a[begin];

    while( begin < end ) {
        while( (a[end] >= v) && (begin < end) )
            end--;

        swap(a[begin], a[end]);

        while( (a[begin] < v) && (begin < end) )
            begin++;

        swap(a[begin], a[end]);
    }

    a[begin] = v;

    return begin;
}

int FindNumK(int a[], int begin, int end, int k) {
    int ret = 0;
    // 递归出口1：数组只有一个元素时
    if(begin == end) {
        ret = a[begin];
    } else {
        int pred = Divide(a, begin, end);
        // 递归出口2
        if( pred == k )
            ret = a[pred];
        else if( pred < k )
            ret = FindNumK(a, pred+1, end, k);
        else if( pred > k )
            ret = FindNumK(a, begin, pred-1, k);
    }

    return ret;
}

int FindNumK(int a[], int n, int k) {
    // 防御性编程
    if( (0 <= k) && (k <= (n-1))) {
        return FindNumK(a, 0, n-1, k);
    } else {
        cout << "the k is not valid!!" << endl;
        exit(1);
    }
}

// 寻找中位数转换为寻找第（n-1）/2位置的数值
int FindMid(int a[], int n) {
    return FindNumK(a, n, (n-1)/2);
}

int main() {
    int a[] = {4,3,2,1,5,7,6,8,9};
    int len = sizeof(a) / sizeof(*a);

    cout << FindNumK(a, len, 3) << endl;
    cout << FindMid(a, len) << endl;
}