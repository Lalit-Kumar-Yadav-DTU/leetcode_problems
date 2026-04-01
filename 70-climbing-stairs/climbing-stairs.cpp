class Solution{    
public:
    int climbStairs(int n){
        if(n==1) return 1;
        if(n==2) return 2;
        int p1 = 1;
        int p2 = 2;
        int curr = 0;
        for(int i=3; i<=n; i++){
            curr = p2 + p1;
            p1 = p2;
            p2 = curr;
        }
        return p2;
    }
};