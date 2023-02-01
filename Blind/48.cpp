#include <bits/stdc++.h>
using namespace std;

class Node{
	public:
		string word;
		bool isTerminal;
		vector<Node*> next;
		Node():next(26,NULL) {
			isTerminal = false;
		}
};

class Solution {
	void put(string &s,int index, Node* current) { // adds a word to the trie
		int c_a = s[index]-'a';
		if (!current->next[c_a]) {
			Node* newnode = new Node();
			current->next[c_a] = newnode;
		}
		if (index != s.size() - 1) {
			put(s, index + 1, current->next[c_a]);
		}
		else {
			current->next[c_a]->isTerminal = true;
			current->next[c_a]->word = s;
		}
	}

void dfs(vector<vector<char>>& board,int i,int j,Node* t,set<string>& res,vector<vector<bool>>& visit){ 
	if(i<0 || j<0 || i>=board.size() || j>= board[0].size())return; //** dfs call to search for word
	char x = board[i][j]-'a';
	t = t->next[x];
	if(visit[i][j] || !t)return ;
   
	if(t->isTerminal)res.insert((t->word));
	visit[i][j] = true;
	dfs(board,i+1,j,t,res,visit);
	dfs(board,i-1,j,t,res,visit);
	dfs(board,i,j+1,t,res,visit);
	dfs(board,i,j-1,t,res,visit);
	visit[i][j]= false;
}

public:
	vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
		set<string> res;
		Node* t = new Node();
		for(string &s:words){
			put(s,0,t);
		}
	vector<vector<bool>> visit(board.size(),vector<bool>(board[0].size(),false));
		for(int i = 0 ;i<board.size();i++){
			for(int j=0;j<board[0].size();j++){
			   dfs(board,i,j,t,res,visit);
			}
		}
		vector<string> ans(res.begin(),res.end());
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