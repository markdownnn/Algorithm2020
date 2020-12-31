// 2016026762_±è¹ÎÇõ

#include <stdio.h>
#include <stdlib.h>

int N, M;
int x, y, w;
int length;
int result;

typedef struct _edge {
	int x;
	int y;
	int w;
} edge;

edge* edges;
edge* resultEdges;

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
	}
	else {
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

void swap(int idxA, int idxB) {
	edge temp = edges[idxB];
	edges[idxB] = edges[idxA];
	edges[idxA] = temp;
}

void minHeapify(int idxNode) {
	if (length < idxNode * 2) {
	}
	else if (length < idxNode * 2 + 1) {
		if (edges[idxNode].w > edges[idxNode * 2].w) {
			swap(idxNode, idxNode * 2);
			minHeapify(idxNode * 2);
		}
		else if (edges[idxNode].w == edges[idxNode * 2].w) {
			if ((edges[idxNode].x > edges[idxNode * 2].x) || (edges[idxNode].x == edges[idxNode * 2].x && edges[idxNode].y > edges[idxNode * 2].y)) {
				swap(idxNode, idxNode * 2);
				minHeapify(idxNode * 2);
			}
		}
	}
	else {
		int idxMin = 0;
		if (edges[idxNode * 2].w < edges[idxNode * 2 + 1].w) {
			idxMin = idxNode * 2;
		}
		else if (edges[idxNode * 2].w > edges[idxNode * 2 + 1].w) {
			idxMin = idxNode * 2 + 1;
		}
		else {
			if ((edges[idxNode * 2].x < edges[idxNode * 2 + 1].x) || (edges[idxNode * 2].x == edges[idxNode * 2 + 1].x && edges[idxNode * 2].y < edges[idxNode * 2 + 1].y)) {
				idxMin = idxNode * 2;
			}
			else
			{
				idxMin = idxNode * 2 + 1;
			}
		}
		if (edges[idxNode].w > edges[idxMin].w) {
			swap(idxNode, idxMin);
			minHeapify(idxMin);
		}
		else if (edges[idxNode].w == edges[idxMin].w) {
			if ((edges[idxNode].x > edges[idxMin].x) || (edges[idxNode].x == edges[idxMin].x && edges[idxNode].y > edges[idxMin].y)) {
				swap(idxNode, idxMin);
				minHeapify(idxMin);
			}
		}
	}
}

void buildMinHeap() {
	for (int i = length / 2; i >= 1; i--) {
		minHeapify(i);
	}
}

edge extractMin() {
	edge minValue = edges[1];
	edges[1] = edges[length];
	length--;
	minHeapify(1);
	return minValue;
}

int main()
{
	scanf("%d %d", &N, &M);
	edges = (edge*)malloc(sizeof(edge) * (M + 1));
	resultEdges = (edge*)malloc(sizeof(edge) * (M + 1));

	length = M;

	for (int i = 1; i <= N; i++) {
		set[i] = (setNode*)malloc(sizeof(setNode));
		set[i]->p = set[i];
		set[i]->rank = 0;
	}

	for (int i = 1; i <= M; i++) {
		scanf("%d %d %d", &x, &y, &w);
		if (x > y) {
			int temp = y;
			y = x;
			x = temp;
		}
		edges[i].x = x;
		edges[i].y = y;
		edges[i].w = w;
	}

	buildMinHeap();
	
	for (int i = 1; i <= M; i++) {
		edge temp = extractMin();
		if (findSet(set[temp.x]) != findSet(set[temp.y])) {
			unionSet(set[temp.x], set[temp.y]);
			result++;
			resultEdges[result] = temp;
		}
	}

	printf("%d\n", result);

	for (int i = 1; i <= result; i++) {
		printf("%d %d %d\n", resultEdges[i].x, resultEdges[i].y, resultEdges[i].w);
	}

	return 0;
}