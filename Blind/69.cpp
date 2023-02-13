#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int getSum(int a, int b);
};

int Solution::getSum(int a, int b) {
	int and_bit = 0;
	int exr_bit = 0;
	int sum = 0;
	and_bit = a & b;
	exr_bit = a ^ b;
	and_bit = and_bit << 1;
	while (1)
	{
		sum ^= and_bit;
		and_bit = sum & exr_bit;
		exr_bit = sum ^ exr_bit;
		sum ^= exr_bit;
	}
	return a + b;
}

// c = a & b
// b = a ^ b
// a = c << 1
int main() {
	Solution sol;
	sol.getSum(1, 2);
	cout << endl;
	sol.getSum(5, 9);
	cout << endl;
	sol.getSum(7, 4);
	cout << endl;
	sol.getSum(2, 30);
	cout << endl;
	sol.getSum(31, 46);
	cout << endl;
	sol.getSum(0, 100);
	cout << endl;
	return 0;
}