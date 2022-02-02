#include<iostream>
#include<vector>
#include<algorithm>
#include "treeNode.h"
#include "N_tree.h"
using namespace std;

void solve_preorderTraversal(TreeNode* root, vector<int>& res)
{
	if (root == nullptr) return;
	res.emplace_back(root->val);
	solve_preorderTraversal(root->left, res);
	solve_preorderTraversal(root->right, res);
}

vector<int> preorderTraversal(TreeNode* root) {
	// 前序遍历
    vector<int> res;
	solve_preorderTraversal(root, res);
	return res;
}

void solve_postorderTraversal(TreeNode* root, vector<int>& res)
{
	if (root == nullptr) return;
	solve_postorderTraversal(root->left, res);
	solve_postorderTraversal(root->right, res);
	res.emplace_back(root->val);
}

vector<int> postorderTraversal(TreeNode* root) {
	// 后序遍历
	vector<int> res;
	solve_postorderTraversal(root, res);
	return res;
}

int maxDepth(Node* root) {
	if (root == nullptr) return 0;
	if (root->children.size() <= 0) return 1;
	int res = 0;
	int temp = 0;
	for (auto node : root->children)
	{
		temp = 1 + maxDepth(node);
		if (res < temp)
			res = temp;
	}
	return res;
}

void findAllSubstrPos(string &s, string &p, vector<int> &res)
{
	int idx = 0;
	idx = s.find(p, idx);
	while (idx != string::npos)
	{
		res.emplace_back(idx);
		if (idx >= s.size() - 1)
			break;
		idx = s.find(p, idx + 1);
	}
}

vector<int> findAnagrams(string s, string p) {
	vector<int> res;
	if (s.size() <= 0) return res;
	if (s.size() < p.size()) return res;
	int idx;
	bool next_flag = true;
	while (next_flag)
	{
		findAllSubstrPos(s, p, res);
		next_flag = next_permutation(p.begin(), p.end());
	}
	return res;
}

string dayOfTheWeek(int day, int month, int year) {
	int all_days = 0;
	// 1971.1.1是周五
	string week_days[7] = { "Friday", "Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday" };
	for (int i = 1971; i < year; i++)
	{
		if (i % 100 == 0 && i % 400 == 0)
		{
			all_days += 366;
		}
		else if (i % 100 != 0 && i % 4 == 0)
		{
			all_days += 366;
		}
		else
		{
			all_days += 365;
		}
	}
	for (int i = 1; i < month; i++)
	{
		if (i == 2)
		{
			if (year % 100 == 0 && year % 400 == 0)
			{
				all_days += 29;
			}
			else if (year % 100 != 0 && year % 4 == 0)
			{
				all_days += 29;
			}
			else
			{
				all_days += 28;
			}
		}
		else if (i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 12)
		{
			all_days += 31;
		}
		else
		{
			all_days += 30;
		}
	}
	all_days += day - 1;
	return week_days[all_days % 7];
}

string reversePrefix(string word, char ch) {
	string res;
	bool is_before = true;
	if (find(word.begin(), word.end(), ch) == word.end())
		return word;
	for (auto c : word)
	{
		if (is_before)
			res.insert(res.begin(), c);
		else
			res.push_back(c);
		if (c == ch && is_before)
			is_before = false;
	}
	return res;
}

int main()
{
	string a = "abcd";
	char b = 'z';
	string x = reversePrefix(a, b);
	return 0;
}