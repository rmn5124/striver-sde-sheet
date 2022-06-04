//https://leetcode.com/problems/next-permutation/
//https://www.codingninjas.com/codestudio/problems/next-permutaion_893046?topList=striver-sde-sheet-problems&leftPanelTab=0

// Brute force will be find all the permutation and store it in array and print the next permutation by traversing in the array.
// One more approach will be call intbuilt next_permutation function in c++ stl library.
 Optimal approach
// According to Wikipedia, a man named Narayana Pandita presented the following simple algorithm to solve this problem in the 14th century.

// Find the largest index k such that nums[k] < nums[k + 1]. If no such index exists, just reverse nums and done.
// Find the largest index l > k such that nums[k] < nums[l].
// Swap nums[k] and nums[l].
// Reverse the sub-array nums[k + 1:].

 class Solution {
public:
    void nextPermutation(vector<int>& nums) {
    	int n = nums.size(), k, l;
    	for (k = n - 2; k >= 0; k--) {
            if (nums[k] < nums[k + 1]) {
                break;
            }
        }
    	if (k < 0) {
    	    reverse(nums.begin(), nums.end());
    	} else {
    	    for (l = n - 1; l > k; l--) {
                if (nums[l] > nums[k]) {
                    break;
                }
            } 
    	    swap(nums[k], nums[l]);
    	    reverse(nums.begin() + k + 1, nums.end());
        }
    }
}; 

// eg.
// 1.
// 1,2,3 k=3 break
// 1,2,3 k=1 break
// 1,3,2 k=1 swap
// 1,3,2 rev(k+1,end)
    
// 2.   
// 1,4,3,2,5  k=3
// 1,4,3,2,5  k=2 break
// 1,4,3,5,2 swap
// 1,4,3,2,5 reverse(k+1,end)

