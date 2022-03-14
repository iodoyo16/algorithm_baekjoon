#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;

int dist[100][100];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++)
			dist[i][j] = INF;
		dist[i][i] = 0;
	}
	for (int i = 0; i < n; i++) {
		char s, e;
		scanf("\n%c => %c", &s, &e);
		dist[s - 'A'][e - 'A'] = 1;
	}
	int cnt = 0;
	for(int k=0;k<='z'-'A';k++)
		for (int i = 0; i <= 'z' - 'A'; i++) {
			for (int j = 0; j <= 'z' - 'A'; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]+1) {
					dist[i][j] = dist[i][k] + dist[k][j]+1;
				}
			}
		}
	for (int i = 0; i <= 'z' - 'A'; i++) {
		for (int j = 0; j <= 'z' - 'A'; j++) {
			if (i!=j&&dist[i][j]!=INF&&dist[i][j]!=0) {
				cnt++;
			}
		}
	}
	printf("%d\n",cnt);
	for (int i = 0; i <= 'z'-'A'; i++) {
		if ('Z' - 'A' < i && i < 'a' - 'A')
			continue;
		for (int j = 0; j <= 'z' - 'A'; j++) {
			if (i == j)
				continue;
			if ('Z' - 'A' < j && j < 'a' - 'A')
				continue;
			if (dist[i][j] != INF)
				printf("%c => %c\n", i+'A',j+'A');
		}
	}
}