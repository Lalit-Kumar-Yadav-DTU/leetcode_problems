class Solution {
public:
    void sortColors(vector<int>& nums){
        int n = nums.size();
        int low=0, mid=0, high=n-1;
        //0 aane par low se swap karenge, aur mid and low ko ++ karenge, kyuki 0 ko low par daal diya hai
        //1 aane par kuch swap nhi karna kyuki mid 1 ko hi manage kar raha hai, bas mid++ kardo
        //2 aane par high se swap kardo, aur bas high-- karna hoga (mid ke saath kuch nhi karna kyuki [1,0,2,0] is case mai 2 ko 0 se swap karne ke baad agar mid++ kar diya to hum 0 ko low se swap karke uski sahi jagah par nhi pahucha payenge , some cases
        //1 1 1 1 1 0 2 0
        
        //1 0 2 0
        // )  




        while(mid<=high){
            if(nums[mid] == 0){
                swap(nums[low], nums[mid]);
                mid++;
                low++;
            }
            else if(nums[mid] == 1){
                mid++;
            }
            else{
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
        // while(mid <= high){
        //     if(nums[mid]==0){
        //         swap(nums[low],nums[mid]);
        //         low++;
        //         mid++;
        //     }
        //     else if(nums[mid]==1){
        //         mid++;
        //     }
        //     else{
        //         swap(nums[mid],nums[high]);
        //         high--;
        //     }
        // }
    }
};