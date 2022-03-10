#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<string>

using namespace std;
typedef pair<string, int> si;
map<string, int> msi;
vector<string> v;
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string name;
		cin >> name;
		msi.insert(si(name, i));
		v.push_back(name);
	}
	for (int i = 0; i <m; i++) {
		string search;
		cin >> search;
		if ('A' <= search[0] && search[0] <= 'Z')
			cout<< msi[search]<<"\n";
		else {
			int num = stoi(search);
			cout << v[num-1]<<"\n";
		}
	}
}