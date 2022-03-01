#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[510][510];
int tri[510][510];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			scanf("%d", &tri[i][j]);
			if (i == 0)
				dp[0][0] = tri[0][0];
			if (j == 0) {
				dp[i][0] = dp[i-1][0]+tri[i][0];
			}
			if (j == i) {
				dp[i][i] = dp[i - 1][i - 1]+tri[i][i];
			}
			else {
				dp[i][j] = max(dp[i - 1][j-1], dp[i - 1][j]) + tri[i][j];
			}
		}
	}
	int ans=0;

	for (int i = 0; i < n; i++) {
		ans=max(dp[n - 1][i],ans);
	}
	printf("%d", ans);
}