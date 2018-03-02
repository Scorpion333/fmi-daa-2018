#include<algorithm>
using namespace std;

template<typename T>
void selection_sort(T* arr, unsigned n) {
    for (unsigned i = 0; i < n; i++) {            // Can we write i < n-1 ?
        for (unsigned j = i + 1; j < n; j++) {
            if (arr[i] > arr[j])
                swap(arr[i], arr[j]);       // You can use std::swap (#include<algorithm>) or write your own swap function
        }
    }
}