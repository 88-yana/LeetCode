#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;

int main() {
	// vector<int> nums = {3, 1, 3, 4, 5, 14, 7, 2, 9};
	// vector<int> nums = {2, 8};
	// Solution sol;
	// sol.minimumDeviation(nums);
	set<int> nums = {1, 5, 2, 3};
	cout << *nums.begin() << endl;
	cout << *(--nums.end()) << endl;
	cout << *--nums.end() << endl;
	return 0;
}