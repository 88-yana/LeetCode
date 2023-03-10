#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	int sizeOfList;
	ListNode* headOfList;
	Solution(ListNode* head) {
		srand(time(NULL));

		ListNode* cur = head;
		int cnt = 0;
		while (cur != nullptr) {
			cnt++;
			cur = cur->next;
		}
		headOfList = head;
		sizeOfList = cnt;
	}

	int getRandom() {
		ListNode* cur = headOfList;
		int r = rand() % sizeOfList;
		for (int i = 0; i < r; i++) {
			cur = cur->next;
		}
		return cur->val;
	}
};