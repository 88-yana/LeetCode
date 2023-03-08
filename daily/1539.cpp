#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		for (int i = 0; i < arr.size(); i++) {
			if (arr[i] - i > k) {
				return i + k;
			}
		}
		return arr.size() + k;
	}
};

arr    2  3  4  7  10
i      0  1  2  3  4
//diff 2  2  2  4  6


arr    2  3  4  7  11
i      0  1  2  3  4
//diff 2  2  2  4  7


arr    1  2  4  5  6
i      0  1  2  3  4
//diff 1  1  2  2  2

// class Solution {
// public:
// 	int findKthPositive(vector<int>& arr, int k) {
// 		int mn = 0;
// 		for (int i = 0; i < arr.size(); i++) {
// 			if (arr[i] - mn > 1) {
// 				k -= arr[i] - mn + 1;
// 				if (k <= 0)
// 					return arr[i] - k;
// 			}
// 			mn = arr[i];
// 		}
// 		return mn + k;
// 	}
// };

// class Solution {
// public:
// 	int findKthPositive(vector<int>& arr, int k) {
// 		for (int i = 0; i < arr.size(); i++) {
// 			int diff = arr[i] - (i + 1);
// 			if (diff >= k) {
// 				return arr[i] - 1 - (diff - k);
// 			}
// 		}
// 		return arr[arr.size() - 1] - (arr[arr.size() - 1] - (arr.size() - 1 + 1) - k);
// 	}
// };
