#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>v;
int main() {
	int n,ans=0,sum=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int pi;
		scanf("%d", &pi);
		v.push_back(pi);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		sum += v[i];
		ans += sum;
	}
	printf("%d", ans);
}