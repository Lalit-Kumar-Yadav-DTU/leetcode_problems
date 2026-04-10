class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        int minDist = INT_MAX;;
        for(auto itr: mp){
            vector<int>&v = itr.second;
            if(v.size()<3) continue;
            for(int i=0; i+2<v.size(); i++){
                int dist = abs(v[i]-v[i+1]) + abs(v[i+1]-v[i+2]) + abs(v[i+2]-v[i]);  //optimized formula 2 * (v[i+2] - v[i])
                minDist = min(minDist,dist);
            }
        }
        if(minDist==INT_MAX) return -1;
        return minDist;
    }
};