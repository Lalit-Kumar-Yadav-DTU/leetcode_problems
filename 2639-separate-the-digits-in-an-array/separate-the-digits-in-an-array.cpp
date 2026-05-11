class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>v;
        int n = nums.size();
        for(int i=n-1; i>=0; i--){
            int val = nums[i];
            while(val>0){
                v.push_back(val%10);
                val /= 10;
            }
        }
        reverse(v.begin(), v.end());
        return v;
    }
};