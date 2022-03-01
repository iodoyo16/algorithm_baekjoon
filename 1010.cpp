#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;
int dp[35][35];
int main() {
	int t,n, m;
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m; j++)
				dp[i][j] = 0;
		for (int i = 1; i <= m; i++) {
			dp[1][i] = i;
		}
		for (int i = 2; i <= n; i++) {
			for (int j = i; j <= m; j++) {
				for (int k = i - 1; k <= j - 1; k++) {
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
		printf("%d\n", dp[n][m]);
	}
}