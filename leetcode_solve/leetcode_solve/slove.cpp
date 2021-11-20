#include<iostream>
#include<vector>
#include "treeNode.h"
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

int main()
{
	return 0;
}