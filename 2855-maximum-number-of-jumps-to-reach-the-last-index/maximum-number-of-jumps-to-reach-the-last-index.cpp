class Solution {
    int solve(vector<int>&nums, int target, int n, int ind, vector<int>&dp){
        if(ind>=n-1) return 0;
        if(dp[ind] != -2) return dp[ind];
        int ans = -1;
        for(int i=ind+1; i<n; i++){
            if(abs(nums[i]-nums[ind]) <= target){
                int temp = solve(nums, target, n, i, dp);
                if(temp != -1){
                    ans = max(ans, 1+temp);
                }
            }
        }
        return dp[ind] = ans;
    }
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        int ind = 0;
        vector<int>dp(n, -2);
        return solve(nums, target, n, ind, dp);
    }
};