class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // 9, 7, 6, 5, 2, 2
        int n = cost.size();
        sort(cost.begin(), cost.end(), greater<int>());
        int minCost = 0;
        int i=0;
        while(i<n){  //3 2 1
            minCost += cost[i];
            i++;
            if(i<n) minCost += cost[i];
            i += 2;
        }
        return minCost;
    }
};