class Solution {
    // int solve(vector<int>&coins, int amount, int ind){
    //     if(amount<0) return 1e9;
    //     if(ind==0){
    //         if(amount % coins[ind] == 0){
    //             return amount/coins[ind];
    //         }
    //         return 1e9;
    //     }
    //     int pick = 1 + solve(coins, amount-coins[ind], ind);
    //     int notPick = solve(coins, amount, ind-1);
    //     return min(pick, notPick);
    // }

    int solve(vector<int>&coins, int amount, int ind, vector<vector<int>>&dp){
        if(amount<0) return 1e9;
        if(ind==0){
            if(amount % coins[ind] == 0){
                return amount/coins[ind];
            }
            return 1e9;
        }
        if(dp[ind][amount] != -1) return dp[ind][amount];
        int pick = 1 + solve(coins, amount-coins[ind], ind, dp);
        int notPick = solve(coins, amount, ind-1, dp);
        return dp[ind][amount] = min(pick, notPick);
    }

public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        // int ans = solve(coins, amount, n-1);
        // return ans >= 1e9 ? -1 : ans;

        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = solve(coins, amount, n-1, dp);
        return ans >= 1e9 ? -1 : ans;
    
        // vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        // for(int i=0; i<n; i++){
        //     dp[i][0] = 0;
        // }

        // for(int j = 0; j <= amount; j++) {
        //     if(j % coins[0] == 0) dp[0][j] = j / coins[0];
        //     else dp[0][j] = 1e9;
        // }


        // for(int i=1; i<n; i++){
        //     for(int j=1; j<=amount; j++){
        //         int pick = 1e9;
        //         if(j >= coins[i]) pick = 1 + dp[i][j-coins[i]];
        //         int notPick = dp[i-1][j];
        //         dp[i][j] = min(pick, notPick);
        //     }
        // }
        // // for(int i=0; i<dp.size(); i++){
        // //     for(int j=0; j<dp[0].size(); j++){
        // //         cout<<dp[i][j]<<"    ";
        // //     }
        // //     cout<<endl;
        // // }
        // return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];



        // return dp[n-1][amount] >= 1e9 ? -1 : dp[n-1][amount];
    }
};