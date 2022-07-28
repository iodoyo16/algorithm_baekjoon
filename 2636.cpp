#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
int map[110][110] = { 0, };
int n, m;
int mx[4] = { 1,0,-1,0 };
int my[4] = { 0,1,0,-1 };
queue<pair<int, int> >a;
queue<pair<int, int> >b;
queue<pair<int, int> >c;
int s;
void air(int x, int y)
{
	map[x][y] = -1;
	b.push(make_pair(x, y));
	while (!b.empty())
	{
		int nowx = b.front().first;
		int nowy = b.front().second;
		for (int i = 0; i < 4; i++)
		{
			int nx = nowx + mx[i];
			int ny = nowy + my[i];
			if (nx > 0 && ny > 0 && nx < n + 1 && ny < m + 1 && map[nx][ny] == 0)
			{
				map[nx][ny] = -1;
				b.push(make_pair(nx, ny));
			}
		}
		b.pop();
	}
}
int bfs()
{
	int ans = 0;
	while (!a.empty())
	{
		s = a.size();
		for (int i = 1; i <= s; i++)
		{
			int ch = 0;
			int nowx = a.front().first;
			int nowy = a.front().second;
			for (int j = 0; j < 4; j++)
			{
				int nx = nowx + mx[j];
				int ny = nowy + my[j];
				if (map[nx][ny] == -1)
				{
					map[nowx][nowy] = 2;
				}
			}
			a.pop();
		}

		++ans;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == 2)
				{
					air(i, j);
				}
			}
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				if (map[i][j] == 1) {
					a.push(make_pair(i, j));
				}
			}
	}
	return ans;
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1)
				a.push(make_pair(i, j));
		}
	air(1, 1);
	printf("%d\n", bfs());
	printf("%d", s);

}