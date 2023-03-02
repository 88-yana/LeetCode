#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
// 	vector<int> sortArray(vector<int>& nums) {
// 		multiset<int> ms;
// 		vector<int> ans;
// 		for (int i = 0; i < nums.size(); i++) {
// 			ms.insert(nums[i]);
// 		}
// 		for (auto it = ms.begin(); it!= ms.end(); it++) {
// 			ans.push_back(*it);
// 		}
// 		return ans;
// 	}
// };

class Solution {
public:
	vector<int> sortArray(vector<int>& nums) {
		vector<int> ans;
		for (int i = 0; i < nums.size(); i++) {
			ans.push_back(nums[i]);
			for (int i = ans.size() / 2 - 1; i >= 0; i--) {
				if (2 * i + 1 < ans.size() && ans[i] < ans[2 * i + 1])
				{
					int temp = ans[i];
						ans[i] = ans[2 * i + 1];
						ans[2 * i + 1] = temp;
				}
				if (2 * i + 2 < ans.size() && ans[i] < ans[2 * i + 2])
				{
					int temp = ans[i];
						ans[i] = ans[2 * i + 2];
						ans[2 * i + 2] = temp;
				}
			}
		}
		for (int i = 0; i < nums.size(); i++) {
			cout << ans[i] << " ";
		}
		return ans;
	}
};