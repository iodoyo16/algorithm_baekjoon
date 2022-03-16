#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;

typedef pair<int, int> ii;
vector<ii> x;
long long y_sum[300010];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int idx, x_i;
		scanf("%d %d", &idx, &x_i);
		x.push_back(ii(idx, x_i));
	}
	int m;
	scanf("%d", &m);
	long long tmp_sum = 0, tmp_idx = 0;
	for (int i = 0; i < m; i++) {
		int idx;
		long long y_i;
		scanf("%d %lld", &idx, &y_i);
		for (int j = tmp_idx; j <= idx; j++) {
			y_sum[j] = tmp_sum;
		}
		tmp_sum += y_i;
		tmp_idx = idx + 1;
	}
	y_sum[tmp_idx] = tmp_sum;
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	long long ans = 0;
	for (int i = 0; i < x.size(); i++) {
		int x_idx = x[i].first;
		int x_val = x[i].second;
		int start = x_idx + a;
		int end = x_idx + b + 1;
		if (start < 0)
			start = 0;
		if (start > tmp_idx)
			continue;
		if (end > tmp_idx)
			end = tmp_idx;
		if (end < 0)
			continue;
		long long y_ab = y_sum[end] - y_sum[start];
		//printf("x_i: %d start: %d end: %d y_ab: %d\n", x_val, start, end, y_ab);
		ans += x_val * y_ab;
	}
	printf("%lld", ans);
}