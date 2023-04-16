/*
 * 基本思想：
 * 1. 第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置
 * 2. 然后再从剩余的未排序元素中寻找到最小（大）元素，然后放到已排序的序列的末尾。
 * 3. 以此类推，直到全部待排序的数据元素的个数为零。
 * @note：选择排序是不稳定的排序方法。
*/

#include <iostream>

#pragma once

class Sort {
public:
    template<typename T>
    static void selectSort(T array[], int len, bool min2Max = true) {
        for(int i = 0; i < len; i++) {
            int recordNum = i; // 记录最大或最小值
            for(int j = i+1; j < len; j++) {
                if( min2Max ? (array[recordNum] > array[j]) : array[recordNum] < array[j]) {
                    recordNum = j;
                }
            }

            // 避免不必要的交换
            if(recordNum != i) {
                swap(array[i], array[recordNum]);
            }
        }
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