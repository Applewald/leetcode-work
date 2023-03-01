/*
 * Created by hexiaoyu 
 * on 2023/3/1 16:08
 * https://leetcode.cn/problems/minimum-depth-of-binary-tree/
 * easy
 */
#include "vector"
#include "queue"
#include "stack"

using namespace std;

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
    int minDepth(TreeNode* root) {
        if(!root) return 0;

        // 层次遍历
        queue<TreeNode*> que;

        TreeNode *p;
        que.emplace(root);

        int this_level_num = 1;
        int next_level_num = 0;
        int res = 1;

        while(!que.empty()){
            p = que.front();
            que.pop();
            this_level_num--;

            if(p->left){
                que.emplace(p->left);
                next_level_num++;
            }
            if(p->right){
                que.emplace(p->right);
                next_level_num++;
            }
            if(!p->left and !p->right){
                return res;
            }

            if(this_level_num == 0){
                if(next_level_num > 0) res++;
                this_level_num = next_level_num;
                next_level_num = 0;
            }
        }
        return res;
    }
};
