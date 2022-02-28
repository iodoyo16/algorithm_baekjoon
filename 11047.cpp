#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>

using namespace std;
vector<int> v;
int main() {
	int n, k,sum=0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int price;
		scanf("%d", &price);
		v.push_back(price);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		int num = k / v[i];
		k = k - num * v[i];
		sum += num;
		if (k == 0)
			break;
	}
	printf("%d",sum);
}