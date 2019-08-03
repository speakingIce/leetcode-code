53. Maximum Subarray

Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
Example:
Input: [-2,1,-3,4,-1,2,1,-5,4],
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
Follow up:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

给出一个数组，找出一个连续的子数组，该子数组的元素和是最大的。

O(n) solution:
从左到右地扫描数组，维护两个变量，maxEndingHere和maxSoFar；
假设当前已经扫描了的数组元素为nums[1-i]，则
maxEndingHere代表以nums[i]结尾的子数组中，最大的元素和的值；
maxSoFar代表当前已经发现的最大的元素和；
每一次扫描到了一个新元素，则进行更新:
maxEndingHere=max(maxEndingHere, nums[i);
maxSoFar=max(maxSoFar, maxEndingHere)。

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

Divide and conquer solution:
将当前数组从中间位置一分为二；
元素和最大的子数组有可能存在于三种位置：
1. 存在于左半部分
2. 存在于右半部分
3. 横跨左半部分和右半部分

class Solution {
private:
    int divideAndConquerMaxSubArray(vector<int>& nums, int l, int r){
        if(l - r + 1 == 1){
            return nums[l];
        }
        int mid = (l + r) / 2;
        // The max subarr exists in the left part
        int leftPartMax = divideAndConquerMaxSubArray(nums, l, mid);
        // The max subarr exists in the right part
        int rightPartMax = divideAndConquerMaxSubArray(nums, mid + 1, r);
        // Else
        int leftPartSumMax = 0, rightPartSumMax = 0;
        int leftPartSum = 0, rightPartSum = 0;
        
        for(int i = mid - 1; i >= l; i--){
            leftPartSum += nums[i];
            if(leftPartSum > leftPartSumMax) leftPartSumMax = leftPartSum;
        }
        for(int i = mid + 1; i <= r; i++){
            rightPartSum += nums[i];
            if(rightPartSum > rightPartSumMax) rightPartSumMax = rightPartSum;
        }
        int midPartMax = nums[mid] + leftPartSumMax + rightPartSumMax;
        
        return max(leftPartMax, max(rightPartMax, midPartMax));
        
    }
public:
    int maxSubArray(vector<int>& nums) {
        return divideAndConquerMaxSubArray(nums, 0, nums.size() - 1);
    }
};
