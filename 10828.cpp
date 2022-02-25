#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stack>
#include<string.h>
using namespace std;

stack<int>st;
int main() {
	int n, t;
	char cmd[20];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &n);
			st.push(n);
		}
		else if (!strcmp(cmd, "pop")) {
			if (st.empty()) {
				printf("-1\n");
			}
			else {
				int top = st.top();
				st.pop();
				printf("%d\n", top);
			}
		}
		else if (!strcmp(cmd, "size")) {
			printf("%d\n", st.size());
		}
		else if (!strcmp(cmd, "empty")) {
			printf("%d\n", st.empty());
		}
		else if (!strcmp(cmd, "top")) {
			if (st.empty()) {
				printf("-1\n");
			}
			else
				printf("%d\n", st.top());
		}

	}
}