template<typename T>
void insertion_sort(T* arr, unsigned n) {
    for (unsigned i = 1; i < n; i++) {
        T inserted_value = arr[i];
        unsigned j = 0;
        while (j < i && arr[j] <= inserted_value) {
            j++;
        }
        // Now j is either i, or the first position (pos.) with value > arr[i] before pos.i
        // We'll shift all the values from pos.j to pos.i-1 (they go to pos. from j+1 to i) and we'll put inserted_value on pos.j
        // We do the shift 'the reverse way'. Why? Think and try the other way...

        for (unsigned k = i; k > j; k--) {      // 'unsigned' is ok as j >= 0
            arr[k] = arr[k - 1];
        }
        arr[j] = inserted_value;
    }
}