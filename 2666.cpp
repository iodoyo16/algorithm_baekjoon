#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>


using namespace std;

int dp[25][25][25];
int seq[25];
int main() {
	int num_of_closet;
	int initial_open1, initial_open2;
	int num_of_sequence;
	scanf("%d", &num_of_closet);
	scanf("%d %d", &initial_open1, &initial_open2);
	scanf("%d", &num_of_sequence);
	for (int i = 1; i <= num_of_sequence; i++) {
		scanf("%d", &seq[i]);
	}
	dp[0][initial_open1][initial_open2] = 0;
	seq[1]
	dp[1]
}