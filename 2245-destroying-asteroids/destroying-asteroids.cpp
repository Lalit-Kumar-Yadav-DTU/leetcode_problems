class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        sort(asteroids.begin(), asteroids.end());  // 3,5,9,19,21     // 4,4,9,23
        long long sum = mass;
        for(int i=0; i<n; i++){
            if(asteroids[i] > sum){
                return false;
            }
            sum += asteroids[i];
        }
        return true;
    }
};