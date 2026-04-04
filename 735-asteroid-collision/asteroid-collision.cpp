class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>ans;
        stack<int>st;
        int n = asteroids.size();
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push(asteroids[i]);
                continue;
            }
            else if(!st.empty() && st.top()>0 && asteroids[i]>0){
                st.push(asteroids[i]);
                continue;
            }
            else if(!st.empty() && st.top()<0 && asteroids[i]<0){
                st.push(asteroids[i]);
                continue;
            }
            else if(!st.empty() && asteroids[i]>0 && st.top()<0){
                st.push(asteroids[i]);
                continue;
            }
            if(!st.empty() && (asteroids[i]+st.top())==0){
                cout<<"3"<<endl;
                st.pop();
                continue;
            }
            if(asteroids[i]<0){
                while(!st.empty() && st.top()>0 && st.top()<abs(asteroids[i])){
                    cout<<"1"<<endl;
                    st.pop();
                }
                if(!st.empty() && st.top()+asteroids[i] == 0){
                    st.pop();
                    continue;
                }
                if(st.empty() || st.top()<0) st.push(asteroids[i]);
            }
        }
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};