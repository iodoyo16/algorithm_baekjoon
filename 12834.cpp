#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;
typedef pair<int, int> ii;
vector<vector<ii> > v;
priority_queue<ii>pq;
int visit[1010];
int dist[1010];
int start[101];
int main() {
	int n, v_num, e_num;
	scanf("%d %d %d", &n, &v_num, &e_num);
	v.resize(v_num + 1);
	int dest1, dest2;
	long long ans=0;
	scanf("%d %d", &dest1, &dest2);
	for (int i = 0; i < n; i++) {
		scanf("%d", &start[i]);
	}
	for (int i = 0; i < e_num; i++) {
		int v1, v2, cost;
		scanf("%d %d %d",&v1,&v2,&cost);
		v[v1].push_back(ii(cost, v2));
		v[v2].push_back(ii(cost, v1)); // 양방향 그래프였다...
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= v_num; j++) {
			dist[j] = INF;
			visit[j] = 0;
		}
		dist[start[i]] = 0;
		pq.push(ii(0, start[i]));
		while (!pq.empty()) {
			int cur = pq.top().second;
			pq.pop();
			if (visit[cur] == 1)
				continue;
			visit[cur] = 1;
			for (int k = 0; k < v[cur].size(); k++) {
				int cost = v[cur][k].first;
				int next = v[cur][k].second;
				if (dist[next] > dist[cur] + cost) {
					dist[next] = dist[cur] + cost;
					pq.push(ii(-dist[next], next));
				}
			}
		}
		ans+= dist[dest1] == INF ? -1 : dist[dest1];
		ans+= dist[dest2] == INF ? -1 : dist[dest2];
	}
	printf("%lld\n", ans);
}