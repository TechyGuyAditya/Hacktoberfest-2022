class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (root == NULL)
        {
            return false;
        }
        if (root->left == NULL and root->right == NULL and targetSum - root->val == 0)
        {
            return true;
        }
        return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val);
    }
};