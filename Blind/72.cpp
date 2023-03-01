#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	int eraseOverlapIntervals(vector<vector<int>>& intervals);
};

int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	sort(intervals.begin(), intervals.end(), [](vector<int> & s, vector<int> & t) {return s[1] < t[1];});
	//小刻みに
	int ans = 0;
	int right = intervals[0][1];
	for (int i = 1; i < intervals.size(); i++) {
		if (intervals[i][0] < right)
			ans++;
		else
			right = intervals[i][1];
	}
	return ans;
}
// sort(P.begin(), P.end(), [](pair<int, int> & s, pair<int, int> & t) {return s.second > t.second;});


// int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
// 	int ans = 0;
// 	for (int i = 0; i < intervals.size() - 1; i++) {
// 		vector<int> a = intervals[i];
// 		for (int j = i + 1; j < intervals.size(); j++) {
// 			vector<int> b = intervals[j];
// 			if (b[LEFT] == a[LEFT] && a[RIGHT] == b[RIGHT]) {
// 				ans++;
// 				intervals.erase(intervals.begin() + j);
// 				j--;
// 			}
// 		}
// 	}

// 	vector<set<int>> overlap(intervals.size());
// 	for (int i = 0; i < intervals.size() - 1; i++) {
// 		vector<int> a = intervals[i];
// 		for (int j = i + 1; j < intervals.size(); j++) {
// 			vector<int> b = intervals[j];
// 			if (a[LEFT] < b[RIGHT])
// 			{
// 				if (b[LEFT] < a[RIGHT])
// 				{
// 					overlap[i].insert(j);
// 					overlap[j].insert(i);
// 				}
// 			}
// 		}
// 	}


// 	vector<pair<int, int>> temp(intervals.size());
// 	for (int i = 0; i < overlap.size(); i++) {
// 		temp[i].first = overlap[i].size();
// 		temp[i].second = i;
// 	}

// 	int i = 0;
	
// 	while (1)
// 	{
// 		int max_size = -1;
// 		int index;
// 		for (int j = 0; j < temp.size(); j++)
// 		{
// 			if (max_size < temp[j].first)
// 			{
// 				max_size = temp[j].first;
// 				index = temp[j].second;
// 			}
// 		}
// 		for (set<int> u : overlap)
// 			cout << "size is " << u.size() << " " << endl;
// 		bool dependency = false;
// 		for (int j = 0; j < overlap.size(); j++)
// 			if (overlap[j].size())
// 				dependency = true;
// 		if (!dependency)
// 			break ;
// 		for (int u : overlap[index])
// 		{
// 			overlap[u].erase(index);
// 			temp[u].first--;
// 		}
// 		overlap[index].clear();
// 		temp[index].first = 0;
// 		for (auto u : overlap)
// 		{
// 			cout << "overlap is " << i << endl;
// 			for (auto v : u)
// 			    cout << v << " ";
// 			cout << endl;
// 		}
// 		ans++;
// 		i++;
// 	}
// 	cout << "ans is" << ans << endl;
// 	return ans;
// }


// int Solution::eraseOverlapIntervals(vector<vector<int>>& intervals) {
	
// 	// sort(intervals.begin(), intervals.end(), [](vector<int> & s, vector<int> & t) {return s[1] - s[0] < t[1] - t[0];});
// 	vector<vector<int>> range;
// 	int ans = 0;
// 	range.push_back(intervals[0]);

// 	for (int i = 1; i < intervals.size(); i++) {
// 		int change = 0;
// 		for (int j = 0; j < range.size(); j++) {
// 			if (intervals[i][LEFT] <= range[j][RIGHT]) {
// 				if (range[j][RIGHT] < intervals[i][RIGHT]) {
// 					range[j][RIGHT] = intervals[i][RIGHT];
// 					change++;
// 				}
// 			}
// 			if (range[j][LEFT] <= intervals[i][RIGHT]) {
// 				if (intervals[i][LEFT] < range[j][LEFT]) {
// 					range[j][LEFT] = intervals[i][LEFT];
// 					change++;
// 				}
// 			}
// 			if (!change) {
// 				if (range[j][LEFT] <= intervals[i][LEFT]) {
// 					if (intervals[i][RIGHT] <= range[j][RIGHT]) {
// 						ans++;
// 						cout << "要らないのは " << intervals[i][LEFT] << " " << intervals[i][RIGHT] << endl; 
// 						change = true;
// 					}
// 				}
// 			}
// 			else if (change == 2)
// 				ans++;
// 			if (change)
// 				break ;
// 		}
// 		if (change)
// 			continue ;
// 		range.push_back(intervals[i]);
// 		for (auto u : range)
// 		{
// 			cout << "range " << i << " " << u[0] << " " << u[1] << endl;
// 		}
// 	}
// 	cout << "----------------------------------------------------------------" << endl;
// 	for (auto u : range)
// 	{
// 		cout << "range "  << " " << u[0] << " " << u[1] << endl;
// 	}
// 	cout << "ans is " << ans << endl;
// 	return ans;
// }


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
	// intervals.push_back({2, 4});
	// intervals.push_back({0, 2});
	// intervals.push_back({1, 3});
	// intervals.push_back({3, 5});
	// intervals.push_back({3, 5});
	// intervals.push_back({4, 6});
	// intervals.push_back({1, 3});
	// intervals.push_back({1, 2});
	// intervals.push_back({1, 2});
	// intervals.push_back({1, 2});
	intervals.push_back({-39,21});
intervals.push_back({-38,5});
intervals.push_back({-67,67});
intervals.push_back({23,37});
intervals.push_back({83,95});
intervals.push_back({-71,-19});
intervals.push_back({-19,64});
intervals.push_back({4,31});
intervals.push_back({37,96});
intervals.push_back({30,57});
intervals.push_back({-19,12});
intervals.push_back({53,75});
intervals.push_back({-54,83});
intervals.push_back({-32,38});
intervals.push_back({-18,16});
intervals.push_back({-60,9});
intervals.push_back({92,93});
intervals.push_back({-12,20});
intervals.push_back({-37,35});
intervals.push_back({19,36});
intervals.push_back({46,56});
intervals.push_back({45,52});
intervals.push_back({-67,-29});
intervals.push_back({30,67});
intervals.push_back({67,79});
intervals.push_back({52,98});
intervals.push_back({59,60});
intervals.push_back({-63,7});
intervals.push_back({7,20});
intervals.push_back({16,59});
intervals.push_back({83,96});
intervals.push_back({-59,-3});
intervals.push_back({33,41});
intervals.push_back({-67,-49});
intervals.push_back({-15,67});
	obj.eraseOverlapIntervals(intervals);
	
	
	cout << "----------------------------------------------------------------" << endl;
	for (vector<int> p : intervals)
		cout << p[0] << " " << p[1] << endl;
	return 0;
}