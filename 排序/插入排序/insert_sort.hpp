/*
 * 基本思想：
 * 1. 将一个记录插入到已经排好序的有序表中，从而一个新的、记录数增1的有序表。
 * 2. 在其实现过程使用双层循环，外层循环对除了第一个元素之外的所有元素，内层循环对当前元素前面有序表进行待插入位置查找，并进行移动
 * @note：插入排序是稳定的排序方法
 * @note：对于少量元素的排序，它是一个有效的算法
*/

#include <iostream>

#pragma once

class Sort {
public:
    template<typename T>
    static void insertSort(T array[], int len, bool min2Max = true) {
        for(int i = 1; i < len; i++) {
            int k = i;
            T val = array[i];

            for(int j = i-1; (j >= 0) && (min2Max ? (array[j] > val) : (array[j] < val)); j--) {
                array[j+1] = array[j];
                k = j;
            }

            if(k != i) {
                array[k] = val;
            }
        }
    }
private:
    Sort() = default;
    Sort(const Sort&) = default;
    Sort& operator = (const Sort&) = default;

};