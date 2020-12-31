// 2016026762_김민혁

#include <stdio.h>

int N;
int arr[30000];

int main()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i < N; i++) {
        int key = arr[i];
        for (int j = i-1; j >= 0; j--) {
            if (key > arr[j]) {
                arr[j + 1] = arr[j];
                if (j == 0) {
                    arr[0] = key;
                }
            } else {
                arr[j + 1] = key;
                break;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}