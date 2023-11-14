#include "heap_sort.hpp"
#include <iostream>
#include <memory>

using namespace std;
int main() {
    int arr[] = {3,2,4,6,4,8,6,5,1,6};
    int len = sizeof(arr)/sizeof(arr[0]);
    //Sort::heapSortRecursive<int>(arr, len, true);
    Sort::heapSort<int>(arr, len, false);
    for(int i = 0; i < len; i++) {
        cout << arr[i] << endl;
    }
}