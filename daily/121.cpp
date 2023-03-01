#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices);
};

int Solution::maxProfit(vector<int>& prices) {
	int mn = INT_MAX;
	int ans = 0;
	for (int i = 0; i < prices.size(); i++) {
		if (prices[i] < mn) {
			mn = prices[i];
		}
		ans = max(ans, prices[i] - mn);
	}
	return ans;
}


// int Solution::maxProfit(vector<int>& prices) {
// 	vector<int> mn(prices.size());
// 	vector<int> mx(prices.size());
// 	mn[0] = prices[0];
// 	for (int i = 1; i < prices.size(); i++) {
// 		mn[i] = min(prices[i - 1], prices[i]);
// 	}
// 	mx[prices.size() - 1] = prices[prices.size() - 1];
// 	for (int i = prices.size() - 2; i >= 0; i--) {
// 		mx[i] = max(mx[i + 1], prices[i]);
// 	}
// 	int ans = 0;
// 	for (int i = 0; i < prices.size(); i++) {
// 		ans = max(ans, mx[i] - mn[i]);
// 	}
// 	return ans;
// }