/*
 * @Author: FrankTudor
 * @Date: 2022-05-02 00:00:51
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-05-02 00:07:09
 */
/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int size = 0;
        ListNode* traversal_ptr = head;
        while(traversal_ptr != nullptr){
            size++;
            traversal_ptr = traversal_ptr->next;
        }
        size/=2;
        while(size--){
            head = head->next;
        }
        return head;
    }
};
// @lc code=end

