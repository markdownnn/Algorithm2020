// 2016026762_김민혁

#include <stdio.h>

int N;
int p[101];
int m[101][101], s[101][101];

void init() {
	for (int i = 1; i <= N; i++) {
		m[i][i] = 0;
	}
}

void findMin() {
	for (int l = 2; l <= N; l++) {
		for (int i = 1; i <= N - l + 1; i++) {
			int j = i + l - 1;
			m[i][j] = 9999999;
			for (int k = i; k <= j - 1; k++) {
				int min = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (min < m[i][j]) {
					m[i][j] = min;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", m[1][N]);
}

void printOptimalParens(int i, int j) {
	if (i == j) {
		printf("%d ", i);
	}
	else {
		printf("( ");
		printOptimalParens(i, s[i][j]);
		printOptimalParens(s[i][j]+1, j);
		printf(") ");
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	init();
	findMin();
	printOptimalParens(1, N);
	return 0;
}