class Solution {
    int reverseNum(int n){
        int y = 0;
        while(n>0){
            y = y*10 + n%10;
            n /= 10;
        }
        return y;
    }
public:
    int mirrorDistance(int n) {
        return abs(n-reverseNum(n));
    }
};