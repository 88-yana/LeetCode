#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MOD 1000000007
using ll = long long;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) ;
};

string dfs(TreeNode* root, set<string>& dup, set<string>& dchk, vector<TreeNode*>& res) {
	
	if (root == NULL)
		return "()";
	else
	{
		string s = "(" + to_string(root->val) + dfs(root->left, dup, dchk, res) + dfs(root->right, dup, dchk, res) + ")";
		if (dup.find(s) != dup.end())
		{
			if (dchk.find(s) == dchk.end())
			{
				dchk.insert(s);
				res.push_back(root);
			}
		}
		else
			dup.insert(s);
		return s;
	}
}

vector<TreeNode*> Solution::findDuplicateSubtrees(TreeNode* root) {
	string s;
	set<string> dup;
	set<string> dchk;
	vector<TreeNode*> res;
	s  = dfs(root, dup, dchk, res);
	cout << s << endl;
	return res;
}