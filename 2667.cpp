#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
typedef pair<int, int> ii;
vector<int >v;
queue<ii>q;
int map[30][30];
int visited[30][30];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
int cntarr[900];
int n,ans=0;
int bfs(int y,int x) {
	int cnt = 0;
	q.push(ii(y, x));
	visited[y][x] = ans+1;
	while (!q.empty()) {
		int curx = q.front().second;
		int cury = q.front().first;
		cnt++;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nexty = cury + movy[i];
			int nextx = curx + movx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= n)
				continue;
			if (map[nexty][nextx] == 1 && visited[nexty][nextx] == 0) {
				q.push(ii(nexty, nextx));
				visited[nexty][nextx] = ans+1;
			}
		}
	}
	return cnt;
}
int main() {
	scanf("%d",&n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d", &map[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (map[i][j] == 1 && visited[i][j] == 0) {
				int cnt=bfs(i, j);
				v.push_back(cnt);
				ans++;
			}
		}
	}
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d", visited[i][j]);
		}
		printf("\n");
	}
	*/

	printf("%d\n", ans);
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}
}
