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
	int DFS(TreeNode* current, TreeNode* p, TreeNode* q, TreeNode **ans) {
		int has = 0;
		if (current->left != NULL)
			has += DFS(current->left, p, q, ans);
		if (current->right != NULL)
			has += DFS(current->right, p, q, ans);
		if (current == p || current == q)
			has++;
		if (has == 2)
		{
			*ans = current;
			has++;
		}
		return has;
	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		TreeNode *ans;
		DFS(root, p, q, &ans);
		return ans;
	}
};
