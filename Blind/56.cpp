#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> mp;
		for (int i = 0; i < t.length(); i++)
			mp[t[i]]++;
		for (int i = 0; i < s.length(); i++) {
			if (mp[s[i]] == 0)
				return false;
			mp[s[i]]--;
		}
		for (int i = 0; i < t.length(); i++)
			if (mp[t[i]] != 0)
				return false;
		return true;
	}
};