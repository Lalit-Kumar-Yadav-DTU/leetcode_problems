class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        int len = 1;
        q.push({beginWord,len});
        unordered_set<string> st(wordList.begin(), wordList.end());
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            string str = p.first;
            int val = p.second;
            if(str == endWord) return val;
            for(int i=0; i<beginWord.size(); i++){
                string originalStr = str;
                for(char ch = 'a'; ch<='z'; ch++){
                    str[i] = ch;
                    if(st.find(str) != st.end() && str != originalStr){   
                        q.push({str, val+1});
                        st.erase(str);
                    }
                }
                str = originalStr;
            }
        }
        return 0;
    }
};