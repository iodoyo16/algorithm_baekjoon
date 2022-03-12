#include<cstdio>
#include<algorithm>
using namespace std;
int n;
int a[20] = { 0, };
int ans = 0;
int check(int depth)
{
	for (int i = 1; i < depth; i++) {
		if (a[depth] == a[i])return 0;
		if (abs(a[depth] - a[i]) == depth - i)return 0;
	}
	return 1;
}
void dfs(int depth)
{
	if (depth == n)
		++ans;
	for (int i = 1; i <= n; i++)
	{
		a[depth + 1] = i;
		if (check(depth + 1))
			dfs(depth + 1);
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		a[1] = i;
		dfs(1);
	}
	printf("%d", ans);
	return 0;
}