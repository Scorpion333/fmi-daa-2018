#include<algorithm>
using namespace std;

template<typename T>
void bubble_sort(T* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        for (unsigned j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);     // You can use std::swap (#include<algorithm>) or write your own swap function
        }
    }
}