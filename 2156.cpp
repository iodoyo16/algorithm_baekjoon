#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<algorithm>

using namespace std;

int score[10010];
int dp[10010][3];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &score[i]);
	}
	dp[1][0] = dp[1][1]=dp[1][2]=score[1];
	dp[2][0] = max(dp[1][0],max(dp[1][1],dp[1][2]))+ score[2];
	dp[2][1] = score[2];
	dp[2][2] = -INF;
	dp[3][0] = dp[2][1] + score[3];
	dp[3][1] = dp[1][0] + score[3];
	dp[3][2] = score[3];
	for (int i = 4; i <= n; i++) {
		dp[i][0] = max(dp[i - 1][1], dp[i - 1][2])+score[i];
		dp[i][1] = max(dp[i - 2][0], max(dp[i - 2][1], dp[i - 2][2]))+ score[i];
		dp[i][2] = max(dp[i - 3][0], max(dp[i - 3][1], dp[i - 3][2])) + score[i];
	}
	int val1=0, val2 = 0 , val3 = 0;
	val1 = max(dp[n][0], max(dp[n][1], dp[n][2]));
	val2 = max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
	if(n>=2)
		val3 = max(dp[n-2][0], max(dp[n-2][1], dp[n-2][2]));
	printf("%d", max(val1, max(val2, val3)));
}
// dp[i][0]== i-1 �԰� i�԰�
// dp[i][1]==i-2 �԰� i�԰�
// dp[i][2]==i-3 �԰� i�԰�
// i-4 �� ���� ��쿡�� i-2 �� ������ �԰� i�� �Դ°� �ִ��̹Ƿ�
// i-3 ������ �з�

//-> more easy
// dp[i][0]== i��° �ȸ���
// dp[i][1]== i-1��° �ȸ԰� i����
// dp[i][2]== i-1��° �԰� i ����
// 3�� ���� ������ �ȵǹǷ� sequence 2���� ���� ������ ������ �ȴ�.
// dp[i][0]�� ��찡 i-1��°�� �Դ��� �ȸԴ��ĸ� �Ѵ� �����Ѵ�.
// �� �� ��츦 ������ �ʿ䰡 ���� ������ ������ i��°�� �ȸԱ� �����̴�.
/*
#include<stdio.h>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;
int dp[3][10010];
int score[10010];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d",&score[i]);
	dp[0][0] = 0;
	dp[1][0] = score[0];
	dp[2][0] = 0;
	dp[0][1] = score[0];
	dp[1][1] = score[1];
	dp[2][1] = score[0]+score[1];
	for (int i = 2; i < n; i++) {
		dp[0][i] = max(dp[0][i - 1], max(dp[1][i - 1], dp[2][i - 1]));
		dp[1][i] = dp[0][i - 1] + score[i];
		dp[2][i] = dp[1][i - 1] + score[i];
	}
	int max1 = max(dp[0][n-1], dp[1][n-1]);
	int max2 = max(max1, dp[2][n - 1]);
	printf("%d",max2);
}

*/