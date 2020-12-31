// 2016026762_김민혁

#include <stdio.h>

int N;
int arr[100000];
int arrA[50001], arrB[50001];

void merge(int p, int q, int r) {
    for (int i = 0; i <= q-p; i++) {
        arrA[i] = arr[i + p];
    }
    for (int i = 0; i <= r-q-1; i++) {
        arrB[i] = arr[i + q + 1];
    }
    
    int idxA = 0, idxB = 0, now = 0;
    arrA[q - p + 1] = -10000000;
    arrB[r - q] = -10000000;
    int totalLen = r - p + 1;

    while (now<totalLen) {
        if (arrA[idxA] >= arrB[idxB]) {
            arr[p + now++] = arrA[idxA++];
        } else {
            arr[p + now++] = arrB[idxB++];
        }
    }
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q+1, r);
        merge(p, q, r);
    }
}

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    merge_sort(0, N - 1);
    

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}