#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>

using namespace std;
int visited[10010];
int prime_check[10010];

int bfs(int prime1,int prime2) {
	queue<int> q;
	q.push(prime1);
	visited[prime1] = 1;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == prime2)
			return visited[prime2];
		int first = cur % 1000;
		int second = cur-(cur % 1000 - cur % 100);
		int third = cur - (cur % 100 - cur % 10);
		int fourth = cur - (cur % 10);
		for (int i = 0; i < 10; i++) {
			int next1 = first + i * 1000;
			int next2 = second + i * 100;
			int next3=third+i*10; 
			int next4=fourth+i;
			if (next1 >= 1000 && prime_check[next1] != -1&&visited[next1]==0) {
				q.push(next1);
				visited[next1] = visited[cur]+1;
			}
			if (prime_check[next2] != -1 && visited[next2] == 0) {
				q.push(next2);
				visited[next2] = visited[cur] + 1;
			}
			if (prime_check[next3] != -1 && visited[next3] == 0) {
				q.push(next3);
				visited[next3] = visited[cur] + 1;
			}
			if (prime_check[next4] != -1 && visited[next4] == 0) {
				q.push(next4);
				visited[next4] = visited[cur] + 1;
			}
		}
	}
	return -1;
}
int main() {
	int t;
	scanf("%d",&t);
	for (int i = 2; i <= 100; i++) {
		int j = 2;
		while (i * j < 10000) {
			prime_check[i * j] = -1;
			j++;
		}
	}
	while (t--) {
		int prime1, prime2;
		for (int i = 1000; i < 10000; i++)
			visited[i] = 0;
		scanf("%d %d", &prime1, &prime2);
		int dist = bfs(prime1, prime2);
		if (dist == -1)
			printf("impossible\n");
		else
			printf("%d\n", dist-1);
	}
}


// queue clear
//= == mistake
// prime number : not include 1