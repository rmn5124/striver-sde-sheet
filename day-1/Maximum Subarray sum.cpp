//https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;// empty array
       long long ans=nums[0],i,j,sum=0;
        for(i=0;i<n;i++){
            sum+=nums[i];
            if(sum>=ans)
            ans=sum;
            if(sum<=0)
            sum=0;
        }
        return ans;
    }
};
