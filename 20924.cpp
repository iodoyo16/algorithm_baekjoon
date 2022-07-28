#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

vector< vector<pair<int, int> > >tree_edge;
int visit[200010];
int giga_node = -1;
int root_num;
int dfs(int cur_node) {
	int out_degree = tree_edge[cur_node].size();
	if (cur_node == root_num&& (out_degree >= 2|| out_degree==0)) {
		giga_node = cur_node;
	}
	else {
		if (giga_node == -1&&out_degree >= 3) {
			giga_node = cur_node;
		}
	}
	int max_len = 0;
	for (int i = 0; i < tree_edge[cur_node].size(); i++) {
		int next_node = tree_edge[cur_node][i].first;
		int cost = tree_edge[cur_node][i].second;
		if (visit[next_node] != -1)
			continue;
		visit[next_node] = visit[cur_node] + cost;
		max_len = max(max_len, dfs(next_node)+cost);
	}
	return max_len;
}
int main() {
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int node_num;
	cin >> node_num >> root_num;
	tree_edge.resize(node_num + 1);
	for (int i = 1; i <= node_num; i++) {
		visit[i] = -1;
	}
	for (int i = 0; i < node_num-1; i++) {
		int v1, v2, cost;
		cin >> v1 >> v2 >> cost;
		tree_edge[v1].push_back(make_pair(v2, cost));
		tree_edge[v2].push_back(make_pair(v1, cost));
	}
	visit[root_num] = 0;
	int max_len = dfs(root_num);
	int tree_height;
	if (giga_node == -1)
		tree_height = max_len;
	else {
		tree_height = visit[giga_node];
	}
	cout << tree_height << " " << max_len - tree_height;
	return 0;
}

//root 노드가 edge 2개 이상
//이외의 노드가 edge 3개 이상