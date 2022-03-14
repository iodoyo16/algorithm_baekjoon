#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
using namespace std;

vector<vector<char> > v;
int visit[100];
int main() {
	int n;
	scanf("%d", &n);
	v.resize('z' - 'A' + 1);
	for (int i = 0; i < n; i++) {
		char s, e;
		scanf("%c => %c", &s, &e);
		v[s-'A'].push_back(e-'A');
	}
	for (int i = 0; i <= 'z'-'A'; i++) {
		if ('Z' - 'A' < i && i < 'a')
			continue;
		for (int j = 0; j < 100; j++) {

		}
		for (int j = 'A'; j <= 'z'; j++) {
			if (i == j)
				continue;
			if ('Z' - 'A' < j && j < 'a')
				continue;

		}
	}
}