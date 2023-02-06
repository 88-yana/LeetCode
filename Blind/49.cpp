#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	int rob(vector<int>& nums) {
		vector<int> ans(nums.size());
		for (int i = 0; i < nums.size(); i++)
			for (int j = 0; j < nums.size() - 1; j += 2)
				ans[i] += nums[(i + j) % nums.size()];
		int max_ans = nums[0];
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << endl;
			max_ans = max(max_ans, ans[i]);
		}
		return max_ans;
	}
};

int main(void) {
	Solution sol;
	vector<int>	nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5); 
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5); 
	cout << sol.rob(nums) << endl;
}