#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<algorithm>

using namespace std;
int dist[101][101];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
		
	for (int i = 0; i < m; i++) {
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		dist[v1][v2] = dist[v2][v1] = 1;
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	int min_val = INF;
	int min_idx;
	for (int i = 1; i <= n; i++) {
		int tmp = 0;
		for (int j = 1; j <= n; j++) {
			tmp += dist[i][j];
		}
		if (tmp < min_val) {
			min_val = tmp;
			min_idx = i;
		}
	}
	printf("%d\n", min_idx);
}

//floyd washall, bfs, dji 여러 방법으로 풀 수 있지만 n이 작고, 한번만 수행하면 되는
//floyd washall로 구현