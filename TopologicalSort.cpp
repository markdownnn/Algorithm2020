// 2016026762_±è¹ÎÇõ

#include <stdio.h>
#include <stdlib.h>

int N, M;
int x, y;
int time;
bool hasCycle = false;

int graph[1001][1001];
int visited[1001];
int finish[1001];

void dfs(int vertex, int start) {
	if (!visited[vertex]) {
		visited[vertex] = 1;
		for (int v = 1; v <= N; v++) {
			if (graph[vertex][v]) {
				if (v == start) {
					hasCycle = true;
				}
				if (!visited[v]) {
					dfs(v, start);
				}
			}
		}
		finish[++time] = vertex;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 1; i <= M; i++) {
		scanf("%d %d", &x, &y);
		graph[x][y] = 1;
	}

	for (int i = 1; i <= N; i++) {
		dfs(i, i);
	}

	printf("%d\n", !hasCycle);

	for (int i = N; i >= 1; i--) {
		printf("%d ", finish[i]);
	}
	printf("\n");

	return 0;
}