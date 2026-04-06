class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.length();
        int maxLen = 0;
        vector<int>v(256, -1);
        while(j<n){
            if(v[s[j]]!=-1 && v[s[j]]>=i){
                i = v[s[j]] + 1;
            }
            maxLen = max(maxLen, j-i+1);
            v[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};