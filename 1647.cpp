#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<iii>ve;
int parent[100010];
int Find(int x) {
	if (parent[x] == x)
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Union(int x,int y) {
	parent[parent[x]] = parent[y];
}
int main() {
	int n, m,max_cost=0;
	long long ans=0;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		scanf("%d %d %d",&u,&v,&cost);
		ve.push_back(iii(cost, ii(u, v)));
	}
	sort(ve.begin(), ve.end());
	for (int i = 0; i < ve.size(); i++) { // 최장 edge 생략
		int cost = ve[i].first;
		int v1 = ve[i].second.first;
		int v2 = ve[i].second.second;
		if (Find(v1) == Find(v2))
			continue;
		//printf("u : %d v: %d cost: %d\n", ve[i].second.first, ve[i].second.second, ve[i].first);
		Union(v1, v2);
		max_cost = max(max_cost, cost);
		ans += cost;
	}
	printf("%lld\n",ans-max_cost);
}
// 처음에 sort 된 edge 들 중 마지막 edge를 빼면 될거라 생각
// 하지만 마지막 edge 가 cycle을 만드는 경우 이미 하나의 mst가 만들어 진 상태이므로
// 마을이 분할되는 경우가 아님
// 따라서 mst 다 만들고 나서 그중 max 값을 뺀다.