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
	for (int i = 0; i < ve.size(); i++) { // ���� edge ����
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
// ó���� sort �� edge �� �� ������ edge�� ���� �ɰŶ� ����
// ������ ������ edge �� cycle�� ����� ��� �̹� �ϳ��� mst�� ����� �� �����̹Ƿ�
// ������ ���ҵǴ� ��찡 �ƴ�
// ���� mst �� ����� ���� ���� max ���� ����.