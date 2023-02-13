#include <bits/stdc++.h>
using namespace std;

#define LEFT 0
#define RIGHT 1

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals);
};

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](vector<int> & s, vector<int> & t) {return s[0] < t[0];});
	sort(intervals.begin(), intervals.end(), [](vector<int> & s, vector<int> & t) {return s[1] - s[0] < t[1] - t[0];});
	vector<vector<int>> range;
	int ans = 0;
	range.push_back(intervals[0]);

	for (int i = 1; i < intervals.size(); i++) {
		int change = 0;
		for (int j = 0; j < range.size(); j++) {
			if (intervals[i][LEFT] <= range[j][RIGHT]) {
				if (range[j][RIGHT] < intervals[i][RIGHT]) {
					range[j][RIGHT] = intervals[i][RIGHT];
					change++;
				}
			}
			if (range[j][LEFT] <= intervals[i][RIGHT]) {
				if (intervals[i][LEFT] < range[j][LEFT]) {
					range[j][LEFT] = intervals[i][LEFT];
					change++;
				}
			}
			if (!change) {
				if (range[j][LEFT] <= intervals[i][LEFT]) {
					if (intervals[i][RIGHT] <= range[j][RIGHT]) {
						ans++;
						cout << "要らないのは " << intervals[i][LEFT] << " " << intervals[i][RIGHT] << endl; 
						change = true;
					}
				}
			}
			else if (change == 2)
				ans++;
			if (change)
				break ;
		}
		if (change)
			continue ;
		range.push_back(intervals[i]);
		for (auto u : range)
		{
			cout << "range " << i << " " << u[0] << " " << u[1] << endl;
		}
	}
	cout << "----------------------------------------------------------------" << endl;
	for (auto u : range)
	{
		cout << "range "  << " " << u[0] << " " << u[1] << endl;
	}
	cout << "ans is " << ans << endl;
	return ans;
}


// sort(P.begin(), P.end(), [](pair<int, int> & s, pair<int, int> & t) {return s.second > t.second;});
int main(){
	Solution obj;
	vector<vector<int>> intervals;
	// intervals.push_back({5, 10});
	// intervals.push_back({1, 2});
	// intervals.push_back({3, 4});
	// intervals.push_back({2, 3});
	// intervals.push_back({1, 3});
	// intervals.push_back({2, 4});
	// intervals.push_back({6, 9});
	// intervals.push_back({2, 8});
	intervals.push_back({1, 100});
	intervals.push_back({11, 22});
	intervals.push_back({1, 11});
	intervals.push_back({2, 12});
	obj.eraseOverlapIntervals(intervals);
	
	
	cout << "----------------------------------------------------------------" << endl;
	for (vector<int> p : intervals)
		cout << p[0] << " " << p[1] << endl;
	return 0;
}