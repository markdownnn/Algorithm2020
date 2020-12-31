// 2016026762_김민혁

#include <stdio.h>

int keys[1000000];
int length;
int isOver, command;

void idxSwap(int idxA, int idxB) {
    int temp = keys[idxA];
    keys[idxA] = keys[idxB];
    keys[idxB] = temp;
}

void maxHeapifyTopDown(int idxNode) {
    if (length < idxNode * 2) {
    }
    else if (length < idxNode * 2 + 1) {
        if (keys[idxNode] < keys[idxNode * 2]) {
            idxSwap(idxNode, idxNode * 2);
            maxHeapifyTopDown(idxNode * 2);
        }
    }
    else {
        int idxMax = keys[idxNode * 2] > keys[idxNode * 2 + 1] ? idxNode * 2 : idxNode * 2 + 1;
        if (keys[idxNode] < keys[idxMax]) {
            idxSwap(idxNode, idxMax);
            maxHeapifyTopDown(idxMax);
        }
    }
}

void maxHeapifyBottomUp(int idxNode) {
    if (idxNode == 1) return;
    if (keys[idxNode] > keys[idxNode / 2]) {
        idxSwap(idxNode, idxNode / 2);
        maxHeapifyBottomUp(idxNode / 2);
    }
}

int extractMax() {
    int maxValue = keys[1];
    keys[1] = keys[length];
    length--;
    maxHeapifyTopDown(1);
    return maxValue;
}

void heapChangeKey(int i, int k) {
    keys[i] = k;
    maxHeapifyTopDown(i);
    maxHeapifyBottomUp(i);
}

void printAll() {
    for (int i = 1; i <= length; i++) {
        printf("%d ", keys[i]);
    }
}

int main()
{
    while (!isOver) {
        scanf("%d", &command);
        int insertValue = 0, insertIndex = 0;
        switch (command) {
            case 0:
                printAll();
                isOver = 1;
                break;
            case 1:
                scanf("%d", &insertValue);
                heapChangeKey(++length, insertValue);
                break;
            case 2:
                printf("%d ", extractMax());
                break;
            case 3:
                scanf("%d %d", &insertIndex, &insertValue);
                heapChangeKey(insertIndex, insertValue);
                break;
        }
    }

    return 0;
}