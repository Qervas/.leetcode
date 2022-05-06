/*
 * @Author: FrankTudor
 * @Date: 2022-05-05 17:17:56
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-06 23:29:33
 */
/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */
#include<iostream>
#include<queue>
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/


class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){return root;}
        root->next = nullptr;
        Node* most_left = root;        
        Node* child_iter, *parent_iter;
        while(most_left->left != nullptr){
            child_iter = most_left->left;
            parent_iter = most_left;
            while(parent_iter != nullptr){
                if(parent_iter->left != child_iter){
                    child_iter->next = parent_iter->left;
                    child_iter = child_iter->next;
                }
                if(parent_iter->right != nullptr){
                    child_iter->next = parent_iter->right;
                }
                parent_iter = parent_iter->next;
                child_iter = child_iter->next;
            }
            most_left = most_left->left;
        }
        return root;
        
    }
};
// @lc code=end

