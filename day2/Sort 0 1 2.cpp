//https://leetcode.com/problems/sort-colors/

/*The idea is to sweep all 0s to the left and all 2s to the right, then all 1s are left in the middle.
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
       int zero=0,two=n-1;
       for(int i=0;i<=two;i++){
           while(i<two and nums[i]==2) swap(nums[i],nums[two--]);
           while(i>zero and nums[i]==0) swap(nums[i],nums[zero++]);
       }
    }
};
