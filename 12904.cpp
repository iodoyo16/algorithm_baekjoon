#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<string.h>

using namespace std;

char start_str[1010];
char dest_str[1010];
int main() {
	scanf("%s", start_str);
	scanf("%s", dest_str);
	int start_strlen = strlen(start_str);
	int dest_strlen = strlen(dest_str);
	int num_of_operations=dest_strlen - start_strlen;
	int left_idx = 0;
	int right_idx = dest_strlen - 1;
	bool reverse_flag = false;
	for (int i = 0; i < num_of_operations; i++) {
		if (reverse_flag) {
			if(dest_str[left_idx]=='B'){
				reverse_flag = false;
			}
			dest_str[left_idx] = '\0';
			left_idx++;
		}
		else {
			if (dest_str[right_idx] == 'B') {
				reverse_flag = true;
			}
			dest_str[right_idx] = '\0';
			right_idx--;
		}
	}
	if (reverse_flag) {
		for (int i = right_idx; i >= left_idx; i--) {
			if (dest_str[i] != start_str[right_idx - i]) {
				printf("0");
				return 0;
			}
		}
		printf("1");
	}
	else {
		for (int i = left_idx; i <= right_idx; i++) {
			//printf("%c", dest_str[i]);
			if (dest_str[i] != start_str[i-left_idx]) {
				printf("0");
				return 0;
			}
		}
		printf("1");
	}
	return 0;
}