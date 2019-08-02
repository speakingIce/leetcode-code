15. 3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
Note:
The solution set must not contain duplicate triplets.
Example:
Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]

给出一个数列，需要找出所有的三元组（不允许duplicate的存在），其中的三个元素之和为零。
我们先对数组进行由小到大排序，然后从左到右地枚举元素，将该元素当做三元组的第一个元素，则可知其他两个元素的和的值应该是多少；
我们在剩余的数组中使用两个指针lb和rb，用它们去找出适合的元素；
初始时lb在剩余数组的左边界，rb在右边界；
当num[lb]+num[rb]大于所需的值时，则rb--；小于时，lb++。

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int> > ans;
        
        if(nums.size() < 3) return ans;
        
        sort(nums.begin(), nums.end());
        
        int prev = nums[0] - 1;
        
        for(int i = 0; i < nums.size() - 2; i++){
            if(nums[i] == prev) continue;
            prev = nums[i];
            int lb = i + 1, rb = nums.size() - 1;
            while(lb < rb){
                if(nums[lb] + nums[rb] == 0 - nums[i]){
                    vector<int> tmp; 
                    tmp.push_back(nums[i]);tmp.push_back(nums[lb]);tmp.push_back(nums[rb]);
                    ans.push_back(tmp);
                    while(lb < rb && nums[lb + 1] + nums[rb] == 0 - nums[i]) lb++;
                    while(lb < rb && nums[lb] + nums[rb - 1] == 0 - nums[i]) rb--;
                    lb++, rb--;
                }else if(nums[lb] + nums[rb] > 0 - nums[i])
                    rb--;
                else
                    lb++;
            }
        }
        return ans;    
    }
};
