#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
#pragma warning(disable:4996)
using namespace std;
vector<vector<int> >ve;
int visit[1010];
void dfs(int n);
void bfs(int n);
int main()
{
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);
	ve.resize(n + 1);
	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		ve[s].push_back(e);
		ve[e].push_back(s);
	}
	for (int i = 1; i <= n; i++) {
		sort(ve[i].begin(), ve[i].end());
	}
	dfs(v);
	printf("\n");
	for (int i = 0; i <= n; i++)visit[i] = 0;
	bfs(v);

}
void dfs(int n) {
	visit[n] = 1;
	printf("%d ", n);
	for (int i = 0; i < ve[n].size(); i++) {
		if (visit[ve[n][i]] == 0)
			dfs(ve[n][i]);
	}
}
void bfs(int n) {
	queue<int>q;
	q.push(n);
	visit[n] = 1;
	while (!q.empty()) {
		int temp = q.front();
		printf("%d ", temp);
		q.pop();
		for (int i = 0; i < ve[temp].size(); i++) {
			if (visit[ve[temp][i]] == 0) {
				visit[ve[temp][i]] = 1;
				q.push(ve[temp][i]);
			}
		}
	}
}