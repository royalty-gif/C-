/*
 *  基本思想：
 *  1. 首先设定一个分界值，通过该分界值将数组分成左右两部分。
 *  2. 将大于或等于分界值的数据集中到数组右边，小于分界值的数据集中到数组的左边
 *  3. 然后，左边和右边的数据可以独立排序。对于左侧的数组数据，又可以取一个分界值，将该部分数据分成左右两部分
 *  4. 重复上述过程，可以看出，这是一个递归定义。通过递归将左侧部分排好序后，再递归排好右侧部分的顺序。当左、右两个部分各数据排序完成后，整个数组的排序也就完成了
 *  @note：递归算法
 */

#include <iostream>

#pragma once

class Sort {
public:
    template <typename T>
    static void quickSort(T array[], int len, bool min2Max = true) {
        quickSort(array, 0, len-1, min2Max);
    }

private:
    template <typename T>
    static void quickSort(T array[], int begin, int end, bool min2Max) {
        if(begin < end) {
            int pivot = partition(array, begin, end, min2Max);

            // 对左边和右边元素进行快速排序
            quickSort(array, begin, pivot-1, min2Max);
            quickSort(array, pivot+1, end, min2Max);
        }
    }

    // 分割
    // 这个过程之后，选取的分割值就位于正确的位置
    template<typename T>
    static int partition(T array[], int begin, int end, bool min2Max) {
        T pv = array[begin];

        while(begin < end) {
            while( (begin < end) && (min2Max ? (array[end] > pv) : (pv > array[end])) ) {
                end--;
            }
            swap(array[begin], array[end]);

            while( (begin < end) && (min2Max ? (array[begin] <= pv) : (pv <= array[begin])) ) {
                begin++;
            }
            swap(array[begin], array[end]);
        }

        array[begin] = pv;

        return begin;
    }

private:
    Sort() = default;
    Sort(const Sort&) = default;
    Sort& operator = (const Sort&) = default;

    template<typename T>
    static void swap(T& a, T& b) {
        T tmp(std::move(a));
        a = std::move(b);
        b = std::move(tmp);
    }
};