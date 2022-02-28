#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[1010][3];
int cost[1010][3];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d %d %d", &cost[i][0], &cost[i][1], &cost[i][2]);
	}
	for (int i = 0; i < 3; i++)
		dp[1][i] = cost[1][i];
	for (int i = 2; i <= n; i++) {
		dp[i][0] = min(dp[i-1][1], dp[i - 1][2])+cost[i][0];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
		dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]) + cost[i][2];
	}
	printf("%d", min(dp[n][0], min(dp[n][1], dp[n][2])));
}