#define INF 987654321
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
}