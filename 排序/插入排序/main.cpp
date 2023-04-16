
#include "insert_sort.hpp"
#include <iostream>

int main() {
    int arr[] = {5,3,2,5,1};
    int len = sizeof(arr) / sizeof(arr[0]);
    Sort::insertSort(arr, len, true);

    for(int val: arr) {
        std::cout << val << std::endl;
    }

    return 0;
}