#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites);
};

bool Solution::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
	vector<vector<int>> to(numCourses);
	vector<int> in_deg(numCourses);
	for (int i = 0; i < prerequisites.size(); i++) {
		to[prerequisites[i][1]].push_back(prerequisites[i][0]);
		in_deg[prerequisites[i][0]]++;
	}
	queue<int> q;
	for (int i = 0; i < numCourses; i++) {
		if (in_deg[i] == 0)
			q.push(i);
	}
	while (!q.empty()) {
		int v = q.front(); q.pop();
		for (int u : to[v]) {
			in_deg[u]--;
			if (in_deg[u] == 0)
				q.push(u);
		}
	}
	for (int i = 0; i < numCourses; i++) {
		if (in_deg[i] != 0)
			return false;
	}
	return true;
}

int main() {
	vector<vector<int>> prerequisites;
	prerequisites.push_back({1, 2});
	Solution s;
	cout << s.canFinish(2, prerequisites) << endl;
	return 0;
}