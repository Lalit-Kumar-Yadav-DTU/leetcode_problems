class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.length();
        vector<int>v(26,0);
        for(auto ch: text){
            v[ch-'a']++;
        }
        string tar = "balloon";
        for(auto itr: v){
            cout<<itr<<" ";
        } cout<<endl;
        int ans = INT_MAX;
        for(auto ch: tar){
            int freq = v[ch-'a'];
            if(ch=='l' || ch=='o'){
                freq /= 2;
            }
            ans = min(ans, freq);
        }
        return ans;
    }
};