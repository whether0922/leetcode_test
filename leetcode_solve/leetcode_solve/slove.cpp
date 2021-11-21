#include<iostream>
#include<vector>
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

int main()
{
	return 0;
}