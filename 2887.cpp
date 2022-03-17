#define _CRT_SECURE_NO_WARNINGS

#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int planets_pos[100010][3];
int planets_visit
priority_queue<pair<int, int> > pq;
int main() {
	int planet_num;
	scanf("%d", &planet_num);
	for (int i = 0; i < planet_num; i++) {
		scanf("%d %d %d", &planets_pos[i][0], &planets_pos[i][1], &planets_pos[i][2]);
	}
}