#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> skillscore_arr;
int main() {
	int num_of_students;
	scanf("%d", &num_of_students);
	long long ans=0;
	for (int i = 0; i < num_of_students; i++) {
		int coding_skill;
		scanf("%d", &coding_skill);
		skillscore_arr.push_back(coding_skill);
	}
	sort(skillscore_arr.begin(), skillscore_arr.end());
	for (int i = 0; i < num_of_students-2; i++) {
		for (int j = i+1; j < num_of_students-1; j++) {
			int temp=skillscore_arr[i] + skillscore_arr[j];
			int start_idx=lower_bound(skillscore_arr.begin() + j + 1, skillscore_arr.end(), -temp)-skillscore_arr.begin();
			int end_idx=upper_bound(skillscore_arr.begin() + j + 1, skillscore_arr.end(), -temp)-skillscore_arr.begin();
			int same_score_num = end_idx - start_idx;
			ans += same_score_num;
		}
	}
	printf("%lld\n", ans);
}