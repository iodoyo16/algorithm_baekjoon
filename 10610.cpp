#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>digit;
int main() {
	int sum = 0;
	while(1){
		char temp;
		scanf("%c", &temp);
		if (temp =='\n')
			break;
		digit.push_back(temp - '0');
		sum += temp-'0';
	}
	sort(digit.begin(), digit.end());
	if (sum % 3 == 0 && digit[0]==0) {
		for (int i = digit.size()-1; i >=0; i--) {
			printf("%d", digit[i]);
		}
	}
	else
		printf("-1");
}