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
#include<stack>
using std::stack;
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        if(root == nullptr){return 0;}
        stack<TreeNode*> pList;
        pList.push(root);
        int count=0;
        TreeNode* active, *last_top;
        while(pList.size()){
            active = pList.top();
            if(active ->left!= nullptr){
                last_top = active;
                pList.push(active->left);
                continue;
            }
            else if(active->right != nullptr){
                last_top = active;
                pList.push(active->right);
                continue;
            }
            else{//left == nullptr && right == nullptr
                last_top = pList.top();
                pList.pop();
                active = pList.top();
                if(last_top == active->left && active->right != nullptr){
                    pList.push()
                }//todo
                if(last_top == pList.top()->right){

                }
                
            }
        }
        return count;
    }
};

int main(void){

    return 0;
}