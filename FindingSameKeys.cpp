// 2016026762_김민혁

#include <stdio.h>

int N, M;
int keys[200002], newKeys[200002];
int count;
int length;
int newKeysIndex = 1;

void idxSwap(int idxA, int idxB) {
    int temp = keys[idxA];
    keys[idxA] = keys[idxB];
    keys[idxB] = temp;
}

void maxHeapify(int idxNode) {
    if (length < idxNode * 2) {
    }
    else if (length < idxNode * 2 + 1) {
        if (keys[idxNode] < keys[idxNode * 2]) {
            idxSwap(idxNode, idxNode * 2);
            maxHeapify(idxNode * 2);
        }
    }
    else {
        int idxMax = keys[idxNode * 2] > keys[idxNode * 2 + 1] ? idxNode * 2 : idxNode * 2 + 1;
        if (keys[idxNode] < keys[idxMax]) {
            idxSwap(idxNode, idxMax);
            maxHeapify(idxMax);
        }
    }
}

void buildMaxHeap() {
    for (int i = length / 2; i >= 1; i--) {
        maxHeapify(i);
    }
}

int extractMax() {
    int maxValue = keys[1];
    keys[1] = keys[length];
    length--;
    maxHeapify(1);
    return maxValue;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) scanf("%d", &keys[i]);
    for (int i = N + 1; i < N + M + 1; i++) scanf("%d", &keys[i]);

    length = N + M;
    buildMaxHeap();

    for (int i = N + M; i >= 1; i--) {
        newKeys[newKeysIndex++]=extractMax();
    }

    for (int i = 2; i <= N + M; i++) {
        if (newKeys[i - 1] == newKeys[i]) {
            count++;
        }
    }
    printf("%d", count);

    return 0;
}