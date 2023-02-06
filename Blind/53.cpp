#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *current = root;
		TreeNode *temp;

		temp = p;
		if (p->val > q->val)
		{
			p = q;
			q = temp;
		}
		while (1)
		{
			if (current->left == NULL || current->right == NULL)
				break ;
			if (current->val < p->val) {
				current = current->right;
				continue ;
			}
			if (current->val > q->val) {
				current = current->left;
				continue ;
			}
			break ;
		}
		return current ;
	}
};