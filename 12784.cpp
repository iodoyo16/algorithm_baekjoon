#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int visit[1010];
typedef pair<int, int> ii;
vector<vector<ii> > v;

int dfs(int curnode) {
	visit[curnode] = 1;
	if (v[curnode].size() == 1 && curnode != 1)
		return INF;
	int min_num=0;
	for (int i = 0; i < v[curnode].size(); i++) {
		int next = v[curnode][i].first;
		int cost = v[curnode][i].second;
		if (visit[next] == 1)
			continue;
		min_num += min(cost, dfs(next));
	}
	return min_num;
}
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d %d", &n, &m);
		v.resize(n + 1);
		for (int i = 0; i <= n; i++)
			visit[i] = 0;
		for (int i = 0; i < m; i++) {
			int v1, v2, cost;
			scanf("%d %d %d",&v1,&v2,&cost);
			v[v1].push_back(ii(v2, cost));
			v[v2].push_back(ii(v1, cost));
		}
		printf("%d\n", dfs(1));
		for (int i = 0; i <= n; i++)
			v[i].clear();
	}
}