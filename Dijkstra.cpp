// 2016026762_±è¹ÎÇõ

#include <stdio.h>
#include <bits/stdc++.h>

#define INF 9999999

using namespace std;

int N, M;
int x, y, w;
int dist[5001];
int result;

list< pair<int, int> >* adjList;
priority_queue< pair<int, int> > q;

void relax(int from, int* to, int v, int w)
{
    if (*to > from + w) {
        *to = from + w;
        q.push(make_pair(v, dist[v]));
    }
}

void Dijkstra()
{
    q.push(make_pair(1, 0));

    dist[1] = 0;
    for (int i = 2; i <= N; i++) {
        dist[i] = INF;
    }

    while (!q.empty())
    {
        int u = q.top().first;
        q.pop();

        for (list<pair<int,int>>::iterator i = adjList[u].begin(); i != adjList[u].end(); i++)
        {
            relax(dist[u], &dist[(*i).first], (*i).first, (*i).second);
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    adjList = new list<pair<int,int>>[N+1];

    for (int i = 1; i <= M; i++) {
        scanf("%d %d %d", &x, &y, &w);
        adjList[x].push_back(make_pair(y, w));
    }

    Dijkstra();

    for (int i = 1; i <= N; i++) {
        if (dist[i] > result) {
            result = dist[i];
        }
    }
    printf("%d", result);

    return 0;
}