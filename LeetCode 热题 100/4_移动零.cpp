class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0, right = 0;
        while(right < nums.size()){
            if(nums[right]){
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
        // for(int i = 0; i < nums.size() - 1; i++){
        //     if(!nums[i]){
        //         int j = i + 1;
        //         while(1){
        //             if(!nums[j] && j != nums.size() - 1){
        //                 j++;
        //             }
        //             else{
        //                 break;
        //             }
        //         }
        //         swap(nums[i], nums[j]);
        //     }
        // }
    }
};