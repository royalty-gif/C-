/*
 * 堆的定义：
 * 1. 在一棵完全二叉树中，每一棵子树的根节点值均大于或小于其左右子树的所有根节点值，被称为堆。
 * 2. 其中每一棵子树的根节点值均大于左右子树的节点时，这棵树被称为大顶堆，反之，被称为小顶堆
 */

#include <iostream>

#pragma once

class Sort {
public:
    // 递归实现
    template <typename T>
    static void heapSortRecursive(T arr[], int n, bool min2Max = true) {
        // 建立初始堆，从最后一个非叶子结点开始向上遍历
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i, min2Max);
        }

        // 不断取出堆顶元素并重新堆化，直到堆为空
        for (int i = n - 1; i >= 0; i--) {
            swap(arr[0], arr[i]); // 将当前最大值移至数组末尾
            heapify(arr, i, 0, min2Max); // 对剩余元素继续堆化
        }
    }

    // 非递归实现
    template<typename T>
    static void heapSort(T arr[], int n, bool min2Max = true) {

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

private:
    template<typename T>
    static void heapify(T arr[], int n, int i, bool min2Max) {
        int largest = i; // 记录根结点的位置
        int left = 2 * i + 1; // 左孩子结点在数组中的位置
        int right = 2 * i + 2; // 右孩子结点在数组中的位置

        // 寻找左右孩子中最大的那个结点
        if (left < n && compare(arr[left], arr[largest], min2Max)) {
            largest = left;
        }
        if (right < n && compare(arr[right], arr[largest], min2Max)) {
            largest = right;
        }

        // 如果最大的结点不是根结点，则交换它们的值，并递归调用堆化函数
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest, min2Max);
        }
    }

    template<typename T>
    static bool compare(const T& lv, const T& rv, bool min2Max) {
        return min2Max ? (lv > rv) : (lv < rv);
    }

private:

};