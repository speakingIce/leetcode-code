42. Trapping Rain Water
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
给出数组height[n]，其中的每一个元素代表台阶的高度，计算下雨后在台阶的坑洼里的积水量。

Brute force
class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size() == 0 || height.size() == 1
          || height.size() == 2) return 0;
        
        int totalAmountOfRain = 0;
        for(int i = 1; i < height.size() - 1; i++){
            int leftMaxLevel = 0;
            int rightMaxLevel = 0;
            for(int j = 0; j < i; j++){
                leftMaxLevel = max(leftMaxLevel, height[j]);
            }
            for(int j = i + 1; j < height.size(); j++){
                rightMaxLevel = max(rightMaxLevel, height[j]);
            }
            totalAmountOfRain += 
                max(0, min(leftMaxLevel, rightMaxLevel) - height[i]);
        }
        return totalAmountOfRain;
    }
};

Dynamic Programming
class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <= 2) return 0;
        vector<int> leftMaxLevels(height.size(), 0);
        vector<int> rightMaxLevels(height.size(), 0);
        leftMaxLevels[0] = height[0];
        for(int i = 1; i < height.size(); i++){
            leftMaxLevels[i] = max(height[i], leftMaxLevels[i - 1]);
        }
        rightMaxLevels[height.size()-1] = height[height.size() - 1];
        for(int i = height.size() - 2; i >= 0; i--){
            rightMaxLevels[i] = max(height[i], rightMaxLevels[i + 1]);
        }
        int totalAmountOfRain = 0;
        for(int i = 1; i < height.size() - 1; i++){
            totalAmountOfRain += max(0, 
                min(leftMaxLevels[i - 1], 
                    rightMaxLevels[i + 1]) - height[i]);
        }
        return totalAmountOfRain;
    }
};

stack
