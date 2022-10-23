class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums[abs(nums[i])-1]*=-1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0) ans.push_back(i+1);
        }
        bool chk = 0;
        for(int i=0;i<n;i++)
        {
            if(abs(nums[i])==ans[1]) chk = 1;
        }
        if(chk) swap(ans[0],ans[1]);
        return ans;
    }
};