#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int map[1010][1010];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
bool visit[1010][1010];

bool bfs(int slope,int n) {
	queue<pair<int, int > > q;
	visit[1][1] = true;
	q.push(make_pair(1,1));
	while (!q.empty()) {
		int curx = q.front().second;
		int cury = q.front().first;
		q.pop();
		if (cury == n && curx == n)
			return true;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + movy[i];
			int nextx = curx + movx[i];
			if (nexty<=0 || nexty>n || nextx<=0 || nextx>n)
				continue;
			if (visit[nexty][nextx])
				continue;
			if (abs(map[nexty][nextx] - map[cury][curx]) > slope)
				continue;
			visit[nexty][nextx] = true;
			q.push(make_pair(nexty, nextx));
		}
	}
	return false;
}

int main() {
	int map_size;
	scanf("%d", &map_size);
	for (int i = 1; i <= map_size; i++) {
		for (int j = 1; j <= map_size; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	int min_slope = 0, max_slope = 999999999;
	int ans=0;
	while (min_slope <= max_slope) {
		int mid_slope = (min_slope + max_slope) / 2;
		for (int i = 1; i <= map_size; i++) {
			for (int j = 1; j <= map_size; j++) {
				visit[i][j] = false;
			}
		}
		bool ok=bfs(mid_slope,map_size);
		if (ok) {
			max_slope = mid_slope - 1;
			ans = mid_slope;
		}
		else
			min_slope = mid_slope + 1;
	}
	printf("%d\n", ans);
}