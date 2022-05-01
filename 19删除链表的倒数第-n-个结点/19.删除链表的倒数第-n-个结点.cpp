/*
 * @Author: FrankTudor
 * @Date: 2022-05-02 00:10:18
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * Your runtime beats 77.58 % of cpp submissions
 * Your memory usage beats 20.71 % of cpp submissions (10.5 MB)
 * @LastEditTime: 2022-05-02 00:42:04
 */
/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr){head->next = nullptr;delete head; return nullptr;}
        ListNode* vanguard= head,* support=head;
        int count = 0, size = 0;
        while(vanguard != nullptr){
            if(count == n+1){
                support = support->next;
            }
            else{
                count++;
            }
            vanguard = vanguard->next;
            size++;
            
        }//delete suuport->next
        if(count == n){//delete head
            ListNode* tmp = head;
            head = head->next;
            tmp->next = nullptr;
            delete tmp;
            return head;
        }
        ListNode* tmp = support->next;
        support->next = tmp->next;
        tmp->next = nullptr;
        delete tmp;

        return head;
    }
};
// @lc code=end

