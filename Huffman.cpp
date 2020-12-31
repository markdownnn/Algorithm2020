// 2016026762_±è¹ÎÇõ

#include <stdio.h>

int N, total;
int length;

typedef struct _node {
	char key[5];
	int freq;
	int sum;
	struct _node* left;
	struct _node* right;
} node;

node nodeHeap[30001];
node newNodeHeap[60001];

int result = 0;

void search(node* searchFrom, int level) {
	if (searchFrom->sum != 1) {
		result += searchFrom->freq * level;
	}
	if (searchFrom->left != NULL) {
		search(searchFrom->left, level+1);
	}
	if (searchFrom->right != NULL) {
		search(searchFrom->right, level+1);
	}
}

void idxSwap(int idxA, int idxB) {
	node temp = nodeHeap[idxA];
	nodeHeap[idxA] = nodeHeap[idxB];
	nodeHeap[idxB] = temp;
}

void minHeapifyTopDown(int idxNode) {
	if (length < idxNode * 2) {
	}
	else if (length < idxNode * 2 + 1) {
		if (nodeHeap[idxNode].freq > nodeHeap[idxNode * 2].freq) {
			idxSwap(idxNode, idxNode * 2);
			minHeapifyTopDown(idxNode * 2);
		}
	}
	else {
		int idxMin = nodeHeap[idxNode * 2].freq < nodeHeap[idxNode * 2 + 1].freq ? idxNode * 2 : idxNode * 2 + 1;
		if (nodeHeap[idxNode].freq > nodeHeap[idxMin].freq) {
			idxSwap(idxNode, idxMin);
			minHeapifyTopDown(idxMin);
		}
	}
}

void minHeapifyBottomUp(int idxNode) {
	if (idxNode == 1) return;
	if (nodeHeap[idxNode].freq < nodeHeap[idxNode / 2].freq) {
		idxSwap(idxNode, idxNode / 2);
		minHeapifyBottomUp(idxNode / 2);
	}
}

void buildMinHeap() {
	for (int i = length / 2; i >= 1; i--) {
		minHeapifyTopDown(i);
	}
}

node extractMin() {
	node minNode = nodeHeap[1];
	nodeHeap[1] = nodeHeap[length];
	length--;
	minHeapifyTopDown(1);
	return minNode;
}

void heapInsert(node newNode) {
	nodeHeap[++length] = newNode;
	minHeapifyTopDown(length);
	minHeapifyBottomUp(length);
}

int findFixedLength(int N) {
	int n = N - 1, fixedLength = 0;
	if (n == 0) return 1;
	for (; n > 0; n /= 2) {
		fixedLength++;
	}
	return fixedLength;
}

node huffman()
{
	int nodeIndex = 0;
	for (int i = 1; i < N; i++) {
		newNodeHeap[nodeIndex] = extractMin();
		newNodeHeap[nodeIndex+1] = extractMin();
		node z = { "sum", newNodeHeap[nodeIndex].freq + newNodeHeap[nodeIndex+1].freq, 1, &newNodeHeap[nodeIndex], &newNodeHeap[nodeIndex + 1] };
		heapInsert(z);
		nodeIndex += 2;
	}
	return extractMin();
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%s", &nodeHeap[i].key);
		scanf("%d", &nodeHeap[i].freq);
	}
	scanf("%d", &total);

	printf("%d\n", findFixedLength(N)*total);

	length = N;

	buildMinHeap();
	
	node root = huffman();
	search(&root, 0);

	printf("%d\n", result);

	return 0;
}