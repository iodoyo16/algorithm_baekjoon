#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long dp[100][2];
int main() {
	int n;
	scanf("%d", &n);
	dp[1][0] = 0;
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	printf("%lld", dp[n][0] + dp[n][1]);
}