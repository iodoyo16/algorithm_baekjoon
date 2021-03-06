#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int>ii;
vector<vector<ii> > v;
priority_queue<ii>pq;
int visit[1010];
int main() {
	int n, m,cnt=0,ans=0;
	scanf("%d", &n);
	v.resize(n + 1);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		v[v1].push_back(ii(cost, v2));
		v[v2].push_back(ii(cost, v1));
	}
	cnt++;
	visit[1] = 1;
	for (int i = 0; i < v[1].size(); i++) {
		int next = v[1][i].second;
		int cost = v[1][i].first;
		pq.push(ii(-cost, next));
	}
	while(cnt<n){
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visit[cur] == 1)
			continue;
		visit[cur] = 1;
		cnt++;
		ans += cost;
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i].second;
			int ncost = v[cur][i].first;
			pq.push(ii(-ncost,next));
		}
	}
	printf("%d", -ans);
}
/*
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int parent[1010];
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector< iii> ve;
int Find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x]=Find(parent[x]);
}
void Union(int x, int y) {
	parent[parent[x]] = parent[y];
}
int main() {
	int n, m, cnt = 0, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		scanf("%d %d %d", &u, &v, &cost);
		ve.push_back(iii(cost,ii(u,v)));
	}
	sort(ve.begin(), ve.end());
	for (int i = 0; i < m; i++) {
		int v1 = ve[i].second.first;
		int v2 = ve[i].second.second;
		int cost = ve[i].first;
		if (Find(v1) != Find(v2)) {
			Union(v1, v2);
			ans += cost;
		}
	}
	printf("%d\n",ans);
}*/
/*
typedef pair<int, int> ii;
vector<vector <ii> > vv;
priority_queue<ii>pq;
int visited[1010];
int main() {
	int n, m,cnt=0,ans=0;
	scanf("%d", &n);
	scanf("%d", &m);
	vv.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		scanf("%d %d %d", &u,&v,&cost);
		vv[u].push_back(ii(-cost, v));
		vv[v].push_back(ii(-cost, u));
	}
	int st = 1;
	visited[st] = 1;
	cnt++;
	for (int i = 0; i < vv[st].size(); i++) {
		int next = vv[st][i].second;
		int cost = vv[st][i].first;
		pq.push(ii(cost,next));
	}
	while (cnt<n) {
		int next = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (visited[next] != 0)
			continue;
		visited[next] = 1;
		cnt++;
		ans += cost;
		for (int i = 0; i < vv[next].size(); i++) {
			pq.push(vv[next][i]);
		}
	}
	printf("%d\n", -ans);
}*/