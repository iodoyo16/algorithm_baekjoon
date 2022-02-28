#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, m;
	int min_pack=1000, min_single=1000;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int pack, single;
		scanf("%d %d", &pack, &single);
		min_pack = min(pack, min_pack);
		min_single = min(single, min_single);
	}
	int min_six = min(min_pack, min_single * 6);
	int ans = n / 6 * min_six;
	ans += min((n % 6) * min_single, min_pack);
	printf("%d", ans);
}