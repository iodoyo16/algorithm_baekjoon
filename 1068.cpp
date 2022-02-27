#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

using namespace std;

int parent[55];
int child_count[55];
int Find(int x) {
	if (parent[x] == -1)
		return x;
	else
		return Find(parent[x]);
}

int main() {
	int n,ans=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &parent[i]);
		child_count[parent[i]]++;
	}
	int del_node;
	scanf("%d", &del_node);
	child_count[parent[del_node]]--;
	parent[del_node] = -1;
	for (int i = 0; i < n; i++) {
		int root=Find(i);
		if (root == del_node)
			child_count[i] = -1;
	}
	for (int i = 0; i < n; i++) {
		if (child_count[i] == 0)
			ans++;
	}
	printf("%d",ans);
}

