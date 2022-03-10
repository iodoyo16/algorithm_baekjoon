#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;

typedef pair<int, int> ii;

int map[55][55];
int visited[55][55];
int movx[4] = { 0,1,0,-1 };
int movy[4] = { -1,0,1,0 };
int n, m;
int bfs(int y,int x) {
	int cnt = 0;
	queue<ii>q;
	q.push(ii(y, x));			  
	visited[y][x] = 1;
	while (!q.empty()) {
		int cury = q.front().first;
		int curx = q.front().second;
		q.pop();
		cnt++;
		for (int i = 0; i < 4; i++) {
			int nexty = cury + movy[i];
			int nextx = curx + movx[i];
			if (nexty < 0 || nexty >= n || nextx < 0 || nextx >= m)
				continue;
			if (visited[nexty][nextx] == 0&&map[nexty][nextx]<=0) {
				q.push(ii(nexty, nextx));
				visited[nexty][nextx] =1;
			}
		}
	}
	return cnt;
}
int main() {
	int max_height = 0;
	int sum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &map[i][j]);
			max_height = max(max_height, map[i][j]);
		}
	}
	while (max_height--) {
		for (int i = 0; i < n; i++) {
			if (map[i][0] <= 0 && visited[i][0] == 0) {
				bfs(i, 0);
			}
			if (map[i][m-1] <= 0 && visited[i][m-1] == 0) {
				bfs(i, m-1);
			}
		}
		for (int i = 0; i < m; i++) {
			if (map[0][i] <= 0 && visited[0][i] == 0) {
				bfs(0, i);
			}
			if (map[n-1][i] <= 0 && visited[n-1][i] == 0) {
				bfs(n - 1,i);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] <= 0 && visited[i][j] == 0) {
					sum += bfs(i, j);
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = 0;
				map[i][j]--;
			}
		}
	}
	printf("%d\n",sum);
}

// ������ �õ�...
// Divide & Conquer
// �⺻������ ���̺��� �����̽��Ѵٰ� ����(���̰� �ִ� 9�̱� ������)
// ���̰� 0 ������ ���� ���԰����ϰ� 1�� ī����
// �𼭸��� ���� bfs �ؾ� �귯��ġ�� ������ visited ǥ�÷� �������� ���� ������
// ó������ bfs���� �ٱ������� �ε����ϸ� return 0 �ϴ� ������ �Ϸ� �ߴµ� �̰�쿡��
// �Ź� visited�� 0���� �ٽ� �ʱ�ȭ ���� �����. �׷��� ������ visited ������
// ���� ���� ������ ������ ���� �ȼ��� ��ó�� ī������ �� ����
// �̷��� ���� ���� map�� ��ü������ 1�� ����
// map�� �־��� �ִ���� �̻����� ���ҽ�Ű�� ��� �κ��� ���̰� 0���ϰ� �ǹǷ� 
// max_height ������ ����