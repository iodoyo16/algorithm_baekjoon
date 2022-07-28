#define _CRT_SECURE_NO_WARININGS
#include<iostream>
#include<string>

using namespace std;

string polynomial_exp;
int coef[2];
int main() {
	cin >> polynomial_exp;
	int coef_idx = 0,coef_val = 0;
	bool negative_flag=false;
	for (int i = 0; i < polynomial_exp.length(); i++) {
		char tmp= polynomial_exp[i];
		if ('0' <= tmp && tmp <= '9') {
			coef_val *= 10;
			coef_val+=tmp - '0';
		}
		else if (tmp == 'x') {
			if (coef_val == 0)
				coef_val = 1;
			coef[1]=coef_val/2;
			if (negative_flag) {
				coef[1] *= -1;
			}
			coef_val = 0;
			negative_flag = false;
		}
		else {
			if (tmp=='-') {
				negative_flag = true;
			}
			coef[0] = coef_val;
			coef_val = 0;
		}
	}
	if (coef_val != 0) {
		coef[0] = coef_val;
		if (negative_flag) {
			coef[0] *= -1;
		}
	}

	if (coef[1] != 0) {
		if (coef[1] == -1)
			cout << "-";
		else if (coef[1] != 1) {
			cout << coef[1];
		}
		cout << "xx";
	}
	if (coef[0] != 0) {
		if (coef[0] > 0&&coef[1]!=0)
			cout << "+";
		if (coef[0] == -1)
			cout << "-";
		else if (coef[0] != 1) {
			cout << coef[0];
		}
		cout << "x";
	}
	if (coef[0] != 0 || coef[1] != 0)
		cout << "+";
	cout << "W\n";
	return 0;
}