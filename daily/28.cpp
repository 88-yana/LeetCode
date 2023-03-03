#include <bits/stdc++.h>
using namespace std;
// class Solution {
// public:
// 	int strStr(string haystack, string needle) {
// 		return haystack.find(needle);
// 	}
// };

// class Solution {
// public:
// 	int strStr(string haystack, string needle) {
// 		for (int i = 0; i < haystack.length(); i++) {
// 			if (haystack.substr(i, needle.size()) == needle)
// 				return i;
// 		}
// 		return -1;
// 	}
// };

class Solution {
public:
	int strStr(string haystack, string needle) {
		for (int i = 0; i < haystack.length(); i++) {
			if (haystack.length() - i < needle.length())
				return -1;
			for (int j = 0; j < needle.length(); j++) {
				if (haystack[i + j] != needle[j])
					break ;
				if (j == needle.size() - 1)
					return i;
			}
		}
		return -1;
	}
};