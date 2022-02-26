#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
vector<vector<int> > v;
queue<int>q;
int visited[110];
int main() {
	int n, m, v1, v2;
	scanf("%d",&n);
	v.resize(n+1);
	scanf("%d %d", &v1, &v2);
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int parent, child;
		scanf("%d %d", &parent, &child);
		v[parent].push_back(child);
		v[child].push_back(parent);
	}
	q.push(v1);
	visited[v1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (visited[next] == 0) {
				q.push(next);
				visited[next] = visited[cur] + 1;
				if (next == v2) {
					printf("%d\n", visited[next] - 1);
					return 0;
				}
			}
		}
	}
	printf("-1");
}