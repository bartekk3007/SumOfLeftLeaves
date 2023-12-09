#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode 
{
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};

int sumOfLeftLeaves(struct TreeNode *root) 
{
	if (root->left != NULL)
	{
		if (root->left->left == NULL && root->left->right == NULL)
		{
			if (root->right != NULL)
			{
				return sumOfLeftLeaves(root->left) + root->left->val + sumOfLeftLeaves(root->right);
			}
			else
			{
				return sumOfLeftLeaves(root->left) + root->left->val;
			}
		}
		else
		{
			if (root->right != NULL)
			{
				return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
			}
			else
			{
				return sumOfLeftLeaves(root->left);
			}
		}
		
	}
	else
	{
		if (root->right != NULL)
		{
			return sumOfLeftLeaves(root->right);
		}
		else
		{
			return 0;
		}
	}
}

struct TreeNode* newNode(int data)
{
	struct TreeNode* node = (struct TreeNode*) malloc(sizeof(struct TreeNode));
	if (node)
	{
		node->val = data;
		node->left = NULL;
		node->right = NULL;
		return node;
	}
}

int main(void)
{
	struct TreeNode* root = newNode(3);
	root->left = newNode(9);
	root->right = newNode(20);
	root->left->left = NULL;
	root->left->right = NULL;
	root->right->left = newNode(15);
	root->right->right = newNode(7);

	int sum = sumOfLeftLeaves(root);
	printf("%d\n", sum);

	return 0;
}