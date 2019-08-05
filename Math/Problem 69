69. Sqrt(x)

Implement int sqrt(int x).
Compute and return the square root of x, where x is guaranteed to be a non-negative integer.
Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
Example 1:
Input: 4
Output: 2
Example 2:
Input: 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since 
             the decimal part is truncated, 2 is returned.
             
将输入的int型整数开二次方根，且去除结果的小数部分。
使用二分法，初始下界为0，上界为INT_MAX，每次迭代的时候，比较mid和x/mid的大小，如果mid>x/mid，说明mid比所求的结果大；
当mid<=x/mid时，再讨论mid+1同x/(mid+1)的大小关系，即可确定mid是否为所求的值。

class Solution {
public:
    int mySqrt(int x) {
        // INT_MAX is the max integer in C++
        int lb = 0, rb = INT_MAX;
        int mid;
        while(lb <= rb){
            mid = (lb + rb) >> 1;
            
            if(mid == 0){
                if(x == 0) return 0;
                return -1;
            }
            
            if(mid > x / mid){
                rb = mid - 1;
            }
            else{
                if(mid + 1 > x / (mid + 1))
                    return mid;
                lb = mid + 1;
            }
        }
        // cout << lb << " " <<mid << " "<<rb<<' '<<"here\n";
        return -1;
    }
};
