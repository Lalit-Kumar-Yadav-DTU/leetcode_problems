class Solution {
public:
    int lengthOfLongestSubstring(string s){
        // int n = s.length();
        // int i = 0, j = 0;
        // int maxLen = 0;

        // unordered_map<char, int> mp;   // {char → last index}

        // while (j < n) {
        //     char ch = s[j];

        //     // If character seen before AND inside current window
        //     if (mp.find(ch) != mp.end() && mp[ch] >= i) {
        //         i = mp[ch] + 1;        // jump start just after previous index
        //     }

        //     mp[ch] = j;                // update last index
        //     maxLen = max(maxLen, j - i + 1);
        //     j++;
        // }

        // return maxLen;


        int maxLen = 0;
        int n = s.length();
        int i=0, j=0;
        unordered_map<char,int>mp;   //{char, freq}
        while(j<n){
            mp[s[j]]++;
            while(i<j && mp[s[j]]>1){
                mp[s[i]]--;
                i++;
            }
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        return maxLen;







        // int maxLen = 0;
        // int n = s.length();
        // for(int i=0; i<n; i++){
        //     unordered_map<char,int>mp;
        //     for(int j=i; j<n; j++){
        //         if(mp.find(s[j]) != mp.end()){
        //             break;
        //         }
        //         mp[s[j]]++;
        //         maxLen = max(maxLen, j-i+1);
        //     }
        // }
        // return maxLen;
    }
};