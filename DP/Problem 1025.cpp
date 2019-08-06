1025. Divisor Game

Alice and Bob take turns playing a game, with Alice starting first.
Initially, there is a number N on the chalkboard.  On each player's turn, that player makes a move consisting of:
Choosing any x with 0 < x < N and N % x == 0.
Replacing the number N on the chalkboard with N - x.
Also, if a player cannot make a move, they lose the game.
Return True if and only if Alice wins the game, assuming both players play optimally.

给出一个正整数N，Alice和Bob轮流操作，Alice先操作。
操作为选择一个比它本身小的因子x，得到结果N-x；
谁无法进行操作则谁输掉比赛。

可以使用DP求解，设dp[n]代表Alice必然胜利或者失败。
如果存在因子x，使得dp[n-x]是必然失败的状态，则dp[n]是必然胜利的状态；否则dp[n]是必然失败的状态。
vector<int> dp(1001, -1);
class Solution {
public:
    bool divisorGame(int N) {
        if(dp[N] != -1) return dp[N];
        
        if(N == 1) return dp[N] = 0;
        
        for(int i = 1; i <= floor(sqrt(N)); i++){
            if((N / i) * i == N){
                if(!divisorGame(N - i)){
                    return dp[N] = 1;
                }
            }
        }
        return dp[N] = 0;
    }
};
