#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[310][2]; // 0 : 한칸 점프해서 도달 , 1: 두칸 점프해서 도달
int score[310];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
	}
	dp[1][0] = score[1];
	dp[1][1] = score[1]; // 첫칸을 두계단 점프해 왔다는 말이 안되지만
	// 시작은 연속한 계단으로 생각하지 않는다했으므로 값을 넣어줘서 계단되게했다.
	dp[2][0] = score[1] + score[2];
	dp[2][1] = score[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + score[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score[i];
	}
	printf("%d", max(dp[n][0], dp[n][1]));
}
// 세개의 연속된 계단을 밟으면 안된다라는 조건을
// 세번 연속 한칸 점프하면 안된다로 생각해서 헤맸다....