class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        vector<int>v;
        bool flag = true;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(nums[i] == nums[j] && nums[j] == nums[k]){
                        int dist = abs(i-j) + abs(j-k) + abs(k-i);
                        v.push_back(dist);
                        flag = false;
                    }
                }
            }
        }
        if(flag) return -1;
        sort(v.begin(), v.end());
        return v[0];
    }
};