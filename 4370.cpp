#include <iostream>

using namespace std;

int main() {
	long long n;
	while (cin >> n) {
		long long tmp_val = 1;
		while (true) {
			tmp_val *= 9;
			if (n <= tmp_val) {
				cout << "Baekjoon wins.\n";
				break;
			}
			tmp_val *= 2;
			if (n <= tmp_val) {
				cout << "Donghyuk wins.\n";
				break;
			}
		}
	}
	return 0;
}