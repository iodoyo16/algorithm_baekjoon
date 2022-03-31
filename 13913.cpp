#define _CRT_SECURE_NO_WARNINGS
#define MAX 100000+1
#include<cstdio>
#include<queue>
#include<stack>
using namespace std;

queue<int>q;
int hide_and_seek[MAX][2];
vector <int> patharr;
int main() {
	int start_pos, dest_pos,cur_pos;
	for (int i = 0; i < MAX; i++) {
		hide_and_seek[i][0] = hide_and_seek[i][1] = -1;
	}
	scanf("%d %d", &start_pos, &dest_pos);
	q.push(start_pos);
	hide_and_seek[start_pos][0] = 0;
	while (!q.empty()){
		cur_pos = q.front();
		q.pop();
		if (cur_pos == dest_pos)
			break;
		int cur_time = hide_and_seek[cur_pos][0];
		if (cur_pos +1< MAX&&hide_and_seek[cur_pos+1][0]==-1) {
			hide_and_seek[cur_pos + 1][0] = cur_time + 1;
			hide_and_seek[cur_pos + 1][1] = cur_pos;
			q.push(cur_pos + 1);
		}
		if (cur_pos-1 >= 0&& hide_and_seek[cur_pos - 1][0] == -1) {
			hide_and_seek[cur_pos - 1][0] = cur_time + 1;
			hide_and_seek[cur_pos - 1][1] = cur_pos;
			q.push(cur_pos - 1);
		}
		if (cur_pos * 2 < MAX&& hide_and_seek[cur_pos*2][0] == -1) {
			hide_and_seek[cur_pos * 2][0] = cur_time + 1;
			hide_and_seek[cur_pos * 2][1] = cur_pos;
			q.push(cur_pos * 2);
		}
	}
	printf("%d\n", hide_and_seek[dest_pos][0]);
	int tmp_pos = dest_pos;
	while (tmp_pos!=-1) {
		patharr.push_back(tmp_pos);
		tmp_pos = hide_and_seek[tmp_pos][1];
	}
	for (int i = patharr.size() - 1; i >= 0; i--) {
		printf("%d ", patharr[i]);
	}
}