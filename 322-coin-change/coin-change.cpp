class Solution {
    int solve(vector<int>& coins, int amount, int ind, vector<vector<int>>&dp){
        if(ind<0 || amount<0) return 1e9;
        if(amount==0) return 0;
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int pick = 1 + solve(coins, amount-coins[ind], ind, dp);
        int notPick = solve(coins, amount, ind-1, dp);
        return dp[ind][amount] = min(pick, notPick);
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n-1, dp);
        if(ans < 1e9) return ans;
        return -1;
    }
};