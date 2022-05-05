/*
 * @Author: FrankTudor
 * @Date: 2022-05-05 10:39:07
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 60.64 % of cpp submissions
 * Your memory usage beats 76.97 % of cpp submissions (14.3 MB)
 * @LastEditTime: 2022-05-05 11:06:22
 */
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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


class Solution : public ListNode{
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr){return list2;}
        if(list2 == nullptr){return list1;}
        ListNode *mergedListHead, *iter;
        if(list1->val < list2->val){
            mergedListHead = list1;
            list1 = list1->next;
        }
        else{
            mergedListHead = list2;
            list2 = list2->next;
        }
        iter = mergedListHead;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                iter->next = list1;
                list1 = list1->next;
            }else{
                iter->next = list2;
                list2 = list2->next;
            }
                iter = iter->next;
        }
        if(list1 == nullptr){
            iter->next = list2;
        }
        else if(list2 == nullptr){
            iter->next = list1;
        }

        return mergedListHead;
    }

};
// @lc code=end

