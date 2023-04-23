/*
 *  基本思想：
 *  1. 它重复地走访过要排序的元素列，依次比较两个相邻的元素，如果顺序（如从大到小、首字母从Z到A）错误就把他们交换过来。
 *  2. 走访元素的工作是重复地进行，直到没有相邻元素需要交换，也就是说该元素列已经排序完成。
 */

#include <iostream>

#pragma once

class Sort {
public:
    template <typename T>
    static void bubbleSort(T array[], int len, bool min2Max = true) {
        // 引入exchange来标记是否需要排序，避免不必要的排序（即已经有序）
        bool exchange = true;
        for(int i = 0; (i < len) && exchange; i++) {
            exchange = false;
            for(int j = len-1; j > i; j--) {
                if(min2Max ? (array[j] < array[j-1]) : (array[j] > array[j-1])) {
                    exchange = true;
                    swap(array[j], array[j-1]);
                }
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