#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

long long dp[1010];
int main() {
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 2;
	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
		dp[i] %= 10007;
	}
	printf("%lld", dp[n]%10007);
}

// 끝을 슬라이싱