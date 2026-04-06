class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0, n=s.length();
        int maxLen = 0;
        unordered_map<char,int> mp;  //{char, last index}
        while(j<n){
            if(mp.find(s[j]) != mp.end() && mp[s[j]]>=i){
                i = mp[s[j]] + 1;
            }
            maxLen = max(maxLen, j-i+1);
            mp[s[j]] = j;
            j++;
        }
        return maxLen;
    }
};