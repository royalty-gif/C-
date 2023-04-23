/*
 *  基本思想：
 *  1. 归并：将两个的有序数列合并成一个有序数列
 *  2. 排序思路中和快速排序算法一样使用到了递归的思想，同时在归并排序中还用到了一个算法，就是有序数组合并算法。
 *  3. 配合递归与有序数组合并算法，归并排序能够高效且稳定的完成排序，
 *  @note: 优点在于其时间复杂度低，稳定性高，但是缺点也是有的，那就是空间复杂度很高（需要同样大小的辅助空间）
 */

#include <iostream>

#pragma once

class Sort {
public:
    template<typename T>
    static void mergeSort(T array[], int len, bool min2Max) {
        // 需要一个同等大小的辅助空间
        T* helper = new T[len];
        if(helper != nullptr) {
            mergeSort(array, helper, 0, len-1, min2Max);
        }
        delete[] helper;
    }
private:
    template<typename T>
    static void mergeSort(T src[], T helper[], int begin, int end, bool min2Max = true) {
        if(begin < end) {
            int mid = (begin + end) / 2;
            // 两段归并法
            // 先归并区间<begin, mid>, 再归并区间<mid+1, end
            // 最后两段区间都有序了，再归并两大段，归并为有序
            mergeSort(src, helper, begin, mid, min2Max);
            mergeSort(src, helper, mid+1, end, min2Max);
            mergeSort(src, helper, begin, mid, end, min2Max);
        }
    }

    template<typename T>
    static void mergeSort(T src[], T helper[], int begin, int mid, int end, bool min2Max) {
        int i = begin;     // 代表第一段归并序列的起始
        int j = mid + 1;   // 代表第二段归并序列的起始
        int k = begin;     // 代表辅助空间的起始

        // 遍历比较第一段和第二段归并序列（此时两段已经有序），比较后的值放入辅助空间helper
        while( (i <= mid) && (j <= end) ) {
            if(min2Max ? (src[i] < src[j]) : (src[i] > src[j])) {
                helper[k++] = src[i++];
            } else {
                helper[k++] = src[j++];
            }
        }

        // 第一段归并序列较长的情况，剩下的值全部填入辅助空间helper
        while(i <= mid) {
            helper[k++] = src[i++];
        }

        // 第二段归并序列较长的情况，剩下的值全部填入辅助空间helper
        while(j <= end) {
            helper[k++] = src[j++];
        }

        // 将辅助空间的数值复制到原数组中
        for(i = begin; i <= end; i++) {
            src[i] = helper[i];
        }
    }

private:
    Sort() = default;
    Sort(const Sort&) = default;
    Sort& operator = (const Sort&) = default;
};