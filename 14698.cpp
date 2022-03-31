#define _CRT_SECURE_NO_WARNINGS
#define DIV 1000000007
#include<cstdio>
#include<queue>

using namespace std;

int main() {
	int test_num;
	scanf("%d", &test_num);
	while (test_num--) {
		int slime_num;
		long long slime_energy;
		long long total_energy = 1;
		priority_queue <long long, vector<long long>, greater<long long> > slime_energy_pq;
		scanf("%d", &slime_num);
		for (int i = 0; i < slime_num; i++) {
			scanf("%lld", &slime_energy);
			slime_energy_pq.push(slime_energy);
		}
		while (slime_energy_pq.size() > 1) {
			long long min_slime1 = slime_energy_pq.top();
			slime_energy_pq.pop();
			long long min_slime2 = slime_energy_pq.top();
			slime_energy_pq.pop();
			long long energy_cost = min_slime1 * min_slime2;
			slime_energy_pq.push(energy_cost);
			total_energy = total_energy*(energy_cost%DIV)%DIV;
		}
		printf("%lld\n", total_energy);
	}
}