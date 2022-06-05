//https://leetcode.com/problems/find-the-duplicate-number/


/*here we will apply slow and fast pointer approach. Since there is a cycle because 
of the duplicate element then after making the cycle we will traverse the 
slow and fast simultaneously and at junction slow and fast will meet. 
since both will be same, hence we can return either slow or fast. */

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[nums[0]];
        while(slow!=fast){
            slow=nums[slow];
            fast=nums[nums[fast]];
        }
        slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
};
