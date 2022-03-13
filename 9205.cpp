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

//�׷��� ���� �ִܰŸ� �˰���. 
//prim�̳� kruskal �� �޸� ���� �׷����� ����
//���� ����Ŭ�� �����ϴ� ��쿡���� �ִܰŸ��� �������� �����Ƿ� �Ұ���

//���ͽ�Ʈ�� : �������� ���� �ٸ� ��� ���������� �ִܰŸ�
//��������ġ ����

//�������� : �������� �ٸ� �������� �ִܰŸ�
//��������ġ ����
//��������� V-1���� �ִ� edge�� ����ϴ� ��츦 ����ؼ� �ִܰŸ��� ����ϱ⶧����
//��������Ŭ�� ������ �ʴ´�.
//�̸� �̿��ؼ� �������带 �ѹ��� ���������� �ִܰŸ��� �ٸ� ������ �ִٸ�
//��������Ŭ�� �����ϴ°��̹Ƿ� �̸� �Ǻ��� ���ִ�

//�÷��̵� �ͼ�: �׷��� ���� ��� �������� �ִܰŸ�
//��������ġ ����, ��������Ŭ �Ұ���