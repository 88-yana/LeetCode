#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<string> ans;
	vector<bool> seen;
	void DFS(vector<vector<char>>& board, vector<string>& words, int i, int j, int k, int index) {
		const bool is_in_y_range = 0 <= i && i < board.size();
		const bool is_in_x_range = 0 <= j && j < board[0].size();
		if (!is_in_y_range || !is_in_x_range)
			return ;
		if (seen[k])
			return ;
		char temp;
		temp = board[i][j];
		if (board[i][j] == words[k][index]) {
			if (index == words[k].size() - 1) {
				seen[k] = true;
				ans.push_back(words[k]);
				return ;
			}
			board[i][j] = 'A';
			DFS(board, words, i - 1, j, k, index + 1);
			DFS(board, words, i + 1, j, k, index + 1);
			DFS(board, words, i, j - 1, k, index + 1);
			DFS(board, words, i, j + 1, k, index + 1);
		}
		board[i][j] = temp;
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		seen.assign(words.size(), false);
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[0].size(); j++) {
				for (int k = 0; k < words.size(); k++) {
					if (board[i][j] == words[k][0])
						DFS(board, words, i, j, k, 0);
				}
			}
		}
		return ans;
	}
};

int main(void)
{
	vector<vector<char>> board = {
		{'o','a','a','n'},
		{'e','t','a','e'},
		{'i','h','k','r'},
		{'i','f','l','v'}
	};
	vector<string> words = {"oath","pea","eat","rain"};
	// vector<vector<char>> board = {
	// 	{'a','a'},
	// };
	// vector<string> words = {"aaa"};
	vector<string> ans;
	Solution sol;

	ans = sol.findWords(board, words);
	for (int i = 0; i < ans.size(); i++)
		cout << "ans is " << ans[i] << endl;
}