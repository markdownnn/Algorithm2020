// 2016026762_±è¹ÎÇõ

#include <stdio.h>
#include <stdlib.h>

int N, M;
int x, y;
int result;

typedef struct _setNode {
    int rank;
    _setNode* p;
} setNode;

setNode* set[1001];

setNode* findSet(setNode* x)
{
    if (x != x->p) x->p = findSet(x->p);
    return x->p;
}

void link(setNode* x, setNode* y)
{
    if (x->rank > y->rank) {
        y->p = x;
    } else {
        x->p = y;
        if (x->rank == y->rank) {
            y->rank = y->rank + 1;
        }
    }
}

void unionSet(setNode* x, setNode* y)
{
    link(findSet(x), findSet(y));
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        set[i] = (setNode*)malloc(sizeof(setNode));
        set[i]->p = set[i];
        set[i]->rank = 0;
    }

    for (int i = 1; i <= M; i++) {
        scanf("%d %d", &x, &y);
        if (findSet(set[x]) != findSet(set[y])) {
            unionSet(set[x], set[y]);
        }
    }

    for (int i = 1; i <= N; i++) {
        if (set[i]->p == set[i]) {
            result++;
        }
    }
    
    printf("%d\n", result);

    return 0;
}