class Solution {
    int reverseNum(int x){  //123
        int y = x%10;
        x /= 10;
        while(x>0){
            y = y*10 + x%10;
            x /= 10;
        }
        return y;
    }
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;  //{reverse(nums[i]), index i}
        int minDist = INT_MAX;
        for(int i=0; i<n; i++){
            if(mp.find(nums[i]) != mp.end()){
                minDist = min(minDist, i-mp[nums[i]]);
            }
            mp[reverseNum(nums[i])] = i;
        }
        return minDist==INT_MAX ? -1: minDist;
    }
};