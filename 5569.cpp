#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int dp[110][110][2];// 0 : ->, 1: up
int main() {
	int w, h;
	scanf("%d %d", &w, &h);
	dp[1][1][0] = dp[1][1][1] = 1;
	for (int i = 2; i <= h; i++) {
		dp[i][1][0] = 0;
		dp[i][1][1] = dp[i-1][1][1];
	}
	for (int i = 2; i <= w; i++) {
		dp[1][i][1] = 0;
		dp[1][i][0] = dp[1][i - 1][0]; 
	}
	for (int i = 2; i <= h; i++) {
		for (int j = 2; j <= w; j++) {
			dp[i][j][0] = (dp[i][j - 1][0] + dp[i - 1][j - 1][1])%100000;
			dp[i][j][1] = (dp[i-1][j][1] + dp[i - 1][j - 1][0])%100000;
		}
	}
	printf("%d", (dp[h][w][0] + dp[h][w][1])%100000);
}