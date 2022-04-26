/*
 * @Author: FrankTudor
 * @Date: 2022-04-26 20:34:48
 * @LastEditors: FrankTudor
 * @Description: This file is created, edited, contributed by FrankTudor
 * @LastEditTime: 2022-04-26 23:00:39
 */
/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

// @lc code=start

// #include<iostream>
//   struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//   };
class Solution {
public:

    //Your runtime beats 97.87 % of cpp submissions
    // Your memory usage beats 68.31 % of cpp submissions (11.1 MB)
    ListNode* reverse(ListNode * start, ListNode* end, ListNode*& beforeEnd ){//[start, end)
        ListNode* tailToArrow = start;
        ListNode* arrowToTail = start->next;
        ListNode* tmp;
        // print(start,end);
        while(arrowToTail != end){
            tmp = arrowToTail->next;
            arrowToTail->next = tailToArrow;
            tailToArrow = arrowToTail;
            arrowToTail = tmp;
        }
        start->next = end;
        beforeEnd = start;

        return tailToArrow;      

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* front, *end;
        int stride = 0;
        front = end = head;
        bool flag = true;
        ListNode* beforeEnd = nullptr;
        while(end != nullptr){
            stride = 0;
            end = front;
            while(stride < k){
                if(end == nullptr){return head;}
                end = end->next;
                stride++;
            }
            if(flag){
                head = reverse(front, end, beforeEnd);
                // print(head, beforeEnd);

                flag = false;
            }
            else{ 
                ListNode* formerBeforeEnd = beforeEnd;
                formerBeforeEnd->next = reverse(front, end, beforeEnd);
                // print(formerBeforeEnd->next, beforeEnd);
            }
            front = end;
        }
        return head;
    }
    // void print(ListNode* start, ListNode* end){
    //     while(start != end){
    //         printf("%d, ",start->val);
    //         start=start->next;
    //     }
    //     printf("\n");
    // }
};
// @lc code=end

// int main(){
//     Solution s;
    
//     ListNode* list = new ListNode[5];
//     list[0].val = 1;
//     for(int i = 0;i < 4; i++){
//         list[i].next = &list[i+1];
//         list[i+1].val  = i+2;
//     }
//     list[4].next = nullptr;
//     auto _list = s.reverseKGroup(list,2);
//     for(auto tmp = _list; tmp != nullptr; tmp = tmp->next){
//         printf("%d, ", tmp->val);
//     }
//     delete[] list;
    
//     return 0;
// }