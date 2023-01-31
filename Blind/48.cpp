#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
	vector<string> ans;
	void DFS(vector<vector<char>>& board, string word, int i, int j, int index) {
		const bool is_in_yrange = 0 <= i && i <= board.size();
		const bool is_in_xrange = 0 <= j && j <= board[i].size();
		if (!(is_in_yrange && is_in_xrange))
			return ;
		if (index > word.size())
			return ;
		if (board[i][j] == word[index]) {
			if (index == word.size() - 1) {
				ans.push_back(word);
				return ;
			}
			DFS(board, word, i - 1, j, index + 1);
			DFS(board, word, i + 1, j, index + 1);
			DFS(board, word, i, j - 1, index + 1);
			DFS(board, word, i, j + 1, index + 1);
		}
	}
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				for (int k = 0; k < words.size(); k++) {
					if (board[i][j] == words[k][0])
						DFS(board, words[k], i, j, 0);
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
	Solution sol;
	cout << "ans is " << sol.findWords(board, words)[0] << endl;
	cout << "ans is " << sol.findWords(board, words)[1] << endl;
}