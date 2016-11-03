/**
 * Url: https://leetcode.com/problems/path-sum/
 */

#include "includes/Tree.h"
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > pathSum(TreeNode* root, int sum) {
        vector<vector<int> > result;
        result.clear();
        if(root == NULL) {
            return result;
        }
        
        vector<int> record;
        record.clear();

        dfs(root, 0, sum, record, result);

        return result;
    }

    void dfs(TreeNode* root, int length, int sum, vector<int>& rec, vector<vector<int> >& result) {
        if(root == NULL) {
            return;
        }

        if(root->val == sum && root->left == NULL && root->right == NULL) {
            vector<int> tmp;
            for(int i = 0; i < length; i++) {
                tmp.push_back(rec[i]);
            }
            tmp.push_back(root->val);
            result.push_back(tmp);
            return;
        }

        int val = sum - root->val;
        rec.push_back(root->val);

        dfs(root->left, length + 1, val, rec, result);  
        dfs(root->right, length + 1, val, rec, result);

        rec.pop_back();
    }};

