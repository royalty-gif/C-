
#include "shell.hpp"
#include <iostream>

int main() {
    int arr[] = {5,3,2,5,1, 4,2,9,3,5};
    int len = sizeof(arr) / sizeof(arr[0]);
    Sort::shellSort(arr, len, false);

    for(int val: arr) {
        std::cout << val << std::endl;
    }

    return 0;
}