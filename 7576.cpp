#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;

int map[1010][1010];
typedef pair<int, int> ii;
vector<ii>v;
queue<ii>q;
int visited[1010][1010];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
int main() {
	int n, m,tomato_num=0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) {
				q.push(ii(i, j));
				visited[i][j] = 1;
			}
			if (map[i][j] != -1) {
				tomato_num++;
			}
		}
	}
	int cnt = 0;
	int maxday = 0;
	while (!q.empty()) {
		int cury=q.front().first;
		int curx = q.front().second;
		q.pop();
		cnt++;
		maxday = visited[cury][curx] > maxday ? visited[cury][curx] : maxday;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + movy[i];
			int nextx = curx + movx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
				continue;
			if (visited[nexty][nextx] == 0 && map[nexty][nextx] == 0) {
				map[nexty][nextx] = 1;
				visited[nexty][nextx] = visited[cury][curx] + 1;
				q.push(ii(nexty, nextx));
			}
		}
	}
	if (cnt < tomato_num) {
		printf("-1\n");
	}
	else {
		printf("%d\n",maxday-1);
	}
}