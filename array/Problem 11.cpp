11. Container With Most Water

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Note: You may not slant the container and n is at least 2.

class Solution {
public:
    int maxArea(vector<int>& height) {
        int lb = 0, rb = height.size() - 1;
        int area = (rb - lb) * min(height[lb], height[rb]);
        while(lb < rb){
            if(height[lb] < height[rb])
                lb++;
            else
                rb--;
            area = max(area, (rb - lb) * min(height[lb], height[rb]));
        }
        return area;
    }
};
