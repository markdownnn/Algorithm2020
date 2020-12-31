// 2016026762_김민혁

#include <stdio.h>

int N;
int e1, e2, x1, x2;
int a[2][101];
int t[2][101];
int s[2][101];
int l[2][101];
int fastestTime, fastestWay;

void fastestAssembly() {
	s[0][1] = e1 + a[0][1];
	s[1][1] = e2 + a[1][1];
	for (int i = 2; i <= N; i++) {
		if (s[0][i - 1] <= s[1][i - 1] + t[1][i - 1]) {
			s[0][i] = s[0][i - 1] + a[0][i];
			l[0][i] = 0;
		}
		else {
			s[0][i] = s[1][i - 1] + t[1][i - 1] + a[0][i];
			l[0][i] = 1;
		}
		if (s[1][i - 1] <= s[0][i - 1] + t[0][i - 1]) {
			s[1][i] = s[1][i - 1] + a[1][i];
			l[1][i] = 1;
		}
		else {
			s[1][i] = s[0][i - 1] + t[0][i - 1] + a[1][i];
			l[1][i] = 0;
		}
	}
	if (s[0][N] + x1 <= s[1][N] + x2) {
		fastestTime = s[0][N] + x1;
		fastestWay = 0;
	}
	else {
		fastestTime = s[1][N] + x2;
		fastestWay = 1;
	}
}

void printFastestWay(int line, int station) {
	if (station < 1) return;
	printFastestWay(l[line][station], station - 1);
	printf("%d %d\n", line + 1, station);
}

int main()
{
	scanf("%d", &N);
	scanf("%d %d", &e1, &e2);
	scanf("%d %d", &x1, &x2);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[0][i]);
	}
	for (int i = 1; i <= N; i++) {
		scanf("%d", &a[1][i]);
	}
	for (int i = 1; i <= N-1; i++) {
		scanf("%d", &t[0][i]);
	}
	for (int i = 1; i <= N-1; i++) {
		scanf("%d", &t[1][i]);
	}
	fastestAssembly();
	printf("%d\n", fastestTime);
	printFastestWay(fastestWay, N);
	return 0;
}