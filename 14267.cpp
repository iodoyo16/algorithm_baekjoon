#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int parent[100010];
int score[100010];
int dp[100010];
int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &parent[i]);
	}
	for (int i = 0; i < m; i++) {
		int employee_num, w;
		scanf("%d %d",&employee_num,&w);
		score[employee_num] += w; // ���� ������� Ī���� ������ ���� ���� �ִܴ�..
	}
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[parent[i]] + score[i];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", dp[i]);
}