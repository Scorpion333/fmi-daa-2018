#include<algorithm>
using namespace std;

template<typename T>
unsigned partition(T* a, unsigned left, unsigned right) {

    unsigned pivot_index = left + (right-left)/2;
    T pivot = a[pivot_index];

    swap(a[left], a[pivot_index]);      // You can use std::swap (#include<algorithm>) or write your own swap function
    pivot_index = left;

    for (unsigned i = left + 1; i < right; i++) {
        if (a[i] <= pivot) {
            pivot_index++;
            swap(a[i], a[pivot_index]);
        }
    }
    swap(a[left], a[pivot_index]);
    return pivot_index;
}

template<typename T>
void quick_sort(T* arr, unsigned left, unsigned right) {
    if (right - left <= 1) {
        return;
    }
    unsigned pivot_index = partition(arr, left, right);
    quick_sort(arr, left, pivot_index);
    quick_sort(arr, pivot_index + 1, right);
}