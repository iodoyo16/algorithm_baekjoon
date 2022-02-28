#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int parent[1010];
typedef pair<int, int> ii;
typedef pair<int, ii>iii;
vector<iii>ve;
int Find(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = Find(parent[x]);
}
void Union(int x,int y) {
	parent[parent[x]] = parent[y];
}
int main() {
	int n, m,k=0;
	int ans;
	scanf("%d %d", &n, &m);
	for (int i = 0; i <=n; i++)
		parent[i] = i;
	for (int i = 0; i <= m; i++) {
		int u, v, c;
		scanf("%d %d %d", &u, &v, &c);
		ve.push_back(iii(c, ii(u, v)));
	}
	sort(ve.begin(), ve.end());//오르막 많이
	for (int i = 0; i < ve.size(); i++) {
		int u = ve[i].second.first;
		int v = ve[i].second.second;
		if (Find(u) != Find(v)) {
			Union(u, v);
			if (ve[i].first == 0) {
				k++;
			}
		}
	}
	ans = k*k;
	k = 0;
	for (int i = 0; i <=n; i++)
		parent[i] = i;
	for (int i = ve.size()-1; i>=0; i--) {//내리막 많이
		int u = ve[i].second.first;
		int v = ve[i].second.second;
		if (Find(u) != Find(v)) {
			Union(u, v);
			if (ve[i].first == 0) {
				k++;
			}
		}
	}
	ans -= k * k;
	printf("%d\n",ans);
}

//n 과 m에 포함되지 않는 0 노드, 0 - 1 edge가 있어서 조심해야했다.