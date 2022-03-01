#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int arr[15];
int ans[15];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		int taller_num = arr[i];
		for (int j = 0; j < n; j++) {
			if (ans[j] == 0) {
				cnt++;
				if (cnt == taller_num+1) {
					ans[j] = i;
					break;
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}
}