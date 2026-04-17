class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;  //{reverse(nums[i]), index i}
        int minDist = INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                minDist = min(minDist, i-mp[nums[i]]);
            }
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());
            mp[stoi(str)] = i;
        }
        return minDist==INT_MAX ? -1: minDist;
    }
};