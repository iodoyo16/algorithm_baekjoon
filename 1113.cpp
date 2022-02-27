#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

typedef pair<int, int> ii;

int map[55][55];
int visited[55][55];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
int n, m;
int bfs(int y,int x) {
	int cnt = 0;
	queue<ii>q;
	q.push(ii(y, x));			  
	visited[y][x] = 1;
	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + movy[i];
			int nextx = curx + movx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
				continue;
			if (visited[nexty][nextx] == 0&&map[nexty][nextx]<=0) {
				q.push(ii(nexty, nextx));
				visited[nexty][nextx] =1;
			}
		}
	}
	return cnt;
}
int main() {
	int max_height = 0;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			max_height = max(max_height, map[i][j]);
		}
	}
	while (max_height--) {
		for (int i = 0; i < n; i++) {
			if (map[i][0] <= 0 && visited[i][0] == 0) {
				bfs(i, 0);
			}
			if (map[i][m-1] <= 0 && visited[i][m-1] == 0) {
				bfs(i, m-1);
			}
		}
		for (int i = 0; i < m; i++) {
			if (map[0][i] <= 0 && visited[0][i] == 0) {
				bfs(0, i);
			}
			if (map[n-1][i] <= 0 && visited[n-1][i] == 0) {
				bfs(n - 1,i);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] <= 0 && visited[i][j] == 0) {
					sum += bfs(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				map[i][j]--;
			}
		}
	}
	printf("%d\n",sum);
}

// 수많은 시도...
// Divide & Conquer
// 기본적으로 높이별로 슬라이싱한다고 생각(높이가 최대 9이기 때문에)
// 높이가 0 이하인 블럭은 진입가능하고 1씩 카운팅
// 모서리를 먼저 bfs 해야 흘러넘치는 영역을 visited 표시로 접근하지 않을 수있음
// 처음에는 bfs에서 바깥영역을 인덱싱하면 return 0 하는 식으로 하려 했는데 이경우에는
// 매번 visited를 0으로 다시 초기화 시켜 줘야함. 그렇지 않으면 visited 때문에
// 물이 새는 영역이 막혀서 물이 안세는 것처럼 카운팅할 수 있음
// 이렇게 세고 나면 map을 전체적으로 1씩 감소
// map에 주어진 최대높이 이상으로 감소시키면 모든 부분이 높이가 0이하가 되므로 
// max_height 까지만 감소