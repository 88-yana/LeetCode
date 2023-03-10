#include <bits/stdc++.h>
using namespace std;


//折角kを定数として考えられるのだから，kを使って具体的に求めるべき
class Solution {
public:
	bool judge(vector<int>& piles, int& k, int& h) {
		int times = 0;
		for (int i = 0; i < piles.size(); i++) {
			times += (piles[i] + k - 1) / k;
			if (times > h) {
				return false;
			}
		}
		return true;
	}
	int minEatingSpeed(vector<int>& piles, int h) {
		int ok = *max_element(piles.begin(), piles.end());
		int ng = 0;
		while (ok - ng > 1) {
			int mid = ng + (ok - ng) / 2;
			if (judge(piles, mid, h)) {
				ok = mid;
			} else {
				ng = mid;
			}
		}
		return ok;
	}
};
