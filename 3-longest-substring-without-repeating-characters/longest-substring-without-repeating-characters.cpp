class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.length();
        int maxLen = 0;
        vector<int>v(256, 0);
        while(j<n){
            v[s[j]]++;
            while(v[s[j]]>1){
                v[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;
    }
};