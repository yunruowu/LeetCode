class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> E;
        ans.push_back(E);
        for(int i = 0; i<nums.size(); i++){
            int len = ans.size();
            for(int j = 0; j<len; j++){
                vector<int> cur = ans[j];
                cur.push_back(nums[i]);
                ans.push_back(cur);
            }
        }
        return ans;
    }
};