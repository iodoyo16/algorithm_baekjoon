#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<utility>

using namespace std;
typedef pair<int, int> ii;
queue<ii>q;
int map[110][110];
int visited[110][110];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
int n, m;
int bfs() {
	int cnt = 0;
	q.push(ii(1, 1));
	visited[1][1] = 1;
	while (!q.empty()) {
		ii cur = q.front();
		int curx = cur.second;
		int cury = cur.first;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextx = curx + movx[i];
			int nexty = cury + movy[i];
			if (visited[nexty][nextx] != 0 || map[nexty][nextx] == 0)
				continue;
			if (nexty < 1 || n < nexty || nextx < 1 || m < nextx)
				continue;
			q.push(ii(nexty, nextx));
			visited[nexty][nextx] = visited[cury][curx] + 1;
			if (nexty == n && nextx == m)
				return visited[n][m];
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int temp;
			scanf("%1d", &temp);
			map[i][j] = temp;
		}
	}
	int dist = bfs();
	printf("%d\n", dist);
}