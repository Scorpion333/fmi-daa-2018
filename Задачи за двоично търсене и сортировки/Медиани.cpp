#include<iostream>
#include<cstdio>
using namespace std;

double median(unsigned* arr, unsigned n) {
    return double(arr[n / 2] + arr[(n - 1) / 2]) / 2;       // Interesting way, works for every n.
}

template<typename T>
void insertion_sort(T* arr, unsigned n) {
    for (unsigned i = 1; i < n; i++) {
        printf("%.1f ", median(arr, i));

        T inserted_value = arr[i];
        unsigned j = 0;
        while (j < i && arr[j] <= inserted_value) {
            j++;
        }
        for (unsigned k = i; k > j; k--) {
            arr[k] = arr[k - 1];
        }
        arr[j] = inserted_value;
    }
    printf("%.1f\n", median(arr, n));
}

int main() {
    ios::sync_with_stdio(false);

    unsigned n, arr[10000];
    cin >> n;

    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }
    insertion_sort(arr, n);
}