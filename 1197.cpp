/*
1. kruskal (greedy)
간선리스트 오름차순 정렬, 사이클 생성하는 간선 제외하면서 간선집합에 추가 -> union find
2. prim 
시작정점에서부터 mst를 확장하는 방법. 시작정점에서 인접한 최소 간선으로 연결된 정점을
선택한다.

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
	// x의 조상이 현재 자기자신인데, x의 조상을 y의 조상(혹은 y자기자신)으로 갱신
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
