#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<string.h>
using namespace std;

queue<int>q;
int main() {
	int n,t;
	char cmd[20];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d",&n);
			q.push(n);
		}
		else if (!strcmp(cmd, "pop")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else {
				int front = q.front();
				q.pop();
				printf("%d\n", front);
			}
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", q.size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", q.empty());
		}
		else if (!strcmp(cmd, "front")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else
				printf("%d\n", q.front());
		}
		else if (!strcmp(cmd, "back")) {
			if (q.empty()) {
				printf("-1\n");
			}
			else 
				printf("%d\n", q.back());
		}
	}
}