#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> ii;
vector<vector<ii> > v;
priority_queue < ii> pq;
int visit[1010];
int dist[1010];
int main() {
	int n, m;
	scanf("%d", &n);
	v.resize(n + 1);
	for (int i = 0; i <= n; i++) {
		visit[i] = 0;
		dist[i] = INF;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		v[v1].push_back(ii(cost,v2));
	}
	int start,dest;
	scanf("%d %d", &start, &dest);
	pq.push(ii(0, start));
	dist[start] = 0;
	while (!pq.empty()) {
		int cur=pq.top().second;
		pq.pop();
		if (visit[cur] == 1)
			continue;
		visit[cur] = 1;
		for (int i = 0; i < v[cur].size(); i++) {
			int cost = v[cur][i].first;
			int next = v[cur][i].second;
			if (dist[next] > dist[cur] + cost) {
				dist[next] = dist[cur] + cost;
				pq.push(ii(-dist[next], next));//dist를 넣어야지 cost를 넣으면 안된다.
				//printf("dist[%d] : %d\n",next,)
			}
		}
	}
	printf("%d\n", dist[dest]);
}