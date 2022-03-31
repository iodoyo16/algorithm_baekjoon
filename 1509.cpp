#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string.h>
using namespace std;

char input_str[2510];
int palindrome_dp[2505][2505];
int main() {
	scanf("%s", input_str);
	int ans = 0;strlen(input_str);
	char prev_top = '\0';
	for (int i = 0; i < input_len; i++) {
		palindrome_dp[i][i] = 1;
	}
	for(int i=0;i)
}