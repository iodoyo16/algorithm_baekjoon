/*
1. kruskal (greedy)
��������Ʈ �������� ����, ����Ŭ �����ϴ� ���� �����ϸ鼭 �������տ� �߰� -> union find
2. prim 
���������������� mst�� Ȯ���ϴ� ���. ������������ ������ �ּ� �������� ����� ������
�����Ѵ�.

*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
typedef pair<int, int> ii;
typedef pair<int, ii>iii;
vector<iii > ve;
int parent[10010];
int Find(int i) {
	if (parent[i] == i)
		return i;
	else
		return parent[i] = Find(parent[i]);
}
void Union(int x, int y) {
	parent[parent[x]] = parent[y];
	// x�� ������ ���� �ڱ��ڽ��ε�, x�� ������ y�� ����(Ȥ�� y�ڱ��ڽ�)���� ����
}
int main() {
	int v, e,ans=0;
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int v1, v2, dist;
		scanf("%d %d %d",&v1,&v2,&dist);
		ve.push_back(iii(dist, ii(v1, v2)));
	}
	for (int i = 0; i<v; i++) {
		parent[i] = i;
	}
	sort(ve.begin(), ve.end());
	for (int i = 0; i < e; i++) {
		int u = ve[i].second.first;
		int v = ve[i].second.second;
		int cost = ve[i].first;
		if (Find(u) == Find(v))
			continue;
		Union(u, v);
		ans += cost;
	}
	printf("%d\n", ans);
}
*/

int visited_node[10010];
typedef pair<int, int> ii;
vector<vector<ii> >ve;
priority_queue<ii> pq;

int main() {
	int v, e, cnt=0,ans=0;
	scanf("%d %d", &v, &e);
	ve.resize(v + 1);
	for (int i = 0; i < e; i++) {
		int v1, v2, cost;
		scanf("%d %d %d", &v1, &v2, &cost);
		ve[v1].push_back(ii(-cost, v2));
		ve[v2].push_back(ii(-cost, v1));
	}
	int start = 1;
	visited_node[start] = 1;
	for (int i = 0; i < ve[start].size(); i++) {
		pq.push(ii(ve[start][i].first,ve[start][i].second));
	}
	cnt++;

	while (cnt<v) {
		int cost = pq.top().first;
		int next = pq.top().second;
		pq.pop();
		if (visited_node[next] == 0) {
			visited_node[next] = 1;
			ans += cost;
			for (int i = 0; i < ve[next].size(); i++) {
				pq.push(ii(ve[next][i].first, ve[next][i].second));
			}
			cnt++;
		}
	}
	printf("%d\n", -ans);
}
