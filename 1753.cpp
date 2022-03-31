/*#define INF 987654321
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

typedef pair<int, int> ii;
vector<vector<ii> >ve;
priority_queue<ii> pq;
int visit[20010];
int dist[20010];

int main() {
	int v, e,start;
	cin >> v >> e;
	ve.resize(v + 1);
	cin >> start;
	for (int i = 0; i <= v; i++)
		dist[i] = INF;
	for (int i = 0; i < e; i++) {
		int v1, v2,cost;
		cin >> v1 >> v2 >> cost;
		ve[v1].push_back(ii(cost, v2));
	}
	dist[start] = 0;
	pq.push(ii(0, start));
	while (!pq.empty()) {
		int curnode = pq.top().second;
		pq.pop();
		if (visit[curnode] == 1)
			continue;
		visit[curnode] = 1;
		for (int i = 0; i < ve[curnode].size(); i++) {
			int next=ve[curnode][i].second;
			int cost = ve[curnode][i].first;
			if (dist[next] > dist[curnode] + cost) {
				dist[next] = dist[curnode] + cost;
				pq.push(ii(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
}*/
#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int, int> ii;
vector<vector<ii> > ve;
priority_queue<ii> pq;
int dist [20010];
int visit[20010];
int main() {
	int v, e,st;
	scanf("%d %d", &v, &e);
	ve.resize(v + 1);
	scanf("%d", &st);
	for (int i = 0; i < e; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		ve[v1].push_back(ii(cost, v2));
	}
	for (int i = 0; i <= v; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;
	pq.push(ii(0, st));
	while (!pq.empty()) {
		int cur = pq.top().second;
		pq.pop();
		if (visit[cur] == 1)
			continue;
		visit[cur] = 1;
		for (int i = 0; i < ve[cur].size(); i++) {
			int cost = ve[cur][i].first;
			int next = ve[cur][i].second;
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push(ii(-dist[next], next));
			}
		}
	}
	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			printf("INF\N");
		else
			printf("%d\n", dist[i]);
	}
	return 0;
}