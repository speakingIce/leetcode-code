633. Sum of Square Numbers
Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
Example 1:
Input: 5
Output: True
Explanation: 1 * 1 + 2 * 2 = 5
 
Example 2:
Input: 3
Output: False

给出一个int型非负整数，判断它是否为两个整数的平方之和。
假设输入的整数为c，方法是枚举从0到floor(sqrt(c))的所有整数；
设当前遍历到的整数为a，判断(c-square(a))是否为一个完全平方数。

class Solution {
private:
    bool judgePerfectSquare(int num){
        int sqrtInt = floor(sqrt(num));
        return sqrtInt * sqrtInt == num;
    }
public:
    bool judgeSquareSum(int c) {
        for(int a = 0; a <= floor(sqrt(c)); a++){
            int restPart = c - a * a;
            if(judgePerfectSquare(restPart)) return true;
        }
        return false;
    }
};

注意：补充一个可能有用的恒等式
1+3+...+(2n-1)=n^2
