#include<iostream>
#include<vector>
#include<map>
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

int sumOfUnique(vector<int>& nums) {
	vector<int> alreadyIn;
	vector<int> multiNum;
	int res = 0;
	for (auto num : nums)
	{
		if (find(alreadyIn.begin(), alreadyIn.end(), num) == alreadyIn.end() && find(multiNum.begin(), multiNum.end(), num) == multiNum.end())
		{
			alreadyIn.emplace_back(num);
			res += num;
		}
		else if (find(alreadyIn.begin(), alreadyIn.end(), num) != alreadyIn.end() && find(multiNum.begin(), multiNum.end(), num) == multiNum.end())
		{
			res -= num;
			multiNum.emplace_back(num);
		}
	}
	return res;
}

int maxNumberOfBalloons(string text) {
	string aim = "balloon";
	if (text.size() < aim.size())
		return 0;
	int min_num = text.size() + 1;
	for (auto c : aim)
	{
		int c_num = count(text.begin(), text.end(), c);
		int self_num = count(aim.begin(), aim.end(), c);
		c_num = c_num / self_num;
		if (c_num == 0)
			return 0;
		if (c_num < min_num)
			min_num = c_num;
	}
	return min_num;
}

vector<int> goodDaysToRobBank(vector<int>& security, int time) {
	int length = security.size();
	vector<int> before_list(length);
	vector<int> after_list(length);
	for (int i = 1; i < length; i++)
	{
		if (security[i] <= security[i - 1])
			before_list[i] = before_list[i - 1] + 1;
		if (security[length - i] >= security[length - 1 - i])
			after_list[length - 1 - i] = after_list[length - i] + 1;
	}
	vector<int> res;
	for (int i = 0; i < length; i++)
	{
		if (before_list[i] >= time && after_list[i] >= time)
			res.emplace_back(i);
	}
	return res;
}

map<int, int> min_res;

int slove_jump(const vector<int>& nums, int index)
{
	if (index >= nums.size() - 1)
		return 0;
	if (min_res.find(index) != min_res.end())
		return min_res[index];
	if (nums[index] == 0)
		return 10001;
	int jump_num = 10001;
	for (int i = 1; i <= nums[index]; i++)
	{
		int next_jump = slove_jump(nums, index + i) + 1;
		if (jump_num > next_jump)
			jump_num = next_jump;
	}
	min_res[index] = jump_num;
	return jump_num;
}

int jump(vector<int>& nums) {
	if (nums.size() <= 0) return 0;
	int res = slove_jump(nums, 0);
	return res;
}

int removeElement(vector<int>& nums, int val) {
	vector<int>::iterator nums_ptr = find(nums.begin(), nums.end(), val);
	int res = 0;
	while (nums_ptr != nums.end())
	{
		res += 1;
		nums.erase(nums_ptr);
		nums_ptr = find(nums.begin(), nums.end(), val);
	}
	return res;
}

bool isSameTree(TreeNode* p, TreeNode* q) {
	if (p == nullptr && q == nullptr)
		return true;
	if (p == nullptr || q == nullptr)
		return false;
	if (p->val != q->val)
		return false;
	return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

int main()
{
	vector<int> a = { 0,1,2,2,3,0,4,2 };
	int x = removeElement(a, 2);
	return 0;
}