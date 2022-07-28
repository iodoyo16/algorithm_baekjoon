#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>

using namespace std;

int main() {
	int test_num;
	printf("wkljflw");
	scanf("%d", &test_num);
	while (test_num--) {
		int card_num,head_idx=0,tail_idx;
		int card_arr[1010];
		int score[2];
		scanf("%d", &card_num);
		tail_idx = card_num-1;
		for (int i = 0; i < card_num; i++) {
			scanf("%d", &card_arr[i]);
		}
		int iter = 0;
		score[0] = score[1] = 0;
		while (head_idx <= tail_idx) {
			int exp_diff_left = card_arr[head_idx] - max(card_arr[head_idx + 1], card_arr[tail_idx]);
			int exp_diff_right = card_arr[tail_idx] - max(card_arr[head_idx], card_arr[tail_idx-1]);
			if (exp_diff_left < exp_diff_right) {
				score[iter % 2] += card_arr[tail_idx];
				tail_idx--;
			}
			else {
				score[iter % 2] += card_arr[head_idx];
				head_idx++;
			}
			iter++;
			printf("score[%d] : %d\n", iter % 2, score[iter % 2]);
		}
		printf("%d\n", max(score[0], score[1]));
	}
	return 0;
}