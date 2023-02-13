#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <set>
using namespace std;

#define LEFT 0
#define RIGHT 1

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals);
};

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	vector<vector<int>> range;
	range.push_back(intervals[0]);
	for (int i = 0; i < intervals.size(); i++) {
		bool change = false;
		for (int j = 0; j < range.size(); j++) {
			if (intervals[i][LEFT] <= range[j][RIGHT]) {
				if (range[j][RIGHT] <= intervals[i][RIGHT]) {
					range[j][RIGHT] = intervals[i][RIGHT];
					change = true;
				}
			}
			if (range[j][LEFT] <= intervals[i][RIGHT]) {
				if (intervals[i][LEFT] <= range[j][LEFT]) {
					range[j][LEFT] = intervals[i][LEFT];
					change = true;
				}
			}
			if (change)
				break ;
		}
		if (change)
			continue ;
		range.push_back(intervals[i]);
	}
	for (auto u : intervals)
	{
		cout << u[0] << " " << u[1] << endl;
	}
}