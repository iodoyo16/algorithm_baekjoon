#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>

using namespace std;

int height[1000010];
int main() {
	int num_of_ballon;
	long long ans=0;
	scanf("%d", &num_of_ballon);
	for (int i = 0; i < num_of_ballon; i++) {
		int temp;
		scanf("%d", &temp);
		if (height[temp] == 0) {
			ans++;
			height[temp-1]++;
		}
		else {
			height[temp]--;
			height[temp - 1]++;
		}
	}
	printf("%lld\n", ans);
}