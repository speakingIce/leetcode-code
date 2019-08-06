53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

给出一个数组，找出其中的元素和最大的连续子数组。
这道题可以使用divide and conquer来求解，这里使用DP求解。
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int maxEndingHere = nums[0], maxSoFar = nums[0];
        for(int i = 1; i < nums.size(); i++){
            maxEndingHere = max(maxEndingHere + nums[i], nums[i]);
            maxSoFar = max(maxSoFar, maxEndingHere);
        }
        return maxSoFar;
    }
};
