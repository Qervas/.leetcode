/*
 * @Author: FrankTudor
 * @Date: 2022-05-05 16:19:18
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 76.47 % of cpp submissions
 * Your memory usage beats 54.13 % of cpp submissions (31.7 MB)
 * Edit in-place on "root2" tree. Be aware of data protection of "root2" tree
 * @LastEditTime: 2022-05-05 17:14:41
 */
/*
 * @lc app=leetcode.cn id=617 lang=cpp
 *
 * [617] 合并二叉树
 */
#include<stack>
#include<queue>
#include<vector>
// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr){return root2;}
        if(root2 == nullptr){return root1;}
        std::queue<TreeNode*> q;
        q.push(root1),q.push(root2);
        TreeNode *t1 = root1, *t2 = root2;
        while(q.size()){
            t1 = q.front();q.pop();
            t2 = q.front();q.pop();
            t2->val += t1->val;
            if(t1->left && t2->left){
                q.push(t1->left);
                q.push(t2->left);
            }
            else if(t2->left == nullptr){
                t2->left = t1->left;
            }
            if(t1->right && t2->right){
                q.push(t1->right);
                q.push(t2->right);
            }
            else if(t2->right == nullptr){
                t2->right = t1->right;
            }
        }
        return root2;

    }
};
// @lc code=end

