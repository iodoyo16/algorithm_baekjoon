#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[310][2]; // 0 : ��ĭ �����ؼ� ���� , 1: ��ĭ �����ؼ� ����
int score[310];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
	}
	dp[1][0] = score[1];
	dp[1][1] = score[1]; // ùĭ�� �ΰ�� ������ �Դٴ� ���� �ȵ�����
	// ������ ������ ������� �������� �ʴ´������Ƿ� ���� �־��༭ ��ܵǰ��ߴ�.
	dp[2][0] = score[1] + score[2];
	dp[2][1] = score[2];
	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + score[i];
		dp[i][1] = max(dp[i - 2][0], dp[i - 2][1]) + score[i];
	}
	printf("%d", max(dp[n][0], dp[n][1]));
}
// ������ ���ӵ� ����� ������ �ȵȴٶ�� ������
// ���� ���� ��ĭ �����ϸ� �ȵȴٷ� �����ؼ� ��̴�....