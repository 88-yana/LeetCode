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
	ListNode* headOfList;
	Solution(ListNode* head) {
		srand(time(NULL));
		headOfList = head;
	}

	int getRandom() {
		ListNode* cur = headOfList;
		int ans;
		int i = 1;
		while (cur != nullptr) {
			if (rand() % i == 0) {
				ans = cur->val;
			}
			cur = cur->next;
			i++;
		}
		return ans;
	}
};

// 1 * 1/2 * 2/3 * 3/4
//     1/2 * 2/3 * 3/4
//           1/3 * 3/4
//                 1/4

// class Solution {
// public:
// 	int sizeOfList;
// 	ListNode* headOfList;
// 	Solution(ListNode* head) {
// 		srand(time(NULL));

// 		ListNode* cur = head;
// 		int cnt = 0;
// 		while (cur != nullptr) {
// 			cnt++;
// 			cur = cur->next;
// 		}
// 		headOfList = head;
// 		sizeOfList = cnt;
// 	}

// 	int getRandom() {
// 		ListNode* cur = headOfList;
// 		int r = rand() % sizeOfList;
// 		for (int i = 0; i < r; i++) {
// 			cur = cur->next;
// 		}
// 		return cur->val;
// 	}
// };