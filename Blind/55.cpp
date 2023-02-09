#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int> productExceptSelf(vector<int>& nums) {
		vector<int> ans(nums.size()), prod(nums.size()), prod_rev(nums.size());
		const int last = nums.size() - 1;

		prod[0] = nums[0];
		prod_rev[last] = nums[last];
		for (int i = 1; i < nums.size(); i++) {
			prod[i] = prod[i - 1] * nums[i];
			prod_rev[last - i] = prod_rev[last - i + 1] * nums[last - i];
		}

		ans[0] = prod_rev[1];
		ans[last] = prod[last - 1];
		for (int i = 1; i < last; i++)
			ans[i] = prod[i - 1] * prod_rev[i + 1];

		return ans;
	}
};


// 1	2	3	4

// 1	2	6	24
// 24	24	12	4

// 24	12	8	6



// -1	1	0	-3	3

// -1	-1	0	0	0
// 0	0	0	-9	3

// 0	0	9	0	0