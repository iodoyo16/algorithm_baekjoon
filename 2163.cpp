#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int ans = min((n * (m - 1) + n - 1), (m * (n - 1) + m - 1));
	printf("%d",ans);
}

/*
int dp[90100];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	dp[1] = 0;
	int x, y;
	for (int i = 2; i <= n * m; i++) {
		x = i / 2;
		y = i - x;
		dp[i] = dp[x] + dp[y] + 1;
	}
	printf("%d", dp[n * m]);
}
*/