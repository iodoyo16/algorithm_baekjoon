#include<iostream>
#include<set>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string>v;
set<string>ss;

int main() {
	int n, m,ans=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string input;
		cin >> input;
		ss.insert(input);
	}
	for (int i = 0; i < m; i++) {
		string search;
		cin >> search;
		if (ss.find(search) != ss.end()) {
			v.push_back(search);
			//ans++;
		}
	}
	sort(v.begin(), v.end());
	cout <<v.size() << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}