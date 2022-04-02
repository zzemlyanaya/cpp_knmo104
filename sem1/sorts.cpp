//
// Cr
// eated by zzemlyanaya on 02.04.2022.
//
void merge_sort(Vec* list, int n) {
    if (n == 1) return;

    int halfLen = n/2 + n%2;

    merge_sort(list, halfLen);
    merge_sort(list + halfLen, halfLen);

    for (int i = 0; i < halfLen; ++i) {
        if (list[i].by_y > list[i + halfLen].by_y) {
            Vec temp = list[i];
            list[i] = list[i + halfLen];
            list[i + halfLen] = temp;
        }
    }
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void quickSort(int* arr, int left, int right) {
    int i = left, j = right;
    int mid = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < mid) i++;
        while (arr[j] > mid) j--;

        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    }
    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}
