class Solution {
public:
    int numberOfSpecialChars(string word) {
        int count = 0;
        unordered_map<char,int>mp;
        for(auto &ch: word){
            mp[ch]++;
        }
        for(auto &ch: word){
            if(islower(ch)){
                char temp = toupper(ch);
                if(mp[temp]>0){
                    count++;
                    mp[temp] = -1;
                    mp[ch] = -1;
                }
            }
            else{
                char temp = tolower(ch);
                if(mp[temp]>0){
                    count++;
                    mp[temp] = -1;
                    mp[ch] = -1;
                }
            }
        }
        return count;
    }
};