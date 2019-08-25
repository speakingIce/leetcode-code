1140. Stone Game II

Alex and Lee continue their games with piles of stones.  There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].  The objective of the game is to end with the most stones. 
Alex and Lee take turns, with Alex starting first.  Initially, M = 1.
On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M.  Then, we set M = max(M, X).
The game continues until all the stones have been taken.
Assuming Alex and Lee play optimally, return the maximum number of stones Alex can get.
 
Example 1:
Input: piles = [2,7,9,4,4]
Output: 10
Explanation:  If Alex takes one pile at the beginning, Lee takes two piles, then Alex takes 2 piles again. Alex can get 2 + 4 + 4 = 10 piles in total. If Alex takes two piles at the beginning, then Lee can take all three piles left. In this case, Alex get 2 + 7 = 9 piles in total. So we return 10 since it's larger. 
 
Constraints:
1 <= piles.length <= 100
1 <= piles[i] <= 10 ^ 4

给定n堆石头，每一堆石头分别有piles[i]个石头，A和L轮流操作，A先行，无法操作的时候结束；
每次操作可以拿走剩下的石头堆中的前X堆石头，1<=X<=2M；
M最初为1，每次操作后更新M=max(M, X)；
A和L都想拿到尽可能多的石头，问A最多能拿到多少石头。

这道题使用DP的思想就可以求解：
设dp[i][M]代表玩家从第i堆石头开始操作，且当前的M值为M时，他最多能拿到的石头数量。
则有dp[i][M]=max(piles[i] + remainingSum[i + 1] - dp[i + 1][max(1, M)], 
                 piles[i]+piles[i+1] + remainingSum[i + 2] - dp[i + 2][max(2, M)],
                 ...,
                 piles[i]+piles[i+1]+...+piles[i+2M-1] + remainingSum[i + 2M] - dp [i + 2M][max(2M, M)])
 
class Solution {
private:
    int DP(int i, int M, int n, vector<int>& piles, vector<int>& sum, vector<vector<int> >& dp){
        if(i >= n) return 0;
        
        if(dp[i][M] != -1) return dp[i][M];
        
        if(i == n - 1){
            return dp[i][M] = piles[n - 1];
        }
        int currSum = 0;
        int maxValue = 0;
        for(int j = 1; j <= 2 * M && i + j - 1 <= n - 1; j++){
            currSum += piles[i + j - 1];
            maxValue = max(maxValue, currSum + sum[i + j] - DP(i + j, max(M, j), n, piles, sum, dp));
        }
        // cout << "i: " << i << " M: " << M <<" "<< maxValue << endl;
        return dp[i][M] = maxValue;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<int> sum(n + 1, 0);
        sum[n - 1] = piles[n - 1];
        for(int i = n - 2; i >= 0; i--){
            sum[i] = piles[i] + sum[i + 1];
        }
        vector<vector<int> > dp(n, vector<int>(2 * n + 1, -1));
        return DP(0, 1, n, piles, sum, dp);
    }
};
