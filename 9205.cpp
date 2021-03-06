#define _CRT_SECURE_NO_WARNINGS
#define INF 999999999
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int> ii;
queue<int>q;
ii pos[110];
int visit[110];
vector<vector <int> >v;
int main() {
	int t, n, m;
	scanf("%d", &t);
	while (t--) {
		int x,y;
		scanf("%d", &n);
		v.resize(n + 3);
		for (int i = 0; i <= n+1; i++) {
			scanf("%d %d", &x, &y);
			pos[i] = ii(x, y);
			for (int j = 0; j < i; j++) {
				int cur_dist=abs(pos[j].first - x)+ abs(pos[j].second - y);
				if (cur_dist <=1000) {
					v[i].push_back(j);
					v[j].push_back(i);
				}
			}
			visit[i] = 0;
		}
		q.push(0);
		visit[0] = 1;
		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			for (int i = 0; i < v[cur].size(); i++) {
				int next = v[cur][i];
				if (visit[next] == 0) {
					visit[next] = 1;
					q.push(next);
				}
			}
		}
		if (visit[n + 1] == 1)
			printf("happy\n");
		else
			printf("sad\n");
		for (int i = 0; i <= n + 1; i++)
			v[i].clear();
	}
}

//그래프 내의 최단거리 알고리즘. 
//prim이나 kruskal 과 달리 방향 그래프도 가능
//음수 사이클이 존재하는 경우에서는 최단거리가 존재하지 않으므로 불가능

//다익스트라 : 한점으로 부터 다른 모든 정점까지의 최단거리
//음수가중치 없음

//벨만포드 : 한점에서 다른 정점으로 최단거리
//음수가중치 가능
//벨만포드는 V-1개의 최대 edge를 사용하는 경우를 고려해서 최단거리를 계산하기때문에
//음수사이클에 잡히지 않는다.
//이를 이용해서 벨만포드를 한번더 수행했을때 최단거리가 다른 정점이 있다면
//음수사이클이 존재하는것이므로 이를 판별할 수있다

//플로이드 와셜: 그래프 내의 모든 정점간의 최단거리
//음수가중치 가능, 음수사이클 불가능