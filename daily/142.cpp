#include <bits/stdc++.h>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		map<ListNode*, int> mp;
		ListNode *cur = head;
		while (cur != NULL && mp[cur] != 2) {
			mp[cur]++;
			cur = cur->next;
		}
			return cur;
	}
};

// class Solution {
// public:
// 	ListNode *detectCycle(ListNode *head) {
// 		int cnt = 0;
// 		ListNode *cur = head;
// 		while (cur != NULL && cnt < 10002) {
// 			cur = cur->next;
// 		}
// 		if (cnt != 10001)
// 			return NULL;
// 		if (head->next) {
// 			if (head == head->next->next)
// 				return head;
// 		}
// 		ListNode *ok = cur;
// 		ListNode *ng = head;
// 		while (ok->next != ng) {
// 			int mid = ng + (ok - ng) / 2;
// 			if (judge(piles, mid, h)) {
// 				ok = mid;
// 			} else {
// 				ng = mid;
// 			}
// 		}
// 		return ok;
// 	}
// };