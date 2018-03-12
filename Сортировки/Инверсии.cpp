#include<iostream>
using namespace std;

template<typename T>
void merge_sort(T* arr, unsigned n, T* helper, unsigned& inv) {
    if (n <= 1)
        return;

    merge_sort(arr, n / 2, helper, inv);
    merge_sort(arr + n / 2, n - n / 2, helper, inv);

    unsigned i_help = 0;
    unsigned i_left = 0;
    unsigned i_right = n / 2;

    while (i_help < n) {
        if (i_right >= n || (i_left < n / 2 && arr[i_left] <= arr[i_right])) {
            helper[i_help] = arr[i_left];
            i_left++;
        }
        else {
            inv += n / 2 - i_left;
            helper[i_help] = arr[i_right];
            i_right++;
        }
        i_help++;
    }
    for (unsigned i = 0; i < n; i++)
        arr[i] = helper[i];
}

int main() {
    unsigned arr[2000000], helper[2000000], n;
    cin >> n;

    for (unsigned i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unsigned inv = 0;
    merge_sort(arr, n, helper, inv);
    cout << inv << '\n';
}