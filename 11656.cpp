#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

vector<string>v;
int main() {
	string input;
	cin >> input;
	for (int i = 0; i < input.length(); i++) {
		v.push_back(input.substr(i));
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}
}