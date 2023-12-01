// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * @class Solution
 * @brief Class that provides a solution for counting nodes equal to the average of the subtree.
 */
class Solution 
{
    public:
        /**
         * @brief Calculates the number of nodes in a subtree.
         * @param root The root of the subtree.
         * @return The number of nodes in the subtree.
         */
        int get_subtree_nodes(TreeNode * root)
        {
            if (root == nullptr)
                return 0;
            else
                return get_subtree_nodes(root->left) + get_subtree_nodes(root->right) + 1;
        }

        /**
         * @brief Calculates the sum of values in a subtree.
         * @param root The root of the subtree.
         * @return The sum of values in the subtree.
         */
        int get_subtree_nodes_sum_value(TreeNode * root)
        {
            if (root == nullptr)
                return 0;
            else
                return get_subtree_nodes_sum_value(root->left) + get_subtree_nodes_sum_value(root->right) + root->val;
        }

        /**
         * @brief Calculates the average of values in a subtree.
         * @param root The root of the subtree.
         * @return The average of values in the subtree.
         */
        int averageOfSubtree(TreeNode * root) 
        {
            if (root == nullptr)
                return 0;
            else
            {
                if ((get_subtree_nodes_sum_value(root) / get_subtree_nodes(root)) == root->val)
                    return averageOfSubtree(root->left) + averageOfSubtree(root->right) + 1;
                else
                    return averageOfSubtree(root->left) + averageOfSubtree(root->right);
            }
        }
};