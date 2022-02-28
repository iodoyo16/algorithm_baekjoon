#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

long long dp[50];
long long fibo(int x) {
	if (x == 0)
		return 0;
	if (x == 1)
		return 1;
	if (dp[x] == -1) {
		return dp[x] = fibo(x - 2) + fibo(x - 1);
	}
	else
		return dp[x];
}
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i <= n; i++)
		dp[i] = -1;
	printf("%lld", fibo(n));
}