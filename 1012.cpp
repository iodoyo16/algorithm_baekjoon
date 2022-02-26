#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<utility>

using namespace std;
int map[55][55];
int visited[55][55];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
typedef pair <int, int> ii;

int main() {
	int t;
	int m, n, k;
	scanf("%d",&t);
	while (t--) {
		int cnt = 0;
		queue<ii>q;
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				visited[i][j] = 0;
				map[i][j] = 0;
			}
		}
		for (int i = 0; i < k; i++) {
			int y, x;
			scanf("%d %d", &x, &y);
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1 && visited[i][j] == 0) {
					cnt++;
					q.push(ii(i, j));
					visited[i][j] = 1;
					while (!q.empty()) {
						int curx = q.front().second;
						int cury = q.front().first;
						q.pop();
						for (int i = 0; i < 4; i++) {
							int nexty = cury + movy[i];
							int nextx = curx + movx[i];
							if (nexty < 0 | nexty >= n || nextx < 0 || nextx >= m)
								continue;
							if (map[nexty][nextx] == 1 && visited[nexty][nextx] == 0) {
								q.push(ii(nexty, nextx));
								visited[nexty][nextx] = 1;
							}
						}
					}
				}
			}
		}
		printf("%d\n", cnt);
	}
}