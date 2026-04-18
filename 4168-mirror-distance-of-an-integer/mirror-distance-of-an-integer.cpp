class Solution {
    int reverseNum(int x){
        int revOfx = 0;
        while(x>0){
            revOfx = revOfx*10 + x%10;
            x /= 10;
        }
        return revOfx;
    }
public:
    int mirrorDistance(int n) {
        return abs(n-reverseNum(n));
    }
};