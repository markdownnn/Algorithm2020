// 2016026762_김민혁

#include <stdio.h>

int N;
int p[101];
int r[101];
int s[101];

void rodCutting() {
	for (int i = 1; i <= N; i++) {
		int maxValue = -1;
		for (int j = 1; j <= i; j++) {
			if (p[j] + r[i - j] > maxValue) {
				maxValue = p[j] + r[i - j];
				s[i] = j;
			}
		}
		r[i] = maxValue;
	}
}

void printAnswer(int num) {
	while (num > 0) {
		printf("%d ", s[num]);
		num -= s[num];
	}
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &p[i]);
	}
	rodCutting();
	printf("%d\n", r[N]);
	printAnswer(N);
	return 0;
}