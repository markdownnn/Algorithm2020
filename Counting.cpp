// 2016026762_김민혁

#include <stdio.h>

int N, M, K;
int keys[100001];
int queryA[100001], queryB[100001];
int insertValue;

int main()
{
    scanf("%d %d %d", &N, &M, &K);

    for (int i = 1; i <= K; i++) {
        scanf("%d %d", &queryA[i], &queryB[i]);
    }

    for (int i = 1; i <= N; i++) {
        scanf("%d", &insertValue);
        keys[insertValue]++;
    }

    for (int i = 1; i <= K; i++) {
        int sum = 0;
        for (int j = queryA[i]; j <= queryB[i]; j++) {
            sum += keys[j];
        }
        printf("%d\n", sum);
    }

    return 0;
}