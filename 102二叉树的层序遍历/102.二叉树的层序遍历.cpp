/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include<iostream>
#include<vector>
#include<queue>
#include<math.h>
using std::vector;
  struct TreeNode {
     int val;
     TreeNode *left;
      TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr){return {};}
        vector<vector<int>> ans;
        std::queue<TreeNode*> node_list;
        node_list.push(root);
        TreeNode* cur;
        size_t layer = 1, node_count = 1, fulltree_nodenum = 1;
        vector<int> node_seq;
        while(!node_list.empty()){
            cur = node_list.front();
            printf("%d, ", cur->val);
            if(node_count >= fulltree_nodenum){
                ans.push_back(node_seq);
                node_seq.clear();
                layer += 1;
                fulltree_nodenum += 
            }
            node_list.pop();
            if(cur->left != nullptr){
                node_list.push(cur->left);
            }
            node_count++;
            if(cur->right != nullptr){
                node_list.push(cur->right);
            }
            node_count++;
            
            

        }
        return ans;

    }
};
// @lc code=end

