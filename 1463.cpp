#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include <stdio.h>
#include<algorithm>

using namespace std;

int dp[3000010];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		dp[i] = INF;
	dp[1] = 0;
	for (int i = 1; i < n; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		dp[2 * i] = min(dp[2 * i], dp[i] + 1);
		dp[3 * i] = min(dp[3 * i], dp[i] + 1);
	}
	printf("%d",dp[n]);
}

// 이전에는 그래프로 bfs 로 풀었다.