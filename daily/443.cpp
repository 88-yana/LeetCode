#include <bits/stdc++.h>
using namespace std;

class Solution {
	public:
	int compress(vector<char>& chars) {
		int type = 0;
		int digit = 0;
		for (int i = 0; i < chars.size(); i++) {
			int j = i;
			while (j < chars.size() - 1 && chars[j] == chars[j + 1])
				j++;

			chars[type + digit] = chars[i];
			type++;
			if (j - i != 0) {
				string temp = to_string(j - i + 1);
				for (int k = type + digit; k - (type + digit) < temp.size(); k++) {
					chars[k] = temp[k - (type + digit)]; 
				}
				digit += temp.size();
			}
			i = j;
		}
		return type + digit;
	}
};