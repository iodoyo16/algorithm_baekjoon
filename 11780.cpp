#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int dist[101][101];
vector<int>v[101][101];
int main() {
	int n, m;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dist[i][i] = 0;
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		int s, e,cost;
		scanf("%d %d %d", &s, &e, &cost);
		dist[s][e] = min(dist[s][e],cost);
	}

	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
					v[i][j].clear();
					for (int l = 0; l < v[i][k].size(); l++) {
						v[i][j].push_back(v[i][k][l]);
					}
					v[i][j].push_back(k);
					for (int l = 0; l < v[k][j].size(); l++) {
						v[i][j].push_back(v[k][j][l]);
					}
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) {
				printf("0 ");
			}
			else {
				printf("%d ", dist[i][j]);
			}
		}
		printf("\n");
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF||i==j) {
				printf("0");
			}
			else {
				printf("%d ", v[i][j].size() + 2);
				printf("%d ", i);
				for (int k = 0; k < v[i][j].size(); k++) {
					printf("%d ",v[i][j][k]);
				}
				printf("%d ", j);
			}
			printf("\n");
		}
	}
}